/*
William Yang
CS-244 Data Structures
Instructor: Mark
10/25/16
*/

#include <iostream>
#include <string>
#include "BookList.h"

using namespace std;

BookList::BookList()
{
	count = 0; //when a BookList object is created, the number of Book nodes in it is 0
	first = NULL; //the "first" node points nowhere
	last = NULL; //the "last" node points to nowhere too
}

int BookList::CountBooks()
{
	Book* current = first; //a Book object is created
	int total = 0; //total is reset to 0

	while (current != NULL) //current traverses the linked list and with each step, adds up the quantity value of the books together
	{
		total += current->quantity;
		current = current->next;
	}

	return total; //returns the total value of all books in stock
}

bool BookList::IsEmpty()
{
	return count == 0; //test for equality
}

void BookList::Insert(string t, int q, double p)
{
	{
		Book* mybook = new Book(t, q, p); //pointer to create a new node
		Book* current; //pointer to traverse list
		Book* trailcurrent; //pointer before current
		bool found = false; //boolean variable to track where in the linked list the book should be inserted

		//Case 1: The list is empty
		if (IsEmpty())
		{
			first = mybook; //first points to the new book object
			last = mybook; //last points to the new book object
			count++; //once the new book object is created, count is incremented
		}
		else
		{
			current = first;
			trailcurrent = current;

			while (current != NULL && !found) //Search the list
			{
				if (current->title == mybook->title) // Case 5: The book is already in the list, so update it
				{
					cout << "The book is already in the list. Updating list..." << endl;
					current->quantity = mybook->quantity;
					current->price = mybook->price;
					//There is no incrementation because the book was previously added to the list
					return;
				}
				else if (current->title >= mybook->title)
				{
					found = true;
				}
				else //Traverses the list until a spot is found to place the new book object
				{
					trailcurrent = current;
					current = current->next;
				}
			}
			if (current == first) //Case 2: Insert the new book object at the beginning of the linked list
			{
				mybook->next = first;
				first = mybook;
				count++;
			}
			else //Case 3: Insert the new book object in the middle and if mybook is a lexicographically larger title, move it to the end of the linked list
			{
				trailcurrent->next = mybook;
				mybook->next = current;
				if (current == NULL)
				{
					last = mybook;
				}
				count++;
			}
		}
	}
}

void BookList::Remove(string t)
{
	Book* current = first;
	Book* trailcurrent = current;
	bool found = false;

	if (first == NULL) //Case 1: The list is empty
	{
		cout << "There are no stocks in the list." << endl;
	}

	else
	{
		while (current != NULL && !found) //Search the list
		{
			if (current->title >= t)
			{
				found = true;
			}
			else //Traverses list until the book is found, else move to case 4
			{
				trailcurrent = current;
				current = current->next;
			}
		}

		if (current == NULL) //Case 4: The list is empty
		{
			cout << "The item to be deleted is not in the list." << endl;
		}

		else
		{
			if (current->title == t) //The list is not empty and the item to be deleted is in the list
			{
				if (first == current) //Case 2: The item to be deleted is the first in the list
				{
					first = first->next; //The "first" node now points to the node after the one to be deleted

					if (first == NULL)
					{
						last = NULL;
					}

					delete current;

					cout << "The book \"" << t << "\" was deleted from the list." << endl;
				}
				else //Case 3: The item to be deleted is somewhere in the middle of the list
				{
					trailcurrent->next = current->next;

					if (current == last)
					{
						last = trailcurrent;
					}
					delete current;
				}
				count--;
			}
			else //Case 4: The item is not in list
			{
				cout << "The item to be deleted is not in the list." << endl;
			}
		}
	}
}

void BookList::Print()
{
	int tempCount = 1;
	Book* current = first;

	//If the list is empty, this is printed
	if (IsEmpty())
	{
		cout << "There no no books in stock.";
	}

	//If the list is not empty, the books and their assigned qualities will be printed out
	while (current != NULL)
	{
		cout << "Book " << tempCount << ": " << current->title << "\n\tQuantity: " << current->quantity << "\n\tPrice: $" << current->price << "\n";
		current = current->next;
		tempCount++;
	}
	cout << endl;
}

void BookList::Search(string t)
{
	bool found = false;
	Book* current = first;

	while (current != NULL && !found) //Search the list until the book is found
	{
		if (current->title >= t)
		{
			found = true;
		}
		else
		{
			current = current->next;
		}
	}

	//Print the book and its qualities if it is found, else print a different message
	if (found)
	{
		cout << "The book \"" << t << "\" was found." << endl;
		cout << "Title: " << current->title << "\n\tQuantity: " << current->quantity << "\n\tPrice: $" << current->price << endl;
	}
	else
	{
		cout << "The book is not in the list." << endl;
	}
}

BookList::~BookList()
{
	Book* current = first;
	Book* previous = last;

	while (current != NULL)
	{
		previous = current;
		current = current->next;
		delete previous;
	}
}

int main()
{

	BookList theList; //A new BookList object, theList, is created
	string title;
	int quantity;
	double price;

	while (true) //Go through the loop as long as 999 is not entered
	{
		int input = 0;

		cout << "Enter 1 to insert a book record\n"
			<< "Enter 2 to delete a book record\n"
			<< "Enter 3 to print the book list\n"
			<< "Enter 4 to search the book list\n"
			<< "Enter 999 to stop\n";

		// The following while loops test whether or not user input is valid
		while (!(cin >> input)) {
			cout << "Bad value!";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl;
		}

		if (input == 999)
		{
			break;
		}
		switch (input)
		{
		//
		case 1:
		{
			cout << "Enter the book's title: ";
			cin.ignore();

			while (!(getline(cin, title))) {
				cout << "Bad value!";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}

			cout << "Enter the book's quantity: ";
			while (!(cin >> quantity)) {
				cout << "Bad value!";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}

			cout << "Enter the book's price: ";
			while (!(cin >> price)) {
				cout << "Bad value!";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl;
			}

			theList.Insert(title, quantity, price);
		}
		cout << endl;
		break;
		//
		case 2:
		{
			cout << "Enter the book to be deleted: ";
			cin.ignore();
			string title;
			getline(cin, title);
			theList.Remove(title);
		}
		cout << endl;
		break;
		//
		case 3:
		{
			cout << endl;
			cout << "Total number of books: " << theList.CountBooks()  << endl << endl; //Prints the total number of books in stock
			theList.Print();
		}
		cout << endl;
		break;
		//
		case 4:
		{
			cout << "Enter the title of the book you would like to search for: ";
			cin.ignore();
			string title;
			getline(cin, title);
			theList.Search(title);
		}
		cout << endl;
		break;
		}
	}

	return 0;
}