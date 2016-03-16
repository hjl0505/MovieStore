// CustomerInventory.h---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Holds inventory of the customers.
// ----------------------------------------------------------------------------
// This class stores all the Customer objects in a open hash table, 
// It uses their ID as a unique key. 
// It provides methods to add, remove, get, and check if a customer exists 
// ----------------------------------------------------------------------------

#ifndef CUSTOMERINVENTORY_H
#define CUSTOMERINVENTORY_H

#include "Customer.h"
#include <iostream> // input and output
using namespace std;

class CustomerInventory {

public:
	static const int MAX = 10000; // max number of IDs
	
	// Constructor and Destructor
	CustomerInventory();
	~CustomerInventory();
	
	// Accessors
	Customer* getCustomer (int); // get Customer with ID
	bool customerExist (int); // check if customer exists with ID
	
	// Mutators
	bool addCustomer(int, string, string); // add customer to inventory
	bool removeCustomer(int); // remove customer from inventory

private:
	struct customerNode 
	{
		Customer* customer;
		customerNode* next;
	};
	customerNode* hashTable[MAX]; // open hash table for customer nodes
	
	// helper functions
	int hashFunction(int); // calculate which bucket to insert customer
	void deleteHelper(customerNode*); // delete linked list in a hash bucket
};
#endif
