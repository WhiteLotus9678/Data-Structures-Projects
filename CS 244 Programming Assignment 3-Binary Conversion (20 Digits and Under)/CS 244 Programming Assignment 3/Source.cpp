/*
-----------------------
William Yang
CS-244 Data Structures
Secion-001
Instructor: Mark
Programming Assignment 3
11/30/16
-----------------------
*/
#include <iostream>
#include <string>
#include <math.h>
#include "Stack.h"

using namespace std;

/*
-----------------------------------------
Refer to Stack.h for function definitions
-----------------------------------------
*/

template <class T> //Self-Note: Don't forget to insert "<T>" after class' name
mystack<T>::mystack(int size = 100)
{
	this->maxStackSize = size;
	this->stackTop = 0;
	this->list = new T[size];
}

template <class T>
const mystack<T>& mystack<T>::operator=(const mystack<T>& otherstack)
{
	if (this != &otherstack) //Self-Note: Avoids self-copy
	{
		copyStack(otherstack);
	}

	return *this;
}

template<class T>
mystack<T>::mystack(const mystack<T>& otherstack)
{
	list = NULL;
	this->copyStack(otherstack);
}

template<class T>
void mystack<T>::initializeStack()
{
	stackTop = 0;
}

template<class T>
bool mystack<T>::isEmptyStack()
{
	return (this->stackTop == 0);
}

template<class T>
bool mystack<T>::isFullStack()
{
	return (this->stackTop == this->maxStackSize);
}

template<class T>
void mystack<T>::push(const T & myelement)
{
	//Self-Note: Check if the list is not full to insert an object
	if (!this->isFullStack())
	{
		this->list[this->stackTop] = myelement;
		this->stackTop++;
		//Debugging code: cout << myelement << " was inserted into the stack." << endl; //checks the numbers in the stack
	}
	else
	{
		cout << "Cannot add to a full stack." << endl;
	}
}

template<class T>
T mystack<T>::top() const
{
	//Self-Note: Check if the list is not empty to check
	if (this->stackTop != 0) //Self-Note: Supposed to be if(!isEmptyStack), but is causing problems
	{
		return this->list[this->stackTop - 1];
	}
	else
	{
		cout << "The stack is empty." << endl;
		return NULL;
	}
}

template<class T>
void mystack<T>::pop()
{
	//Self-Note: Check if the list is not empty to delete the top
	if (!this->isEmptyStack())
	{
		this->stackTop--;
	}
	else
	{
		cout << "Cannot remove from an empty stack." << endl;
	}
}

template <class T>
void mystack<T>::binToDecStorage(string binary, mystack<T>& otherstack)
{

	const int SIZE = 20;
	int binArray[SIZE];
	long output = 0;
	int exponent = 0;

	for (int i = 0; i < binary.length(); i++)
	{
		binArray[i] = binary.at(i) - '0';
	}

	//Self-Note: Reads left to right, but exponent is not based on array index because that would mess up the math
	for (int k = binary.length()-1; k >= 0; k--)
	{
		//Self-Note: Use modular division
		if ((binArray[k] % 10) == 1)
		{
			otherstack.push(1 << exponent); //Self-Note: Exponential multiplicatio for integers
		}
		//Debugging Code:
		/*if ((binArray[k] == 1))
		{
			otherstack.push(pow(2, exponent));
		}*/
		exponent++;
	}
}

template <class T>
mystack<T>::~mystack()
{
	this->list = new T; //Self-Note: Dynamically allocated, can call delete on it
	delete[] this->list; //Self-Note: Frees memory
	this->list = NULL; //Self-Note: Set dangling ptr to NULL
}

int testBinary(string binary)
{
	//Self-Note: Converts a binary number into an array of integers
	if (binary.length() > 20)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < binary.length(); i++)
		{
			if (binary.at(i) == '1' || binary.at(i) == '0')
			{
				if (i == binary.length() - 1)
				{
					return true;
				}
			}
		}
	}
}

/*
-----------------------------------
Binary to Decimal Stacks Program
-----------------------------------
*/
int main()
{
	bool run = true;
	string numberEntry = "0";
	int output = 0;

	cout << "Hello! This program converts a binary number you enter into its corresponding decimal number." << endl
		<< "Keep in mind that you must enter a binary number that has 20 digits or less." << endl << endl;

	mystack<int> Stack;

	Stack.initializeStack();

	while (run)
	{
		cout << "Enter a binary number. -1 to exit: ";

		//Self-Note: Checks to see if you input -1
		while (!(cin >> numberEntry) || !testBinary(numberEntry)) //Self-Note: If not a string (without spaces) or not a binary value
		{
			cout << "Bad value! Enter a binary integer with 20 digits or less.";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
		}
		//Self-Note: Clears the string input again
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;

		if (numberEntry == "-1")
		{
		run = false;
		}
		else
		{
			Stack.binToDecStorage(numberEntry, Stack);

			while (!Stack.isEmptyStack()) //Self-Note: Calculates the sum of the bits
			{
				output += Stack.top();
				Stack.pop();
			}
			cout << "The equivalent decimal number is: " << output << endl << endl;
			output = 0;
		}
	}

	//Debugging Code: system("pause");

	return 0;

}