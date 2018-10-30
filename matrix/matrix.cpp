#include "matrix.h"



matrix::matrix()
{
	this->i = 0;
	this->j = 0;
	this->arr = nullptr;
}

matrix::matrix(int i, int j, int number)
{
	if (i < 0 || j < 0) return;
	this->i = i;
	this->j = j;
	this->arr = new int*[this->i];
	for (size_t n = 0; n < this->i; n++)
	{
		this->arr[n] = new int[this->j];
		for (size_t k = 0; k < this->j; k++)
		{
			this->arr[n][k] = number;
		}
	}
}

matrix::matrix(const matrix & obj)
{
	if (obj.i == 0 || obj.j == 0) {
		this->i = 0, this->j = 0;
		this->arr = nullptr;
		return;
	};
	this->i = obj.i;
	this->j = obj.j;
	this->arr = new int*[this->i];
	for (size_t n = 0; n < this->i; n++)
	{
		this->arr[n] = new int[this->j];
		for (size_t k = 0; k < this->j; k++)
		{
			this->arr[n][k] = obj.arr[n][k];
		}
	}
}

matrix & matrix::operator=(const matrix & obj)
{
	if (this == &obj) return *this;
	if (this->i == obj.i && this->j == obj.j) {
		for (size_t n = 0; n < this->i; n++)
		{
			for (size_t m = 0; m < this->j; m++)
			{
				this->arr[n][m] = obj.arr[n][m];
			}
		}
		return *this;
	}
	this->~matrix();
	if (obj.i == 0 || obj.j == 0) {
		this->i = 0, this->j = 0;
		this->arr = nullptr;
		return *this;
	};
	this->i = obj.i;
	this->j = obj.j;
	this->arr = new int*[this->i];
	for (size_t n = 0; n < this->i; n++)
	{
		this->arr[n] = new int[this->j];
		for (size_t k = 0; k < this->j; k++)
		{
			this->arr[n][k] = obj.arr[n][k];
		}
	}
	return *this;
}

matrix::matrix(matrix && obj)
{
	this->i = obj.i;
	this->j = obj.j;
	this->arr = obj.arr;
	obj.arr = nullptr;
	obj.i = 0;
	obj.j = 0;
}

matrix & matrix::operator=(matrix && obj)
{
	this->~matrix();
	this->i = obj.i;
	this->j = obj.j;
	this->arr = obj.arr;
	obj.arr = nullptr;
	obj.i = 0;
	obj.j = 0;
	return *this;
}

void matrix::print() const
{
	if (this->arr == nullptr) return;
	for (size_t i = 0; i < this->i; i++)
	{
		for (size_t j = 0; j < this->j; j++)
		{
			cout << this->arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void matrix::trans()
{
	if (this->arr == nullptr) return;
	int** tmp = new int*[this->j];
	for (size_t n = 0; n < this->j; n++)
	{
		tmp[n] = new int[this->i];
		for (size_t m = 0; m < this->i; m++)
		{
			tmp[n][m] = this->arr[m][n];
		}
	}
	for (size_t i = 0; i < this->i; i++)
	{
		delete[]this->arr[i];
	}
	delete[]this->arr;
	this->arr = tmp;
	swap(this->i, this->j);	
}

int * matrix::operator[](int index)
{	
	return this->arr[index];
}

void matrix::operator+=(int number)
{
	if (this->arr == nullptr) return;
	for (size_t n = 0; n < this->i; n++)
	{
		for (size_t m = 0; m < this->j; m++)
		{
			this->arr[n][m] += number;
		}
	}
}

void matrix::operator-=(int number)
{
	if (this->arr == nullptr) return;
	for (size_t n = 0; n < this->i; n++)
	{
		for (size_t m = 0; m < this->j; m++)
		{
			this->arr[n][m] -= number;
		}
	}
}

void matrix::operator*=(int number)
{
	if (this->arr == nullptr) return;
	for (size_t n = 0; n < this->i; n++)
	{
		for (size_t m = 0; m < this->j; m++)
		{
			this->arr[n][m] *= number;
		}
	}
}

void matrix::operator/=(int number)
{
	if (this->arr == nullptr) return;
	for (size_t n = 0; n < this->i; n++)
	{
		for (size_t m = 0; m < this->j; m++)
		{
			this->arr[n][m] /= number;
		}
	}
}


matrix::~matrix()
{
	for (size_t i = 0; i < this->i; i++)
	{
		delete[]this->arr[i];
	}
	delete[]this->arr;
	this->i = 0;
	this->j = 0;
	this->arr = nullptr;
}

bool operator==(const matrix & a, const matrix & b)
{
	
	return false;
}

ostream & operator<<(ostream & os, const matrix & obj)
{
	
	return os;
}