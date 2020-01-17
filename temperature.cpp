/* Name: Robert Cimarelli
COP3330 Spring 2018
Student ID: rac16c
Section 8
Assignment #2
Date: 2/15/2018
*/

#include <iostream>
#include <iomanip>
#include "temperature.h"
using namespace std;

Temperature::Temperature() //constructor 
{
	degree = 0;
	temperature = 'C';
}

Temperature::Temperature(double degrees, char temp) // constructor #2
{

degree = degrees; 
	temperature = temp;
	
	
	if (!Set(degrees, temp)) //error checking, using function
	{
		degree = 0;
		temperature = 'C';
	}
	else
	{
		degree = degrees;
		temperature = temp;
	} 
} 


void Temperature::Input()
{
	bool invalid; //error checking
	double degrees;
	char scale;
	//degrees = degree;
	//scale = temperature;
	do {
		invalid = false; //bool = true to re-iterate the funct
		cout << "Enter a temperature" << endl;
		cin >> degrees >> scale;

		if (degrees <= 0 && scale == 'K')
		{
			invalid = true;
			cout << "Invalid Temperature, please try again " << endl;
			continue;
		}
		if (degrees <= 0 && scale == 'k')
		{
			invalid = true;
			cout << "Invalid Temperature, please try again " << endl;
			continue;
		}
		if (degrees < -273.15 && scale == 'C')
		{
			invalid = true;
			cout << "Invalid Temperature, please try again " << endl;
			continue;
		
		}
		if (degrees < -273.15 && scale == 'c')
		{
			
			invalid = true;
			cout << "Invalid Temperature, please try again " << endl;
			continue;

		}
		if (degrees <= -459.688 && scale == 'F')
		{
			invalid = true;
			cout << "Invalid Temperature, please try again " << endl;
			continue;
		}
		else if (degrees <= -459.688 && scale == 'f')
		{
			invalid = true;
			cout << "Invalid Temperature, please try again " << endl;
			continue; //starts from the top
		} 
		if (scale == 'F' || scale == 'f' || scale == 'C' || scale == 'c' || scale == 'K' || scale == 'k')
		{
			degree = degrees;
			temperature = scale;
			invalid = false;
		}
		else
		{
			invalid = true;
			cout << "Invalid Temperature, please try again " << endl;
			continue;
		}
	} while (invalid == true);
}
void Temperature::Show() //print in different forms
{
	if (!SetFormat(format) || format == 'D')
	{
		cout << degree << " ";
		if (temperature == 'F' || temperature == 'f')
		{
			cout << 'F' << endl;
		}
		if (temperature == 'C' || temperature == 'c')
		{
			cout << 'C' << endl;
		}
		if (temperature == 'K' || temperature == 'k')
		{
			cout << 'K' << endl;
		}
	}
	else {
		switch (format)
		{
		case 'D':	// case 'D' already accounted for
			cout << degree << " ";
			if (temperature == 'F' || temperature == 'f')
			{
				cout << 'F' << endl;
			}
			if (temperature == 'C' || temperature == 'c')
			{
				cout << 'C' << endl;
			}
			if (temperature == 'K' || temperature == 'k')
			{
				cout << 'K' << endl;
			}
			
			break;
		case 'P': //print in 
		{
			int oldprecision = cout.precision();
		
			
			ios_base::fmtflags oldflags = cout.flags();

			cout << fixed << setprecision(1);
			cout << degree << " ";
		
			if (temperature == 'F' || temperature == 'f')
			{
				cout << 'F' << endl;
			}
			if (temperature == 'C' || temperature == 'c')
			{
				cout << 'C' << endl;
			}
			if (temperature == 'K' || temperature == 'k')
			{
				cout << 'K' << endl;
			}
			cout.precision(oldprecision); //restore settings
			cout.flags(oldflags); //restore
			break;
		}
		case 'L':
			switch (temperature)
			{
			case 'c':
			case 'C':
			{
				cout << degree << " ";
				cout << "Celsius";
				break;
			}
			case 'f':
			case 'F':
			{
				cout << degree << " ";
				cout << "Fahrenheit";
				break;
			}
			case 'k':
			case 'K':
			{
				cout << degree << " ";
				cout << "Kelvin";
				break;
			}
			}
			break;
		default:
			cout << degree << " ";
			if (temperature == 'F' || temperature == 'f')
			{
				cout << 'F' << endl;
			}
			if (temperature == 'C' || temperature == 'c')
			{
				cout << 'C' << endl;
			}
			if (temperature == 'K' || temperature == 'k')
			{
				cout << 'K' << endl;
			}
		}
	
	}


}

bool Temperature::Set(double deg, char s)
{
	degree = deg;
	temperature = s;

	if (degree <= 0 && s == 'K')
	{
		return false;
		
	}
	if (degree <= 0 && s == 'k')
	{
		return false;
	}
	if (degree <= -273.15 && s == 'C')
	{
		return false;
	}
	if (degree <= -273.15 && s == 'c')
	{
		return false;
	}
	if (degree <= -459.688 && s == 'F')
	{
		return false;
	}
	if (degree <= -459.688 && s == 'f')
	{
		return false;
	}
	//accounts for characters 
	else if (s == 'F' || s == 'f' || s == 'C' || s == 'c' || s == 'K' || s == 'k')
	{
		degree = deg;
		temperature = s;
		return true;
	}
		
	else
	{
		
		return false;
	}
}
double Temperature::GetDegrees() const
{
	return degree;
}
char Temperature::GetScale() const
{
	return temperature;
}
bool Temperature::SetFormat(char f)
{
	//format = f;
	switch (f)
	{
	case 'D': // valid
		format = f;
		return true; // valid setting
	case 'P': // valid setting
		format = f;
		return true; //valid setting
	case 'L': //valid setting
		format = f;
		return true;
	default:
		format = 'D';
		return false;
	}
	return false; // invalid
}
bool Temperature::Convert(char sc)
{
	//if (sc != temperature) // optional
//	{
		switch (sc)
		{
		case 'F':
		case 'f':
		{
			if (temperature == 'C' || temperature == 'c')
			{

				degree = (degree * 1.8) + 32;
				temperature = sc;

				return true;
			}
			if (temperature == 'K' || temperature == 'k')
			{
				degree = (degree * 9 / 5) - 459.67;
				temperature = sc;
				return true;
			}
			break;
			//else
		//	{
			//	return false;
			//}
		}
		case 'C':
		case 'c':
		{
			if (temperature == 'F' || temperature == 'f')
			{
				degree = (degree - 32) * (5 / 9.0);
				temperature = sc;
				return true;
			}
			if (temperature == 'K' || temperature == 'k')
			{
				degree = degree - 273.15;
				temperature = sc;
				return true;
			}
			break;
			//else
				//return false; option
		}
		case 'K':
		case 'k':
		{
			if (temperature == 'F' || temperature == 'f')
			{

				degree = (9 / 5.0)*(degree - 273) + 32; //converts temp as well
				temperature = sc;
				return true;
			}
			if (temperature == 'C' || temperature == 'c')
			{
				degree = degree + 273;
				temperature = sc;
				return true;

			}
			break;
			//	else
				//{
					//return false;
				//}
		}
		default:
		{
			return false;
		}
		}
	//}
		return false;
}
int Temperature::Compare(const Temperature &d) //just returns number
{
	if (degree > d.degree)
	{
		return -1;
	}
	if (degree == d.degree)
	{
		return 0;
	}
	if (degree < d.degree) 
	{
		return 1;
	}
}
void Temperature::Increment(int deg, char sc)
{
// would call the convert function, however, convert function changes temp; doesn't return original	
	if (temperature == sc) 
	{
		degree = degree + deg;
		
	}
	else
	{
		switch (sc)
		{
		case 'F':
		case 'f':
		{
			if (temperature == 'C' || temperature == 'c')
			{
				double temp = (degree * 1.8) + 32;
				degree = degree + temp;

			}
			if (temperature == 'K' || temperature == 'k')
			{
				double temp;
				temp = (degree * 9 / 5) - 459.67;
				degree = degree + temp;

			}
			break;

		}
		case 'C':
		case 'c':
		{
			if (temperature == 'F' || temperature == 'f')
			{
				double temp;
				temp = (degree - 32) * (5 / 9.0);
				degree = temp + degree;

			}
			if (temperature == 'K' || temperature == 'k')
			{
				double temp;
				 temp = degree - 273.15;
				 degree = temp + degree;
			}
			break;

		}
		case 'K':
		case 'k':
		{
			if (temperature == 'F' || temperature == 'f')
			{
				double temp;
				temp = (9 / 5.0)*(degree - 273) + 32;
				degree = temp + degree;

			}
			if (temperature == 'C' || temperature == 'c')
			{
				double temp; 
				temp = degree + 273;
				degree = temp + degree;

			}
			break;
		}

		}
	}
}
