#include<iostream>
using namespace std;

#include "SqMatrix.h"

int main()
{  SqMatrix m1, m2;
   cin >> m1 >> m2;

   cout << "m2 is: " << m2 << endl;

   SqMatrix m3(m1);
   cout << "m3 is: " << m3 << endl;

   m3 = m3;
   cout << "m3 is: " << m3 << endl;

   m3 = m2;
   cout << "m3 is: " << m3 << endl;

// Make sure you understand the polymorphism below:

   Matrix m4(m1);
   Matrix *m5 = &m1;
   m1.printDiagonal();
   m4.printDiagonal();
   m5 -> printDiagonal();
}
