// Store.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Store class holds the business logic for the inventory system
// ----------------------------------------------------------------------------
// The essential business logic is the performTransaction method 
// which performs either borrowing or returning a movie, 
// printing inventory of all the items, 
// and printing transaction history of a customer.
// performTransaction also checks for bad inputs from the input file.
// ----------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include <iostream> //input and output
#include <fstream> // reading file
#include <sstream> // reading string as input
#include "../Customer/CustomerInventory.h"
#include "../Customer/Customer.h"
#include "../Movie/MovieInventory.h"
#include "../Movie/MovieFactory.h"
#include "../Movie/Movie.h" 
#include "../Transaction/TransactionFactory.h" 
#include "../Transaction/Transaction.h"  
using namespace std;

class Store {

public:
	Store();
	~Store();
	
	void readCustomerFile (ifstream&); // load customers into customerTable
	void readMovieFile (ifstream&); // load movies into movieTable
	void readTransactionFile (ifstream&); // read transactions and execute 
	
	bool performTransaction (Transaction*); // execute a transaction
	
private: 
	MovieInventory movieTree; // BST of movies
	CustomerInventory customerTable; // hash table of customers
	MovieFactory movieFactory; // movie factory
	TransactionFactory transFactory; // transaction factory
	
	// helpers
	string readStringStream(stringstream&);
	string readStringStreamClassic(stringstream&);
};
#endif