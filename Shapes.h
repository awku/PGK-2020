#pragma once
#include "vecmat.h"
#include <wx/graphics.h>

class Shapes {
public:
	Shapes() {}
	virtual ~Shapes() {}
	virtual void Draw(wxGraphicsContext *dc) = 0;
	virtual void Reset() = 0;
	virtual Vector Center() const = 0;
	bool moving, close, used;
	int len;
	Vector d[5];
};

class Triangle : public Shapes {
public:
	Triangle();
	virtual ~Triangle() {}
	void Draw(wxGraphicsContext *dc) override;
	virtual void Reset() = 0;
	Vector Center() const override;
};

class Quadrangle : public Shapes {
public:
	Quadrangle();
	virtual ~Quadrangle() {}
	void Draw(wxGraphicsContext *dc) override;
	virtual void Reset() = 0;
	Vector Center() const override;
};

class BigTr : public Triangle {
public:
	BigTr(bool ver);
	void Reset() override;
	bool v;
};

class SmallTr : public Triangle {
public:
	SmallTr(bool ver);
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