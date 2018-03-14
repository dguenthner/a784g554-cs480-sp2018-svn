/*Name: Debbie Guenthner
 *ID#:  A784G554
 * Email: a784g554@wichita.edu
 *Class: CS411
 *
 *Program: Assignment 5
 *Date: 12/02/2016
*/
//Added this new line here 2018-03-03
#include "Matrix.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Matrix::deleteSpace()
{
	for(int i=0; i<numRows; i++)
	{
		delete[] marray[i];
	}
	delete[] marray;
	numRows = numCols = 0;
	marray = nullptr;

}

void Matrix::allocSpace()
{
	marray = new double *[numRows];
	for(int i=0; i<numRows; i++)
	{
		marray[i] = new double[numCols];
	}
}

Matrix::Matrix(const Matrix& ma2)
	:numRows(ma2.getNumRows()), numCols(ma2.getNumCols())
{
	allocSpace();
	for(int i=0; i<getNumRows(); i++)
	{
		for(int j=0; j<getNumCols(); j++)
		{
			marray[i][j] = ma2.marray[i][j];
		}
	}
	cout << "Matrix copy ctor: Allocated the matrix" << endl;
}

Matrix::~Matrix()
{
	deleteSpace();
	cout << "Matrix dtor: Released the matrix" << endl;
}

int Matrix::getNumRows() const
{
	return (numRows);
}

int Matrix::getNumCols() const
{
	return (numCols);
}

Matrix& Matrix::operator=(const Matrix& ma2)
{
	if (this == &ma2)
	{
		cout << "\nMatrix operator=: Assigned the matrix" << endl;
		return *this;
	}
	else
	{
		deleteSpace();
		numRows = ma2.getNumRows();
		numCols = ma2.getNumCols();
		allocSpace();

		for(int i=0; i<numRows; i++)
		{
			for(int j=0; j<numCols; j++)
			{
				marray[i][j] = ma2.marray[i][j];
			}
		}
		cout << "\nMatrix operator=: Assigned the matrix" << endl;
		return *this;
	}
}

Matrix operator+(Matrix& m1, const Matrix& m2)
{
	Matrix summe(m1);
	for(int i=0; i<summe.getNumRows(); i++)
	{
		for(int j=0; j<summe.getNumCols(); j++)
		{
			summe.marray[i][j] += m2.marray[i][j];
		}
	}
	return summe;
}

void Matrix::printDiagonal() const
{
	cout << "Matrix::printDiagonal(): Sorry, no diagonal" << endl << endl;
}

ostream& operator<<(ostream& OSObj, const Matrix& mdata)
{
	OSObj << "a square matrix of size " << mdata.getNumRows() << endl;
	
	for(int i=0; i<mdata.getNumRows(); i++)
	{
		for(int j=0; j<mdata.getNumCols(); j++)
		{
			OSObj << mdata.marray[i][j] << " ";
		}
		OSObj << endl;
	}
	return OSObj;
}

istream& operator>>(istream& ISObj, Matrix& mdata)
{
	mdata.deleteSpace();
	
	ISObj >> mdata.numRows >> mdata.numCols;
	ISObj.ignore(1000,'\n');
	
	mdata.allocSpace();

	for(int i=0; i<mdata.getNumRows(); i++)
	{
		for(int j=0; j<mdata.getNumCols(); j++)
		{
			ISObj >> mdata.marray[i][j];
		}
	}
	return ISObj;
}


