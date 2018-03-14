/*Name: Debbie Guenthner
 *ID#:  A784G554
 *Email: a784g554@wichita.edu
 *Class: CS411
 *
 *Program: Assignment 5
 *Date: 12/02/2016
*/
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <fstream>
using namespace std;

class Matrix
{
	protected:
	   int numRows=0;
	   int numCols=0;
	   double **marray=nullptr;
	   void deleteSpace();
	   void allocSpace();
	   
	public:
	   
	   Matrix() { }
	   Matrix(const Matrix& ma2);
	   virtual ~Matrix();
	   int getNumRows() const;
	   int getNumCols() const;
	   Matrix& operator=(const Matrix& ma2);
	   friend Matrix operator+(Matrix& m1, const Matrix& m2);
	   virtual void printDiagonal() const;
	   
	   
	   friend ostream& operator<<(ostream& OSObj, const Matrix& mdata);
	   friend istream& operator>>(istream& ISObj, Matrix& mdata);
	   
};

  
#endif
