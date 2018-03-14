/*Name: Debbie Guenthner
 *ID#:  A784G554
 *Email: a784g554@wichita.edu
 *Class: CS411
 *
 *Program: Assignment 5
 *Date: 12/02/2016
*/

#include "SqMatrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void SqMatrix::deleteDSpace()
{
	delete[] diagonal;
	diagonal = nullptr;
}

void SqMatrix::allocDSpace()
{
	diagonal = new double[Matrix::getNumRows()+1];
}
SqMatrix::SqMatrix()
{
}

SqMatrix::SqMatrix(const SqMatrix& sa2)
	:Matrix(sa2)
{
	allocDSpace();
	int size = Matrix::getNumRows();
	for(int i=0; i<size; i++)
	{
		diagonal[i] = sa2.diagonal[i];
	}
	cout << "SqMatrix copy ctor: Allocated the diagonal" << endl;
}

SqMatrix::~SqMatrix()
{
	deleteDSpace();
	cout << "\nSqMatrix dtor: Released the diagonal" << endl;
}

SqMatrix& SqMatrix::operator=(const SqMatrix& sa2)
{
	if (this == &sa2)
	{
		Matrix::operator=(sa2);
		cout << "SqMatrix operator=: Assigned the diagonal" << endl;
		return *this;
	}
	else
	{
		Matrix::operator=(sa2);
		deleteDSpace();
		allocDSpace();
	
		int size = Matrix::getNumRows();
		for(int i=0; i<size; i++)
		{
			diagonal[i] = sa2.diagonal[i];
		}
		cout << "SqMatrix operator=: Assigned the diagonal" << endl;
		return *this;
	}
	
}
void SqMatrix::printDiagonal() const
{
	cout << "SqMatrix::printDiagonal(): ";
	int size = Matrix::getNumRows();
	for(int i=0; i<size; i++)
	{
		cout << diagonal[i] << " ";
	}
	cout << endl << endl;
}
		
ostream& operator<<(ostream& OSObj, const SqMatrix& sdata)
{
	OSObj << "a square matrix of size " << sdata.getNumRows() << endl;
	for(int i=0; i<sdata.getNumRows(); i++)
	{
		for(int j=0; j<sdata.getNumCols(); j++)
		{
			OSObj << sdata.marray[i][j] << " ";
		}
		OSObj << endl;
	}

	cout << "Its diagonal is: ";
	
	for(int i=0; i<sdata.getNumRows(); i++)
	{
		cout << sdata.diagonal[i] << " ";
	}
	OSObj << endl << endl;
	return OSObj;
}

istream& operator>>(istream& ISObj, SqMatrix& sdata)
{
	sdata.deleteSpace();
	
	ISObj >> sdata.numRows >> sdata.numCols;
	ISObj.ignore(1000,'\n');
	
	sdata.allocSpace();

	for(int i=0; i<sdata.getNumRows(); i++)
	{
		for(int j=0; j<sdata.getNumCols(); j++)
		{
			ISObj >> sdata.marray[i][j];
		}
	}
	sdata.allocDSpace();
	
	for(int i=0; i<sdata.getNumRows(); i++)
	{
		sdata.diagonal[i] = sdata.marray[i][i];
	}

	return ISObj;
}


