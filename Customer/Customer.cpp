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

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

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

//Input Constructor
//Initiates first and last to the passed in strings
//Initiates ID to the passed in id int
//History and checked out list are both empty
Customer::Customer(int id, string first, string last)
{
	firstName = first;
	lastName = last;
	ID = id;

	history = NULL;
	checkedOut = NULL;
}

//Destructor
//Deletes dynamic memory created by history and checkOut linked lists
Customer::~Customer()
{
 	// delete history list
	historyNode* temp = history;
	while (temp != NULL)
	{
  		history = history -> next;
		delete temp;
		temp = history;
	}

	// delete checked out list
 	checkedOutNode* cur = checkedOut;
 	while (cur != NULL)
	{
  		checkedOut = checkedOut -> next;
		delete cur -> movieBorrowed;
		cur -> movieBorrowed = NULL;
		delete cur;
		cur = checkedOut;
	}
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Display
//Displays the customer's ID, first name, and last name
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
	cout << zeros << ID  << "    ";
	cout.width(10);
	cout << left << firstName;
	cout.width(10);
	cout << left << lastName << endl;
}

// Display History
// Most recent to Least recent (newest transaction to oldest transaction)
void Customer::displayHistory()
{
	cout << endl;
	cout << "History for " << getName() << ":" <<endl;
	historyNode* temp = history;
	while (temp!= NULL)
	{
		cout << temp -> data << endl;
		temp = temp -> next;
	}
	cout << endl;
}

//Get ID
//Returns the customer's ID
int Customer::getID()
{
	return ID;
}

//Get Name
//Returns the customer's first and last name
string Customer::getName()
{
	return firstName + " " + lastName;
}

// Add History
// newest to oldest transaction
// insert new transaction to the front of the list of history
void Customer::addHistory(string summary)
{
	historyNode* newHistory = new historyNode;
	newHistory -> data = summary;
	newHistory -> next = history;
	history = newHistory;
}

// Add Checked Out
// insert new checked out movie in front of the list of checked out list
// customer can check out 2 copies of the same movie (do not check for double)
void Customer::addCheckedOut(Movie* movie)
{

	checkedOutNode* newMovieNode = new checkedOutNode;
	newMovieNode -> movieBorrowed = movie;
	newMovieNode -> next = checkedOut;
	checkedOut = newMovieNode;
}

//Remove Checked Out
//Returns true if customer was able to return a movie from their
//movieBorrowed linked list
bool Customer::removeCheckedOut(Movie* movie)
{
	checkedOutNode* cur = checkedOut;
 	if (cur != NULL)
	{
		// check the first checkedOutNode
		if (*(cur -> movieBorrowed) == *movie)
		{
			delete checkedOut -> movieBorrowed;
			checkedOut = cur -> next;
			delete cur;
			cur = NULL;
			return true;
		}

 		// check all other checkedOutNode
		checkedOutNode* prev = cur;
		cur = cur -> next;
		while (cur != NULL)
		{
 			if (*(cur -> movieBorrowed) == *movie)
			{
				delete cur -> movieBorrowed;
 				// remove movie from the list
				prev -> next = cur -> next;

				// delete pointers
				cur -> next = NULL;
				delete cur;
				return true;
			}
			prev = cur;
			cur = cur -> next;
		}
	}
	return false; // movie was not checked out by the customer
}
