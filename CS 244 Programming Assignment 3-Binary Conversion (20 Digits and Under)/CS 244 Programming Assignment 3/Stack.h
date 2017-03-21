#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

/*
--------------------------------------
Stack Class
--------------------------------------
The stack data structure holds a list
of homogenous elements in which the
addition and deletion of elements
occurs only at one end (LIFO-type)
*/

template <class T>
class mystack
{
private:

	//Keeps track of the size of the stack
	int maxStackSize;

	//Keeps track of the top position of the array
	int stackTop;

	//The pointer is dynamically allocated
	T *list = new T[0];

	//CopyStack function allows us to copy content from one mystack object to another
	void copyStack(const mystack<T>& otherstack)
	{
		delete[] list;
		this->maxStackSize = otherstack.maxStackSize;
		this->stackTop = otherstack.stackTop;
		this->list = new T[maxStackSize];

		//copy otherstack into this stack
		for (int i = 0; i < this->stackTop; i++)
		{
			list[i] = otherstack.list[i];
		}
	}
public:

	/*
	--------------------------------------
	mystack
	--------------------------------------
	Constructor
	*/

	mystack(int size = 100);
	const mystack<T>& operator=(const mystack<T>& otherstack);
	mystack(const mystack<T>& otherstack);

	/*
	--------------------------------------
	initializeStack
	--------------------------------------
	Initializes the stack to an empty stack
	*/

	void initializeStack();

	/*
	--------------------------------------
	isEmptyStack
	--------------------------------------
	Determines whether the sack is empty.
	If the stack is empty, it returns the
	value true; otherwise, it returns the
	value false
	*/

	bool isEmptyStack();

	/*
	--------------------------------------
	isFullStack
	--------------------------------------
	Determines whether the stack is full.
	If the stack is full, it returns the
	value true; otherwise, it returns the
	value false
	*/

	bool isFullStack();

	/*
	--------------------------------------
	Push
	--------------------------------------
	Adds an element to the top of the stack.
	Prior to this operation, the stack
	must exist and  must not be full
	*/

	void push(const T & myelement);

	/*
	--------------------------------------
	Top
	--------------------------------------
	Returns the top element of the stack.
	Prior to this operation, the stack
	must exist and not be empty
	*/

	T top() const;

	/*
	--------------------------------------
	Pop
	--------------------------------------
	Removes the top element of the stack.
	Prior to this operation, the stack
	must exist and not be empty
	*/

	void pop();

	/*
	--------------------------------------
	binToDecStorage
	--------------------------------------
	Converts a an array of characters
	(that make up a binary number) into
	a decimal number
	*/

	void binToDecStorage(string binary, mystack<T>& otherstack);

	/*
	--------------------------------------
	~mystack
	--------------------------------------
	Deconstructor
	*/

	~mystack();
};

#endif