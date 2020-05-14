#include <cstdio>
#include <cmath>

class Vector{
 public:
	 double GetX() const;
	 double GetY() const;
	 Vector();
	 void Set(double d1,double d2);
	 double data[3];
};

class Matrix{
 public:
	Matrix();
	Matrix operator*(const Matrix);
	friend Vector operator*(const Matrix,const Vector);
	double data[3][3];
};

/*Vector::Vector(){
	data[0]=0.0; data[1]=0.0; data[2]=1.0;
}

void Vector::Set(double d1,double d2){
	data[0]=d1; data[1]=d2;
}

double Vector::GetX() const {
	return data[0];
}

double Vector::GetY() const {
	return data[1];
}

Matrix::Matrix(){
	data[0][0]=0.0; data[0][1]=0.0; data[0][2]=0.0;
	data[1][0]=0.0; data[1][1]=0.0; data[1][2]=0.0;
	data[2][0]=0.0; data[2][1]=0.0; data[2][2]=1.0;
}

Matrix Matrix::operator* (const Matrix gMatrix){
	int i,j,k;
	Matrix tmp;
	
	for (i=0;i<3;i++)
		for (j=0;j<3;j++){
			tmp.data[i][j]=0.0;
			for (k=0;k<3;k++)
				tmp.data[i][j]=tmp.data[i][j]+(data[i][k]*gMatrix.data[k][j]);
		}
 return tmp;
}

Vector operator* (const Matrix gMatrix,const Vector gVector){
	unsigned int i,j;
	Vector tmp;
	for (i=0;i<3;i++){
		tmp.data[i]=0.0;
		for (j=0;j<3;j++) tmp.data[i]=tmp.data[i]+(gMatrix.data[i][j]*gVector.data[j]);
	}
 return tmp;
}


Matrix Set_Rotate(double alpha){
	Matrix tmp;
	double dalpha = alpha * 3.14159265358979323846 / 180;
	tmp.data[0][0] = tmp.data[1][1] = cos(dalpha);
	tmp.data[1][0] = sin(dalpha);
	tmp.data[0][1] = -tmp.data[1][0];
	return tmp;
}

Matrix Set_Translation(double dx, double dy){
	Matrix tmp;
	tmp.data[0][0] = tmp.data[1][1] = 1;
	tmp.data[0][2] = dx;
	tmp.data[1][2] = dy;
	return tmp;
}*/

