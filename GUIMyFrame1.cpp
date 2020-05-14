#include "GUIMyFrame1.h"
#include<iostream>
#include <vector>

Vector operator* (const Matrix gMatrix, const Vector gVector) {
	unsigned int i, j;
	Vector tmp;
	for (i = 0; i < 3; i++) {
		tmp.data[i] = 0.0;
		for (j = 0; j < 3; j++) tmp.data[i] = tmp.data[i] + (gMatrix.data[i][j] * gVector.data[j]);
	}
	return tmp;
}
Matrix Set_Rotate(double alpha) {
	Matrix tmp;
	double dalpha = alpha * 3.14159265358979323846 / 180;
	tmp.data[0][0] = tmp.data[1][1] = cos(dalpha);
	tmp.data[1][0] = sin(dalpha);
	tmp.data[0][1] = -tmp.data[1][0];
	return tmp;
}

Matrix Set_Translation(double dx, double dy) {
	Matrix tmp;
	tmp.data[0][0] = tmp.data[1][1] = 1;
	tmp.data[0][2] = dx;
	tmp.data[1][2] = dy;
	return tmp;
}

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent),
	move_shape(false),
	reset(true),
	Btr_t(true),
	Btr_f(false),
	Mtr(),
	Str_t(true),
	Str_f(false),
	Squa(),
	Rhom(),
	ptr_moving_shape(nullptr),
	last_x(100000),
	last_y(100000)
{
	//, move_shape(false), Btr_t(BigTr(true)), BTr_f(BigTr(false)), Mtr(MediumTr()), Str_t(SmallTr(true)), Str_f(SmallTr(false)), Squa(Square()), Rhom(Rhomboid())
}

void GUIMyFrame1::panelOnKeyDown(wxKeyEvent& event)
{
	// TODO: Implement panelOnKeyDown
}


//part of panelOnMouseEvents
double f_lin(double a,double b,double x) {
	return a * x + b;
}

//part of panelOnMouseEvents

// algorithm explained here http://wazniak.mimuw.edu.pl/index.php?title=GKIW_Modu%C5%82_3_-_Podstawowe_operacje_rastrowe
bool GUIMyFrame1::is_in_this_shape(Shapes& shp,int sides, double x, double y) {
	bool p_good = true;// if point is not inside this shape p_good must turn to false
	double a, b;
	int j = 2;
	for (int i = 0; i < sides; i++) {
		if (j == sides + 1) j = 1;

		if (shp.d[i].GetX() != shp.d[i + 1].GetX()) {
			a = (shp.d[i].GetY() - shp.d[i + 1].GetY()) / (shp.d[i].GetX() - shp.d[i + 1].GetX());
			b = shp.d[i].GetY() - a * shp.d[i].GetX();

			if (f_lin(a, b, shp.d[j].GetX()) < shp.d[j].GetY()) {
				if (f_lin(a, b, x) > y)
					p_good = false;
			}
			else {
				if (f_lin(a, b, x) < y)
					p_good = false;
			}
		}
		else {
			if (shp.d[i].GetX() < shp.d[j].GetX()) {
				if (shp.d[i].GetX() > x)
					p_good = false;
			}
			else {
				if (shp.d[i].GetX() < x)
					p_good = false;
			}
		}
		j++;
	}
	if (p_good) {
		ptr_moving_shape = &shp;
	}
	return p_good;
}
//part of panelOnMouseEvents
bool GUIMyFrame1::if_catch_shape(double x, double y) {
	
	bool is_in_shape = true;
	// if point (x,y) is not inside any of all shapes = is_in_shape turn to false 
		if (! is_in_this_shape(Btr_t, 3, x, y))
			if (!is_in_this_shape(Btr_f, 3, x, y))
				if (!is_in_this_shape(Mtr, 3, x, y))
					if (!is_in_this_shape(Str_t, 3, x, y))
						if (!is_in_this_shape(Str_f, 3, x, y))
							if (!is_in_this_shape(Rhom, 4, x, y))
								if (!is_in_this_shape(Squa, 4, x, y))
									is_in_shape = false;
	
	if (is_in_shape) {
		panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
		return true;
	}
	else return false;
}

void GUIMyFrame1::panelOnMouseEvents(wxMouseEvent& event)
{

	//if just pushed LetfBotton, if caught shape, be ready to move it
	if (event.LeftDown()) if (if_catch_shape(event.GetX(), event.GetY())) move_shape = true;

	//if just released LetfBotton, stop moving shape, and drop it
	if (event.LeftUp()) {
		panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
		if (move_shape) {
			move_shape = false;
			ptr_moving_shape = nullptr;
			last_x = 100000;
			last_y = 100000;
			//drop_shape();
		}
	}
	
	//if mouse is moved and not left window move holding shape
	if (event.Dragging()) {
		if (move_shape) {
			if (!event.Leaving()) {
				wxClientDC dc1(panel);
				wxBufferedDC dc(&dc1);
				dc.Clear();
				if (last_x != 100000) {
					Matrix t = Set_Translation(event.GetX()-last_x, event.GetY()-last_y);
					for (auto &v : ptr_moving_shape->d)
						v = t * v;
					last_x = event.GetX();
					last_y = event.GetY();
				}
				else {
					last_x = event.GetX();
					last_y = event.GetY();
				}
				ptr_moving_shape->Draw(&dc);
				panel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DFACE));
			}
		}
	}
}

void GUIMyFrame1::panelOnUpdateUI(wxUpdateUIEvent& event)
{
		PaintShapes();
}

void GUIMyFrame1::checkOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement checkOnButtonClick
}

void GUIMyFrame1::randomOnButtonClick(wxCommandEvent& event)
{
	// TODO: Implement randomOnButtonClick
}

void GUIMyFrame1::PaintShapes() {
	wxClientDC dc1(panel);
	wxBufferedDC dc(&dc1);
	dc.Clear();
	Matrix t;
	dc.SetPen(wxPen(wxColor(0, 0, 0)));
	if (reset) {
		t = Set_Translation(5, 5);
		reset = false;
		for (auto &v : Btr_t.d)
			v = t * v;
		for (auto &v : Btr_f.d)
			v = t * v;
		for (auto &v : Mtr.d)
			v = t * v;
		for (auto &v : Str_t.d)
			v = t * v;
		for (auto &v : Str_f.d)
			v = t * v;
		for (auto &v : Squa.d)
			v = t * v;
		for (auto &v : Rhom.d)
			v = t * v;
	}

	Btr_t.Draw(&dc);
	Btr_f.Draw(&dc);
	Mtr.Draw(&dc);
	Str_t.Draw(&dc);
	Str_f.Draw(&dc);
	Squa.Draw(&dc);
	Rhom.Draw(&dc);

	dc.DrawLine(262, 0, 262, 620);
	dc.DrawLine(0, 262, 262, 262);
}