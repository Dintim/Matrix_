#pragma once
#include <iostream>
using namespace std;

class matrix
{
	int **arr;
	int i;
	int j;
public:
	matrix();
	matrix(int i, int j, int number = 0);
	matrix(const matrix&obj);
	matrix&operator=(const matrix&obj);
	matrix(matrix&&obj);
	matrix&operator=(matrix&&obj);
	void print()const;
	void setElement(int index1, int index2, int number);
	int getI()const { return i; };
	int getJ()const { return j; };
	int getElement(int index1, int index2)const;
	void trans();
	int* operator[](int index);	
	void operator+=(int number);
	void operator-=(int number);
	void operator*=(int number);
	void operator/=(int number);
	~matrix();
};

bool operator==(const matrix&a, const matrix&b);
ostream&operator<<(ostream&os, const matrix&obj);
istream&operator>>(istream&is, matrix&obj);