// Customer.h---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Customer Object
// ----------------------------------------------------------------------------
// Stores information about a customer.
// including first and last name, ID, history, and movies currently borrowed
// ----------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream> // input and output
#include "../Movie/Movie.h"
#include "../Movie/MovieFactory.h"
using namespace std;

class Customer {

public:
	// Constructor and Destructor
	Customer();
	Customer(int, string, string); // ID, first, last
	~Customer();
	
	// Accessors
	void display(); // display customer's name and id
	void displayHistory(); //display history of transactions

	int getID(); //return ID of customer
	string getName(); // return full name of customer
	
	// Mutators
 	void addHistory(string); // add transaction to history
	void addCheckedOut(Movie*); // add movie to customer's checkedOut list
	bool removeCheckedOut(Movie*); // remove movie from checkedOut list 

private:
	struct historyNode { // Node to keep track of history
		historyNode* next;
		string data; // transaction summary
	};
	
	struct checkedOutNode { // Node to keep track of movies borrowed
		checkedOutNode* next;
		Movie* movieBorrowed; // pointer to movies borrowed
	};
	
	string lastName;
	string firstName;
	int ID; // unique user ID
	historyNode *history; // linked list of transaction history nodes 
	checkedOutNode *checkedOut; // linked list of movies checked out
};
#endif