#include "Shapes.h"

void Triangle::Draw(wxGraphicsContext *dc) {
	wxPoint2DDouble list[2];
	for (int i = 0; i < 3; i++) {
		dc->SetPen(wxPen(wxColor(0, 0, 0), 1, wxSOLID));
		list[0] = wxPoint2DDouble(d[i].GetX(), d[i].GetY());
		list[1] = wxPoint2DDouble(d[i + 1].GetX(), d[i + 1].GetY());
		dc->DrawLines(2, list);
	}
}

wxPoint Triangle::Center() const {
	wxPoint tmp;
	double xt = (d[1].GetX() + d[2].GetX()) / 2.;
	double yt = (d[1].GetY() + d[2].GetY()) / 2.;
	tmp.x = (d[0].GetX() + xt) / 2.;
	tmp.y = (d[0].GetY() + yt) / 2.;
	return tmp;
}

void Quadrangle::Draw(wxGraphicsContext *dc) {
	wxPoint2DDouble list[2];
	for (int i = 0; i < 4; i++) {
		dc->SetPen(wxPen(wxColor(0, 0, 0), 1, wxSOLID));
		list[0] = wxPoint2DDouble(d[i].GetX(), d[i].GetY());
		list[1] = wxPoint2DDouble(d[i + 1].GetX(), d[i + 1].GetY());
		dc->DrawLines(2, list);
	}
}

wxPoint Quadrangle::Center() const {
	wxPoint tmp;
	tmp.x = (d[0].GetX() + d[2].GetX()) / 2.;
	tmp.y = (d[0].GetY() + d[2].GetY()) / 2.;
	return tmp;
}

BigTr::BigTr(bool ver) : Triangle() {
	if (ver) v = true;
	else v = false;
	Reset();
}

void BigTr::Reset() {
	used = false;
	if (v) {
		d[0].Set(126, 126);
		d[1].Set(0, 0);
		d[2].Set(252, 0);
		d[3].Set(126, 126);
	}
	else {
		d[0].Set(126, 126);
		d[1].Set(0, 0);
		d[2].Set(0, 252);
		d[3].Set(126, 126);
	}
}

SmallTr::SmallTr(bool ver) : Triangle() {
	if (ver) v = true;
	else v = false;
	Reset();
}

void SmallTr::Reset() {
	used = false;
	if (v) {
		d[0].Set(63, 189);
		d[1].Set(0, 252);
		d[2].Set(126, 252);
		d[3].Set(63, 189);
	}
	else {
		d[0].Set(126, 126);
		d[1].Set(189, 189);
		d[2].Set(189, 63);
		d[3].Set(126, 126);
	}
}

MediumTr::MediumTr() : Triangle() {
	Reset();
}

void MediumTr::Reset() {
	used = false;
	d[0].Set(252, 252);
	d[1].Set(252, 126);
	d[2].Set(126, 252);
	d[3].Set(252, 252);
}

Square::Square() : Quadrangle() {
	Reset();
}

void Square::Reset() {
	used = false;
	d[0].Set(126, 126);
	d[1].Set(189, 189);
	d[2].Set(126, 252);
	d[3].Set(63, 189);
	d[4].Set(126, 126);
}

Rhomboid::Rhomboid() : Quadrangle() {
	Reset();
}

void Rhomboid::Reset() {
	used = false;
	d[0].Set(252, 0);
	d[1].Set(252, 126);
	d[2].Set(189, 189);
	d[3].Set(189, 63);
	d[4].Set(252, 0);
}
