/*Name: Debbie Guenthner
 *ID#:  A784G554
 *Email: a784g554@wichita.edu
 *Class: CS411
 *
 *Program: Assignment 5
 *Date: 12/02/2016
*/
#ifndef __SQMATRIX_H__
#define __SQMATRIX_H__

#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;

class SqMatrix: public Matrix
{
	private:
	   double *diagonal=nullptr;
	   void deleteDSpace();
	   void allocDSpace();
	   
	public:
	   SqMatrix();
	   SqMatrix(const SqMatrix& sa2);
	   virtual ~SqMatrix();
	   SqMatrix& operator=(const SqMatrix& sa2);
	   virtual void printDiagonal() const;
	   
	   friend ostream& operator<<(ostream& OSObj, const SqMatrix& sdata);
	   friend istream& operator>>(istream& ISObj, SqMatrix& sdata);
	   
};

  
#endif
