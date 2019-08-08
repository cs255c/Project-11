/* Define exception for dividing by zero
 * 4/24/2015
 * Alex Debrecht */

#ifndef DIVIDEBYZERO_H_
#define DIVIDEBYZERO_H_

#include <stdexcept>
using namespace std;

// Extends runtime_error
class DivideByZeroException : public runtime_error {

	// Define message to be printed by console, or passed to catch
public:
	DivideByZeroException() : runtime_error("Cannot divide by zero."){
	}
};

#endif /* DIVIDEBYZERO_H_ */
