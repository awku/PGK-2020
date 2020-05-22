#include "Shapes.h"

void Triangle::Draw(wxBufferedDC *dc)const {
	Vector start, end;
	for (int i = 0; i < 3; i++) {
		start.Set(d[i].GetX(), d[i].GetY());
		end.Set(d[i + 1].GetX(), d[i + 1].GetY());
		dc->DrawLine(start.GetX(), start.GetY(), end.GetX(), end.GetY());
	}
}

void Quadrangle::Draw(wxBufferedDC *dc)const {
	Vector start, end;

	for (int i = 0; i < 4; i++) {
		start.Set(d[i].GetX(), d[i].GetY());
		end.Set(d[i + 1].GetX(), d[i + 1].GetY());
		dc->DrawLine(start.GetX(), start.GetY(), end.GetX(), end.GetY());
	}
}

BigTr::BigTr(bool ver) : Triangle() {
	if (ver) v = true;
	else v = false;
	Reset();
}

void BigTr::Reset() {
	if (v) {
		d[0].Set(0, 0);
		d[1].Set(252, 0);
		d[2].Set(126, 126);
		d[3].Set(0, 0);
	}
	else {
		d[0].Set(0, 0);
		d[1].Set(0, 252);
		d[2].Set(126, 126);
		d[3].Set(0, 0);
	}
}

SmallTr::SmallTr(bool ver) : Triangle() {
	if (ver) v = true;
	else v = false;
	Reset();
}

void SmallTr::Reset() {
	if (v) {
		d[0].Set(0, 252);
		d[1].Set(126, 252);
		d[2].Set(63, 189);
		d[3].Set(0, 252);
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
	d[0].Set(126, 252);
	d[1].Set(252, 252);
	d[2].Set(252, 126);
	d[3].Set(126, 252);
}

Square::Square() : Quadrangle() {
	Reset();
}

void Square::Reset() {
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
	d[0].Set(252, 0);
	d[1].Set(252, 126);
	d[2].Set(189, 189);
	d[3].Set(189, 63);
	d[4].Set(252, 0);
}
