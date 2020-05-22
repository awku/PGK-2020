#pragma once
#include "vecmat.h"
#include <wx/graphics.h>

class Shapes {
public:
	Shapes(){}
	virtual void Draw(wxGraphicsContext *dc) = 0; // draw figure only there there it is
	virtual void Reset() = 0;
	Vector d[5]; // for triangles last part unused 
	bool moving = false;
	bool close = false;
	bool used = false;
	virtual wxPoint Center() const = 0;
};

class Triangle : public Shapes {
public:
	Triangle() {}
	void Draw(wxGraphicsContext *dc) override;
	virtual void Reset() = 0;
	wxPoint Center() const override;
};

class Quadrangle : public Shapes {
public:
	Quadrangle() {}
	void Draw(wxGraphicsContext *dc) override;
	virtual void Reset() = 0;
	wxPoint Center() const override;
};

class BigTr : public Triangle {
public:
	BigTr(bool);
	void Reset() override;
	bool v;
};

class SmallTr : public Triangle {
public:
	SmallTr(bool);
	void Reset() override;
	bool v;
};

class MediumTr : public Triangle {
public:
	MediumTr();
	void Reset() override;
};

class Square : public Quadrangle {
public:
	Square();
	void Reset() override;
};

class Rhomboid : public Quadrangle {
public:
	Rhomboid();
	void Reset() override;
};
