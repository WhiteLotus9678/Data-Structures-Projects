#pragma once
#ifndef BOOKLIST_H_ICLUDED
#define BOOKLIST_H_INCLUDED

#include<iostream>
#include <string>
using namespace std;

class Book
{
public:
	string title; //title of the book
	int quantity; //number of books in stock
	double price; //price of book
	Book* next;

	/*
	--------------------------------------------------
	This constructor creates a Book object with title,
	my title, quantity, myquantity, and price, myprice.
	the next node is also set to NULL.
	--------------------------------------------------
	*/
	Book(string t, int q, double p)
	{
		title = t;
		quantity = q;
		price = p;
		next = NULL;
	}
};

class BookList
{
private:
	Book* first; //pointer to the first node
	Book* last; //pointer to the last node
	int count; //records number of nodes in the list

public:

	/*
	--------------------------------------------------
	Called when an object of BookList is created.
	Variables are then initialized.
	--------------------------------------------------
	*/
	BookList();
	
	/*
	--------------------------------------------------
	CountBooks calculates the total number of books in
	stock by finding the sum of the quantities of each
	book in stock.
	--------------------------------------------------
	*/
	int CountBooks();

	/*
	--------------------------------------------------
	IsEmpty checks whether or not the vector is empty
	and returns a boolean value of true or false.
	--------------------------------------------------
	*/
	bool IsEmpty();

	/*
	--------------------------------------------------
	Insert places a new book in the vector in
	lexicographical order according to the book's title.
	Tjhe book has title, t, number of copies in stock,
	q, and the price, p.
	If the book title already exists in the list, then
	upgrade the record with q and p.
	--------------------------------------------------
	*/
	void Insert(string t, int q, double p);

	/*
	--------------------------------------------------
	Remove deletes a book record, whose book title is
	t.
	If the book is not in the list, do nothing.
	--------------------------------------------------
	*/
	void Remove(string t);

	/*
	--------------------------------------------------
	Print prints the book records in the vector in the
	lexographical order of book titles.
	--------------------------------------------------
	*/
	void Print();

	/*
	--------------------------------------------------
	Search searches for the book with the given title,
	t.
	If the book is found, the book's title, quantity
	and price will be printed.
	Otherwise, report that the book is not in stock.
	--------------------------------------------------
	*/
	void Search(string t);

	/*
	--------------------------------------------------
	Called when the lifetime of a BookList object ends.
	Frees up resources that the object had.
	--------------------------------------------------
	*/
	~BookList();

};

#endif