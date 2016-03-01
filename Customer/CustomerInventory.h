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

class CustomerInventory {

public:
	static const int MAX = 10000 // max ID
	
	CustomerInventory();
	~CustomerInventory();
	
	Customer getCustomer (int); // get Customer with ID
	bool customerExist (int); // Check if customer exists with ID
		
	bool addCustomer(Customer); // add customer to inventory
	bool removeCustomer(int); // remove customer from inventory

private:
	Customer* hashTable [MAX]; // hash table
	int hashFunction (int) // calculate hash key
};
#endif
