/////////////////////////////////////////////////////////
// Bob Myers
//
// sample.cpp -- sample test program starter for Temperature class
/////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

int main()
{
	Temperature t1(50, 'F');		// should default to 0 Celsius
	Temperature t2(41, 'F');  // should init to 34.5 Fahrenheit 
	

								// display dates to the screen
	
	cout << "\nTemperature t1 is: ";
	t1.Show();
	cout << "\nTemperature t2 is: ";
	t2.Show();

	//t1.Input();			// Allow user to enter a temperature for t1
	//cout << "\nTemperature t1 is: ";
	//t1.Show();
	
	
	t1.SetFormat('P');		// change format of t1 to "Long" format
	//cout << "\nTemperature t1 is: ";
	t1.Show();

	t1.Convert('F');
	t1.Show();
	// and so on.  Add your own tests to fully test the class' 
	//   functionality. */

t1.Increment(5, 'C');
t1.Show();

t2.Increment(5, 'C');
t2.Show();

}