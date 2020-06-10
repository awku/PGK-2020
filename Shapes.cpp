#include "Shapes.h"

Triangle::Triangle(){
	len = 3; 
	moving = false;
	close = false;
	used = false;
}

void Triangle::Draw(wxGraphicsContext *dc) {
	wxPoint2DDouble list[4];
	dc->SetBrush(wxBrush(wxColor(177, 177, 177), wxSOLID));
	dc->SetPen(wxPen(wxColor(125, 125, 125), 1, wxSOLID));

	for (int i = 0; i < 4; i++)
		list[i] = wxPoint2DDouble(d[i].GetX(), d[i].GetY());

	dc->DrawLines(4, list);
}

Vector Triangle::Center() const {
	Vector tmp;
	double xt = (d[1].GetX() + d[2].GetX()) / 2.;
	double yt = (d[1].GetY() + d[2].GetY()) / 2.;
	tmp.Set((d[0].GetX() + xt) / 2., (d[0].GetY() + yt) / 2.);
	return tmp;
}

Quadrangle::Quadrangle() {
	len = 4;
	moving = false;
	close = false;
	used = false;
}

void Quadrangle::Draw(wxGraphicsContext *dc) {
	wxPoint2DDouble list[5];
	dc->SetBrush(wxBrush(wxColor(177, 177, 177), wxSOLID));
	dc->SetPen(wxPen(wxColor(125, 125, 125), 1, wxSOLID));

	for (int i = 0; i < 5; i++)
		list[i] = wxPoint2DDouble(d[i].GetX(), d[i].GetY());

	dc->DrawLines(5, list);
}

Vector Quadrangle::Center() const {
	Vector tmp;
	tmp.Set((d[0].GetX() + d[2].GetX()) / 2., (d[0].GetY() + d[2].GetY()) / 2.);
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