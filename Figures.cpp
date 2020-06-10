#include "Figures.h"

wxPoint2DDouble convert(Vector &a) {
	wxPoint2DDouble tmp(a.GetX(), a.GetY());
	return tmp;
}

void drawpolygon(std::vector<Vector> dat, wxGraphicsContext *gc) {
	wxPoint2DDouble list[5];
	gc->SetPen(wxPen(wxColor(0, 0, 0), 2, wxSOLID));
	gc->SetBrush(wxBrush(wxColor(0, 0, 0), wxSOLID));
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 3;j++)
			list[j] = convert(dat[i * 3 + j]);
		list[3] = convert(dat[i * 3]);
		gc->DrawLines(4, list);
	}
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++)
			list[j] = convert(dat[15 + i * 4 + j]);
		list[4] = convert(dat[15 + i * 4]);
		gc->DrawLines(5, list);
	}
}

void fish(std::vector<Vector> &data, wxGraphicsContext *dc) {
	data.clear();
	double x, y, xmin = 900, xmax = 0, ymin = 900, ymax = 0;
	std::ifstream in("fish.dat");
	if (in.is_open()) {
		data.clear();
		while (!in.eof()) {
			in >> x >> y;
			if (x > xmax) xmax = x;
			if (x < xmin) xmin = x;
			if (y > ymax) ymax = y;
			if (y < ymin) ymin = y;
			data.push_back(Vector(x, y));
		}
		in.close();
	}
	std::vector <Vector> tem;
	double temp = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	Matrix t = Set_ScaleFigure(temp)*Set_Translation(10. - xmin, 400);
	for (auto&n : data)
		tem.emplace_back(n);

	for (auto&n : tem)
		n = t * n;

	drawpolygon(tem, dc);
}

void swan(std::vector<Vector> &data, wxGraphicsContext *dc) {
	data.clear();
	double x, y, xmin = 900, xmax = 0, ymin = 900, ymax = 0;
	std::ifstream in("swan.dat");
	if (in.is_open()) {
		data.clear();
		while (!in.eof()) {
			in >> x >> y;
			if (x > xmax) xmax = x;
			if (x < xmin) xmin = x;
			if (y > ymax) ymax = y;
			if (y < ymin) ymin = y;
			data.push_back(Vector(x, y));
		}
		in.close();
	}
	std::vector <Vector> tem;
	double temp = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	Matrix t = Set_ScaleFigure(temp)*Set_Translation(10. - xmin, 400);
	for (auto&n : data)
		tem.emplace_back(n);

	for (auto&n : tem)
		n = t * n;

	drawpolygon(tem, dc);
}

void horse(std::vector<Vector> &data, wxGraphicsContext *dc) {
	data.clear();
	double x, y, xmin = 900, xmax = 0, ymin = 900, ymax = 0;
	std::ifstream in("horse.dat");
	if (in.is_open()) {
		data.clear();
		while (!in.eof()) {
			in >> x >> y;
			if (x > xmax) xmax = x;
			if (x < xmin) xmin = x;
			if (y > ymax) ymax = y;
			if (y < ymin) ymin = y;
			data.push_back(Vector(x, y));
		}
		in.close();
	}
	std::vector <Vector> tem;
	double temp = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	Matrix t = Set_ScaleFigure(temp)*Set_Translation(10. - xmin, 600);
	for (auto&n : data)
		tem.emplace_back(n);

	for (auto&n : tem)
		n = t * n;

	drawpolygon(tem, dc);
}

void human(std::vector<Vector> &data, wxGraphicsContext *dc) {
	data.clear();
	double x, y, xmin = 900, xmax = 0, ymin = 900, ymax = 0;
	std::ifstream in("human.dat");
	if (in.is_open()) {
		data.clear();
		while (!in.eof()) {
			in >> x >> y;
			if (x > xmax) xmax = x;
			if (x < xmin) xmin = x;
			if (y > ymax) ymax = y;
			if (y < ymin) ymin = y;
			data.push_back(Vector(x, y));
		}
		in.close();
	}
	std::vector <Vector> tem;
	double temp = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	Matrix t = Set_ScaleFigure(temp)*Set_Translation(10. - xmin, 500);
	for (auto&n : data)
		tem.emplace_back(n);

	for (auto&n : tem)
		n = t * n;

	drawpolygon(tem, dc);
}

void house(std::vector<Vector> &data, wxGraphicsContext *dc) {
	data.clear();
	double x, y, xmin = 900, xmax = 0, ymin = 900, ymax = 0;
	std::ifstream in("house.dat");
	if (in.is_open()) {
		data.clear();
		while (!in.eof()) {
			in >> x >> y;
			if (x > xmax) xmax = x;
			if (x < xmin) xmin = x;
			if (y > ymax) ymax = y;
			if (y < ymin) ymin = y;
			data.push_back(Vector(x, y));
		}
		in.close();
	}
	std::vector <Vector> tem;
	double temp = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	Matrix t = Set_ScaleFigure(temp)*Set_Translation(10. - xmin, 300);
	for (auto&n : data)
		tem.emplace_back(n);

	for (auto&n : tem)
		n = t * n;

	drawpolygon(tem, dc);
}

void boat(std::vector<Vector> &data, wxGraphicsContext *dc) {
	data.clear();
	double x, y, xmin = 900, xmax = 0, ymin = 900, ymax = 0;
	std::ifstream in("boat.dat");
	if (in.is_open()) {
		data.clear();
		while (!in.eof()) {
			in >> x >> y;
			if (x > xmax) xmax = x;
			if (x < xmin) xmin = x;
			if (y > ymax) ymax = y;
			if (y < ymin) ymin = y;
			data.push_back(Vector(x, y));
		}
		in.close();
	}
	std::vector <Vector> tem;
	double temp = (xmax - xmin) > (ymax - ymin) ? (xmax - xmin) : (ymax - ymin);
	Matrix t = Set_ScaleFigure(temp)*Set_Translation(10. - xmin, 400);
	for (auto&n : data)
		tem.emplace_back(n);

	for (auto&n : tem)
		n = t * n;

	drawpolygon(tem, dc);
}
