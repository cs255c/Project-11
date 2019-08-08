/* Test the Rational class with exception for division by zero
 * 4/24/2015
 * Alex Debrecht */

#include <iostream>
#include "Rational.h"
#include "DivideByZero.h"
using namespace std;

// function main begins program execution
int main() {

	// Declare variables
	int num1;
	int denom1;
	int num2;
	int denom2;
	bool ans = true;
	char ansChar;
	bool exception = true;
	Rational frac;
	Rational frac2;

	// Loop if user wants to test with multiple numbers
	while (ans) {

		// Declare and initialize rationals, catching zeros in denominator
		while(exception) {
			try {
				// Ask user for rational numbers (numerators and denominators)
				cout << "Enter the numerator of the first fraction." << endl;
				cin >> num1;
				cout << "Enter the denominator of the first fraction." << endl;
				cin >> denom1;
				cout << "Enter the numerator of the second fraction." << endl;
				cin >> num2;
				cout << "Enter the denominator of the second fraction." << endl;
				cin >> denom2;

				// Initialize rationals
				frac = Rational(num1,denom1);
				frac2 = Rational(num2,denom2);

				exception = false;
				// Catch exception from division by zero
			} catch (DivideByZeroException &e) {
				cerr << "An exception occurred: " << e.what() << endl;
				exception = true;
			}
		}

		exception = true;

		// Test overloaded + operator
		Rational frac3 = frac + frac2;
		cout << frac << " + " << frac2 << " = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;
		cout << "First fraction is not destroyed: " << frac << endl;

		// Subtract frac2 from frac and print
		frac3 = frac - frac2;
		cout << frac << " - " << frac2 << " = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Multiply frac by frac2 and print
		frac3 = frac * frac2;
		cout << frac << " * " << frac2 << " = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		// Divide frac by frac2 and print
		try {
			frac3 = frac / frac2;
			cout << frac << " / " << frac2 << " = " << frac3 << " = ";
			frac3.printFloat();
			cout << endl;
			// Catch exception if division by zero is attempted
		} catch (DivideByZeroException &e) {
			cout << "An exception occurred (Division): " << e.what() << endl;
		}

		// Negate frac
		frac3 = -frac;
		cout << "-(" << frac << ") = " << frac3 << " = ";
		frac3.printFloat();
		cout << endl;

		try {
			// Take the reciprocal of frac
			frac3 = !frac;
			cout << "1/(" << frac << ") = " << frac3 << " = ";
			frac3.printFloat();
			cout << endl;
		} catch (DivideByZeroException &e) {
			cout << "An exception occurred (Reciprocal): " << e.what() << endl;
		}

		// Check combinations of functions
		try {
			frac3 = (frac + frac2)/(frac - frac2);
			cout << "(" << frac << " + " << frac2 << ")/(" << frac << " - " <<
					frac2 << ") = " << frac3 << " = ";
			frac3.printFloat();
			cout << endl;
			// Catch exception if division by zero is attempted
		} catch (DivideByZeroException &e) {
			cout << "An exception occurred (Function combinations): " << e.what() << endl;
		}

		// Check less than operator
		if (frac < frac2) {
			cout << frac << " < " << frac2 << endl;
		}

		// Check greater than operator
		if (frac > frac2) {
			cout << frac << " > " << frac2 << endl;
		}

		// Check less than or equal to operator
		if (frac <= frac2) {
			cout << frac << " <= " << frac2 << endl;
		}

		// Check greater than or equal to operator
		if (frac >= frac2) {
			cout << frac << " >= " << frac2 << endl;
		}

		// Check equality
		if (frac == frac2) {
			cout << frac << " = " << frac2 << endl;
		}

		// Check inequality
		if (frac != frac2) {
			cout << frac << " != " << frac2 << endl;
		}

		// Ask user if they would like to loop again
		cout << "Would you like to test more fractions?" << endl;
		cin >> ansChar;

		// Set boolean based on answer
		if (ansChar == 'n' || ansChar == 'N') ans = false;

	}
}
