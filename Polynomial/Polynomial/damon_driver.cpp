// Main Program Example for HW5

// You can use this file as your main program, or add more functions if you want.
// Please ***MAKE SURE*** that your class works fine in this main program.
// TA will test your class by this program with additional test data.


#include <iostream>
#include "Polynomial.h"
// ****If you need to include more header files, add it here****
#include "Interface.h"

using std::cout;
using std::cin;
using std::endl;

int main(){

	//TA DATA TEST
	cout << "-------------------------------------------------------------" << endl;
	cout << "Please Type in coefficients and exponents, seperated by SPACE" << endl;
	cout << ", and add 0 -1 in the end" << endl;
	cout << "For example, if you wish to assign P1 as 5x^3 -4x^2 + x -9" << endl;
	cout << "Type: 5 3 -4 2 1 1 -9 0 0 -1"<<endl;
	cout << "-------------------------------------------------------------" << endl << endl;

	Polynomial P1, P2, P3, P4;
	cout << "* Assign values for polynomial P1 *" << endl;
	cout << "Input: ";
	cin >> P1;
	cout << "P1 is: " << P1 << endl << endl;

	cout << "* Assign values for polynomial P2 *" << endl;
	cout << "Input: ";
	cin >> P2;
	cout << "P2 is: " << P2 << endl << endl;

	cout << "P3 = P1 - P2" <<endl;
	P3 = P1 - P2;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 += 11" << endl;
	P3 += 11;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 += P1" << endl;
	P3 += P1;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 = P1 * 4" << endl;
	P3 = P1 * 4;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 *= P2" << endl;
	P3 *= P2;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P3 = 2 * P1 * P2" << endl;
	P3 = 2 * P1 * P2;
	cout << "Now P3 is: " << P3 << endl << endl;

	cout << "P4 = P2 * 2 * P1" << endl;
	P4 = P2 * 2 * P1;
	cout << "Now P4 is: " << P4 << endl << endl;

	cout << "P3 now equals to P4, is that true?" << endl;
	if (P3 == P4) cout << "TRUE";
	else cout << "FALSE";
	cout << endl << endl;
	
	cout << "P4 is: " << P4 << endl;
	cout << "P4 (-6) equals to: " << P4(-6) <<endl << endl;

	cout << "---------- END TA PROGRAM ----------" << endl << endl;

    return 0;
}