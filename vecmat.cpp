#include "vecmat.h"

Vector::Vector() {
	data[0] = 0.0; data[1] = 0.0; data[2] = 1.0;
}

void Vector::Set(double d1, double d2) {
	data[0] = d1; data[1] = d2;
}

double Vector::GetX() const {
	return data[0];
}

double Vector::GetY() const {
	return data[1];
}

Matrix::Matrix() {
	data[0][0] = 0.0; data[0][1] = 0.0; data[0][2] = 0.0;
	data[1][0] = 0.0; data[1][1] = 0.0; data[1][2] = 0.0;
	data[2][0] = 0.0; data[2][1] = 0.0; data[2][2] = 1.0;
}

Matrix Matrix::operator* (const Matrix gMatrix) {
	int i, j, k;
	Matrix tmp;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++) {
			tmp.data[i][j] = 0.0;
			for (k = 0; k < 3; k++)
				tmp.data[i][j] = tmp.data[i][j] + (data[i][k] * gMatrix.data[k][j]);
		}
	return tmp;
}

