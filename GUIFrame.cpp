#include "GUIFrame.h"
#include <iostream>
#include <vector>
#include <wx/file.h>
#include <string>
#include <ctime>
#include "Figures.h"
#include <wx/msgdlg.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <algorithm>

GUIFrame::GUIFrame(wxWindow* parent)
	:
	Frame(parent),
	move_shape(false),
	reset(true),
	ctrl(false),
	last_x(-1),
	last_y(-1),
	fig(rand() % 6) {
	shapes.emplace_back(new BigTr(true));
	shapes.emplace_back(new BigTr(false));
	shapes.emplace_back(new MediumTr());
	shapes.emplace_back(new SmallTr(true));
	shapes.emplace_back(new SmallTr(false));
	shapes.emplace_back(new Square());
	shapes.emplace_back(new Rhomboid());
}

GUIFrame::~GUIFrame() {
	for (auto p : shapes)
		delete p;

	shapes.clear();
}

void GUIFrame::panelOnKeyDown(wxKeyEvent& event)
{
	if (event.GetEventType() == wxEVT_KEY_DOWN && event.GetKeyCode() == WXK_CONTROL && !ctrl)
		ctrl = true;
	if (event.GetEventType() == wxEVT_KEY_UP && ctrl)
		ctrl = false;
}

double f_lin(double a, double b, double x) {
	return a * x + b;
}

bool GUIFrame::is_in_this_shape(Shapes& shp, int sides, double x, double y, bool m = false, bool ver = false) {
	bool p_good = true;
	double a, b;
	int j = 2;
	for (int i = 0; i < sides; i++) {
		if (j == sides + 1) j = 1;

		if (shp.d[i].GetX() != shp.d[i + 1].GetX()) {
			a = (shp.d[i].GetY() - shp.d[i + 1].GetY()) / (shp.d[i].GetX() - shp.d[i + 1].GetX());
			b = shp.d[i].GetY() - a * shp.d[i].GetX();

			if (f_lin(a, b, shp.d[j].GetX()) < shp.d[j].GetY()) {
				if (m && f_lin(a, b, x) >= y)
					p_good = false;
				else if (!m && f_lin(a, b, x) > y)
					p_good = false;
			}
			else {
				if (m && f_lin(a, b, x) <= y)
					p_good = false;
				else if (!m && f_lin(a, b, x) < y)
					p_good = false;
			}
		}
		else {
			if (shp.d[i].GetX() < shp.d[j].GetX()) {
				if (m && shp.d[i].GetX() >= x)
					p_good = false;
				else if (!m && shp.d[i].GetX() > x)
					p_good = false;
			}
			else {
				if (m && shp.d[i].GetX() <= x)
					p_good = false;
				else if (!m && shp.d[i].GetX() < x)
					p_good = false;
			}
		}
		j++;
	}

	if (!m) {
		if (!ver) {
			if (p_good) {
				if (!ctrl) {
					for (auto& n : ptr_moving_shape)
						n->moving = false;
					ptr_moving_shape.clear();
					ptr_moving_shape.push_back(&shp);
					shp.moving = true;
					shp.used = true;
				}
				else {
					if (!shp.moving) {
						ptr_moving_shape.push_back(&shp);
						shp.moving = true;
						shp.used = true;
					}
				}
			}
		}

		if (ver) {
			if (p_good)
				if (!shp.close)
					ptr_close_shape.push_back(&shp);
		}
	}
	return p_good;
}


bool GUIFrame::if_catch_shape(double x, double y) {
	bool is_in_shape = true;

	int i = 6;
	bool T = true;
	while (T) {
		if (i < 0) {
			T = false;
			is_in_shape = false;
		}
		else {
			if (is_in_this_shape(*shapes[i], shapes[i]->len, x, y))
				T = false;
		}
		i--;
	}

	if (is_in_shape) {
		panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
		return true;
	}
	else return false;
}

void get_points_between(Vector a, Vector b, Vector res[5]) {
	Vector t1, t2, t3, t4, t5;
	t1.Set(a.GetX(), a.GetY());
	t3.Set((a.GetX() + b.GetX()) / 2., (a.GetY() + b.GetY()) / 2.);
	t2.Set((a.GetX() + t3.GetX()) / 2., (a.GetY() + t3.GetY()) / 2.);
	t4.Set((b.GetX() + t3.GetX()) / 2., (b.GetY() + t3.GetY()) / 2.);
	t5.Set(b.GetX(), b.GetY());
	res[0] = t1;
	res[1] = t2;
	res[2] = t3;
	res[3] = t4;
	res[4] = t5;
}

bool is_aligned(Vector a, Vector b, Vector c, Vector d, double& temp) {
	double temp1 = (a.GetY() - b.GetY()) / (a.GetX() - b.GetX());
	double temp2 = (c.GetY() - d.GetY()) / (c.GetX() - d.GetX());
	temp = (temp1 + temp2) / 2.;
	if (fabs(temp1 - temp2) < 0.5)
		return true;
	else return false;
}


void GUIFrame::panelOnMouseEvents(wxMouseEvent& event)
{
	if (event.LeftDown()) {
		if (if_catch_shape(event.GetX(), event.GetY())) {
			move_shape = true;
			last_x = event.GetX();
			last_y = event.GetY();

			auto it1 = std::find(shapes.begin(), shapes.end(), ptr_moving_shape[ptr_moving_shape.size() - 1]);
			std::size_t i_old = distance(shapes.begin(), it1);
			std::size_t i_new = 6;

			if (i_old != i_new)
				while (i_old < i_new) {
					std::swap(shapes[i_old], shapes[i_old + 1]);
					++i_old;
				}
		}
	}

	if (event.LeftUp()) {
		panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
		if (move_shape) {
			for (auto m : ptr_moving_shape) {
				int sides = m->len;
				for (auto n : shapes)
					if (!n->moving && n->used) {
						for (int k = 0; k < sides; k++) {
							Vector points[5];
							get_points_between(m->d[k], m->d[k + 1], points);
							for (int l = 0; l < 5; l++)
								for (int i = -1; i <= 1; i++)
									for (int j = -1; j <= 1; j++)
										is_in_this_shape(*n, n->len, points[l].GetX() + i * 20, points[l].GetY() + j * 20, false, true);
						}
					}

				if (ptr_close_shape.size() != 0) {
					double xw, yw, xmin = 1000, ymin = 10000, a, b1, b2;
					Vector pm[5], pc[5];
					for (auto n : ptr_close_shape) {
						int s = n->len;
						for (int j = 0; j < sides; j++) {
							get_points_between(m->d[j], m->d[j + 1], pm);
							for (int i = 0; i < s; i++) {
								get_points_between(n->d[i], n->d[i + 1], pc);
								if (is_aligned(m->d[j], m->d[j + 1], n->d[i], n->d[i + 1], a)) {
									b1 = m->d[j].GetY() - a * m->d[j].GetX();
									b2 = n->d[i].GetY() - a * n->d[i].GetX();
									yw = b2 - b1;
									xw = n->d[i].GetX() - m->d[j].GetX();
									if (fabs(yw) < fabs(ymin))
										ymin = yw;
									if (fabs(xw) < fabs(xmin))
										xmin = xw;
								}
								for (int m = 0; m < 5; m++)
									for (int l = 0; l < 5; l++) {
										xw = pc[m].GetX() - pm[l].GetX();
										yw = pc[m].GetY() - pm[l].GetY();
										if (fabs(yw) < fabs(ymin))
											ymin = yw;
										if (fabs(xw) < fabs(xmin))
											xmin = xw;
									}
							}
						}
						if (m->Center().GetX() > n->Center().GetX())
							xmin = -fabs(xmin);
						else xmin = fabs(xmin);

						if (m->Center().GetY() > n->Center().GetY())
							ymin = -fabs(ymin);
						else ymin = fabs(ymin);

						n->close = false;
					}
					if (fabs(xmin) > 20)
						xmin = 0;
					if (fabs(ymin) > 20)
						ymin = 0;

					Matrix t = Set_Translation(xmin, ymin);
					for (auto &v : m->d)
						v = t * v;
					ptr_close_shape.clear();
				}
			}
			wxSize size = panel->GetVirtualSize();

			for (auto n : ptr_moving_shape)
				if (n->Center().GetX() > size.GetWidth() || n->Center().GetY() > size.GetHeight() || n->Center().GetY() < 0 || n->Center().GetX() < 0) {
					n->Reset();
					Matrix t = Set_Translation(5, 5);
					for (auto& v : n->d)
						v = t * v;
				}


			if (last_x > 0 && last_x < 262) {
				for (auto n : ptr_moving_shape)
					n->Reset();
				Matrix t = Set_Translation(5, 5);
				for (auto n : ptr_moving_shape)
					for (auto& v : n->d)
						v = t * v;
			}

			for (auto n : shapes)
				if (!n->moving && n->used) {
					for (auto m : ptr_moving_shape) {
						int s = n->len, sides = m->len;
						Vector p[5];
						for (int j = 0; j < sides; j++) {
							get_points_between(m->d[j], m->d[j + 1], p);
							for (int i = 0; i < 5; i++)
								if (is_in_this_shape(*n, n->len, p[i].GetX(), p[i].GetY(), 1)) {
									m->Reset();
									Matrix t = Set_Translation(5, 5);
									for (auto& v : m->d)
										v = t * v;
								}
						}
					}
				}

			if (!ctrl) {
				move_shape = false;
				for (auto n : ptr_moving_shape)
					n->moving = false;
				ptr_moving_shape.clear();
			}
			last_x = -1;
			last_y = -1;
		}

	}

	if (event.Dragging()) {
		if (move_shape) {
			if (!event.Leaving()) {
				wxClientDC dc1(panel);
				wxBufferedDC dc(&dc1);
				Matrix t = Set_Translation(event.GetX() - last_x, event.GetY() - last_y);
				for (auto n : ptr_moving_shape)
					for (auto& v : n->d)
						v = t * v;
				last_x = event.GetX();
				last_y = event.GetY();

				wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
				if (gc)
					for (auto n : ptr_moving_shape)
						n->Draw(gc);
				delete gc;
				panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));
			}
		}
	}
	if (event.GetWheelRotation() != 0) {
		if (move_shape) {
			wxClientDC dc1(panel);
			wxBufferedDC dc(&dc1);
			Matrix t = Set_Translation(last_x, last_y) * Set_Rotate(event.GetWheelRotation() / 8) * Set_Translation(-last_x, -last_y);
			for (auto n : ptr_moving_shape)
				for (auto& v : n->d)
					v = t * v;
			wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
			if (gc)
				for (auto n : ptr_moving_shape)
					n->Draw(gc);
			delete gc;
		}
	}
	if (event.RightUp()) {
		if (move_shape) {
			wxClientDC dc1(panel);
			wxBufferedDC dc(&dc1);
			Matrix t;
			for (auto n : ptr_moving_shape) {
				if (n->len == 3)
					t = Set_Translation(n->Center().GetX(), n->Center().GetY()) * Set_FlipT() * Set_Translation(-n->Center().GetX(), -n->Center().GetY());
				else
					t = Set_Translation(n->Center().GetX(), n->Center().GetY()) * Set_FlipQ() * Set_Translation(-n->Center().GetX(), -n->Center().GetY());
				for (auto& v : n->d)
					v = t * v;
			}
			wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
			if (gc)
				for (auto n : ptr_moving_shape)
					n->Draw(gc);
			delete gc;
		}
	}
}

void GUIFrame::panelOnUpdateUI(wxUpdateUIEvent& event)
{
	PaintShapes();
}

bool compare::operator()(const Vector& a, const Vector& b) const {
	Vector temp(0., 0.);
	double ta = GetDistance(temp, a);
	double tb = GetDistance(temp, b);
	if (ta != tb)
		return ta > tb;
	else {
		if (a.GetX() != b.GetX())
			return a.GetX() > b.GetX();
		else return a.GetY() > b.GetY();
	}
}


bool is_right(std::vector<Vector> d, std::vector<Vector> c) {
	std::sort(d.begin(), d.end(), compare());
	std::sort(c.begin(), c.end(), compare());

	for (unsigned int i = 0; i < d.size(); i++)
		for (unsigned int j = i + 1; j < d.size(); j++)
			if (GetDistance(d[i], d[j]) < 5)
				d[i].Set(3010, 3010);

	for (unsigned int i = 0; i < c.size(); i++)
		for (unsigned int j = i + 1; j < c.size(); j++)
			if (GetDistance(c[i], c[j]) < 5)
				c[i].Set(3010, 3010);

	c.erase(std::remove_if(c.begin(), c.end(), [](auto &a) {return (a.GetX() > 3000 || a.GetY() > 3000);}), c.end());

	d.erase(std::remove_if(d.begin(), d.end(), [](auto &a) {return (a.GetX() > 3000 || a.GetY() > 3000);}), d.end());

	if (d.size() != c.size() || d.size() == 0 || c.size() == 0)
		return false;
	else {
		double te = GetDistance(d[0], c[0]);
		bool spr = false;
		for (unsigned int i = 0; i < d.size(); i++) {
			spr = false;
			for (unsigned int j = 0; j < c.size(); j++)
				if (fabs(GetDistance(d[i], c[j]) - te) < 10) {
					spr = true;
					d[i].Set(3010, 3010);
					c[j].Set(3010, 3010);
					break;
				}
			if (!spr)
				return false;
		}

		return true;
	}
}


void GUIFrame::checkOnButtonClick(wxCommandEvent& event)
{
	bool error = false;

	for (auto n : shapes)
		if (!n->used) {
			wxMessageDialog messagedialog(this, "Nie wszystkie elementy zostały wyłożone", "Błędnie ułożone");
			messagedialog.ShowModal();
			error = true;
			break;
		}

	if (!error) {
		std::vector <Vector> checked;
		for (auto n : shapes)
			for (int i = 0; i < n->len; i++)
				checked.push_back(n->d[i]);

		error = is_right(data, checked);

		if (error) {
			wxMessageDialog messagedialog(this, "Gratulacje!", "!!!!");
			messagedialog.ShowModal();
		}
		else {
			wxMessageDialog messagedialog(this, "Prawdopodbnie źle ułożono", "Błędnie ułożone");
			messagedialog.ShowModal();
		}
	}
}

void GUIFrame::randomOnButtonClick(wxCommandEvent& event)
{
	for (auto n : shapes)
		n->Reset();
	reset = true;
	int temp = fig;
	srand(time(nullptr));
	while (temp == fig)
		temp = rand() % 6;
	fig = temp;
	PaintShapes();
}

void GUIFrame::PaintShapes() {
	wxClientDC dc1(panel);
	wxBufferedDC dc(&dc1);
	dc.Clear();
	Matrix t;
	if (reset) {
		t = Set_Translation(5, 5);
		reset = false;
		for (auto n : shapes)
			for (auto& v : n->d)
				v = t * v;
	}

	wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
	if (gc) {

		wxPoint2DDouble list[2];
		gc->SetPen(wxPen(wxColor(0, 0, 0), 1, wxSOLID));

		list[0] = wxPoint2DDouble(262, 0);
		list[1] = wxPoint2DDouble(262, 620);
		gc->DrawLines(2, list);

		list[0] = wxPoint2DDouble(0, 262);
		list[1] = wxPoint2DDouble(262, 262);
		gc->DrawLines(2, list);

		switch (fig) {
		case 0:
			boat(data, gc);
			break;
		case 1:
			swan(data, gc);
			break;
		case 2:
			horse(data, gc);
			break;
		case 3:
			house(data, gc);
			break;
		case 4:
			human(data, gc);
			break;
		case 5:
			fish(data, gc);
			break;
		}

		for (auto n : shapes)
			n->Draw(gc);
	}
	delete gc;
}