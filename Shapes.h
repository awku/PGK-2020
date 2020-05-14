#pragma once
#include "vecmat.h"
#include <wx/dcbuffer.h>

class Shapes {
public:
	Shapes(){}
	virtual void Draw(wxBufferedDC *dc)const = 0; // draw figure only there there it is
	virtual void Reset() = 0;
	Vector d[5]; // for triangles last part unused 
};

class Triangle : public Shapes {
public:
	Triangle() {}
	void Draw(wxBufferedDC *dc)const override;
	virtual void Reset() {}
};

class Quadrangle : public Shapes {
public:
	Quadrangle() {}
	void Draw(wxBufferedDC *dc)const override;
	virtual void Reset() {}
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