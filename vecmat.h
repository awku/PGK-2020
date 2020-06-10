#include <cstdio>
#include <cmath>

class Vector{
 public:
	 Vector(double a = 0., double b = 0.);
	 double GetX() const;
	 double GetY() const;
	 void Set(double d1,double d2);
	 bool operator==(const Vector &v) const;
	 double data[3];
};

class Matrix{
 public:
	Matrix();
	Matrix operator*(const Matrix gMatrix);
	friend Vector operator*(const Matrix gMatrix,const Vector gVector);
	double data[3][3];
};

Matrix Set_Rotate(double x);
Matrix Set_Translation(double x, double y);
Matrix Set_FlipQ();
Matrix Set_FlipT();
Matrix Set_ScaleFigure(double x);

double GetDistance(const Vector &a, const Vector &b);