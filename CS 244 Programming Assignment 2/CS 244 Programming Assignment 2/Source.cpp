/*
-----------------------
William Yang
CS-244 Data Structures
Programming Assignment 2
Instructor: Mark
11/10/16
-----------------------
*/

#include <iostream>
#include "Conversion.h"

using namespace std;

/*
-----------------------------------
Variable Definitions
-----------------------------------
*/
int flag = 0; //Used to exit the program
int num, base; //Used to set the integer and the base

int main()
{

	//If flag is set to -1, then exit the program
	while (flag != -1)
	{
		cout << "Enter a nonnegative integer. Enter -1 to exit: ";

		//Checking for valid input. the integer must be nonnegative.
		//However, if the number is -1, the program will exit at the end of the loop
		while (!(cin >> num) || (num < -1)) {
			cout << "Bad value! Please enter a nonnegative integer";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
		}

		flag = num; //Sets flag according to user input

		if (flag != -1)
		{
			cout << "Enter the desired base between 2 and 36: ";

			while (!(cin >> base) || (base < 2) || (base > 36)) {
				cout << "Bad value! Please enter an integer value between 2 and 36";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}

			//The recursive function is called here
			cout << num << " to the base " << base << " = ";
			decToBase(num, base);
			cout << endl << endl;
		}
	}

	system("pause");
	return 0;

}

/*
-----------------------------------
Function Declaration
-----------------------------------
*/
void decToBase(int num, int base)
{
	//Recursion stops here
	if (num == 0 || num == 1)
	{
		cout << num;
	}
	else if (num > 0)
	{
		//Recursion begins here until the number is equal to 0 or 1
		decToBase(num / base, base);

		//Converts numbers larger than 9 to letters when using a base higher than 10
		if ((num % base) == 10)
		{
			cout << "A";
		}
		else if ((num % base) == 11)
		{
			cout << "B";
		}
		else if ((num % base) == 12)
		{
			cout << "C";
		}
		else if ((num % base) == 13)
		{
			cout << "D";
		}
		else if ((num % base) == 14)
		{
			cout << "E";
		}
		else if ((num % base) == 15)
		{
			cout << "F";
		}
		else if ((num % base) == 16)
		{
			cout << "G";
		}
		else if ((num % base) == 17)
		{
			cout << "H";
		}
		else if ((num % base) == 18)
		{
			cout << "I";
		}
		else if ((num % base) == 19)
		{
			cout << "J";
		}
		else if ((num % base) == 20)
		{
			cout << "K";
		}
		else if ((num % base) == 21)
		{
			cout << "L";
		}
		else if ((num % base) == 22)
		{
			cout << "M";
		}
		else if ((num % base) == 23)
		{
			cout << "N";
		}
		else if ((num % base) == 24)
		{
			cout << "O";
		}
		else if ((num % base) == 25)
		{
			cout << "P";
		}
		else if ((num % base) == 26)
		{
			cout << "Q";
		}
		else if ((num % base) == 27)
		{
			cout << "R";
		}
		else if ((num % base) == 28)
		{
			cout << "S";
		}
		else if ((num % base) == 29)
		{
			cout << "T";
		}
		else if ((num % base) == 30)
		{
			cout << "U";
		}
		else if ((num % base) == 31)
		{
			cout << "V";
		}
		else if ((num % base) == 32)
		{
			cout << "W";
		}
		else if ((num % base) == 33)
		{
			cout << "X";
		}
		else if ((num % base) == 34)
		{
			cout << "Y";
		}
		else if ((num % base) == 35)
		{
			cout << "Z";
		}
		
		//Outputs the number if it is not larger than 9
		else
		{
			cout << num % base;
		}
	}
}