#include<iostream>
using namespace std;
//Adding this line 2018-03-03 to confirm this file has been changed.
#include "SqMatrix.h"
//Adding secone line 2018-03-03
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
