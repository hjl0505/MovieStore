// Customer.cpp---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Customer Object
// ----------------------------------------------------------------------------
// Stores information about a customer.
// including first and last name, ID, history, and movies currently borrowed
// ----------------------------------------------------------------------------

#include "Customer.h"

// Default constructor 
// Initiates first and last name as Anonymous
// customer ID initiated to 0
// history and checked out list are both empty
Customer::Customer()
{
	firstName = "Anon";
	lastName = "Ymous"; 
	ID = 0;
	
	history = NULL;
	checkedOut = NULL;
}

Customer::Customer(int id, string first, string last)
{
	firstName = first;
	lastName = last;
	ID = id;
	
	history = NULL;
	checkedOut = NULL;
}

Customer::~Customer()
{
	// get rid of linked lists
}

void Customer::display()
{
	// set preceding 0 for 4 digit ID
	string zeros = "";
	if (ID < 10)
		zeros = "000";
	else if (ID < 100)
		zeros = "00";
	else if (ID < 1000)
		zeros = "0";
	
	// print customer info
	cout << firstName << setw(10) << lastName << setw(8) << zeros << ID << endl;  
}

// Most recent to Least recent (newest transaction to oldest transaction)
void Customer::displayHistory()
{
	historyNode* temp = history;
	while (temp!= NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> next;
	}
}

int Customer::getID()
{
	return ID;
}

string Customer::getName()
{
	return firstName + " " + lastName;
}

// newest to oldest transaction
// insert new transaction to the front of the list of history
void Customer::addHistory(string summary)
{
	historyNode* newHistory = new historyNode;
	newHistory -> data = summary;
	newHistory -> next = history;
	history = newHistory;
}

// insert new checked out movie in front of the list of checked out list
// customer can check out 2 copies of the same movie (do not check for double)
bool Customer::addCheckedOut(Movie* moviePtr)
{
	checkedOutNode* newMovie = new checkedOutNode;
	newMovie -> movieBorrowed = moviePtr;
	newMovie -> next = checkedOut;
	checkedOut = newMovie;
	return true;
}

bool Customer::removeCheckedOut(Movie* moviePtr)
{
	checkedOutNode* before = checkedOut;
	if (before != NULL) 
	{
		checkedOutNode* cur = checkedOut -> next;
		while (cur != NULL) 
		{
			if (*cur -> movieBorrowed == *moviePtr) 
			{
				// remove movie from the list
				before -> next = cur -> next; 
				
				// delete pointers
				cur -> next = NULL;
				cur -> movieBorrowed = NULL;
				delete cur -> movieBorrowed;
				delete cur;
				return true;
			}
			cur = cur -> next;
		}
	}
	return false; // movie was not checked out by the customer
}
