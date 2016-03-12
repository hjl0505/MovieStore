// CustomerInventory.cpp---------------------------------------------------------
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

#include "CustomerInventory.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

// intialize hash table of dummy customer nodes
CustomerInventory::CustomerInventory()
{
	for (int i = 0; i < MAX; i++) 
	{
		hashTable[i] = new customerNode; 
		hashTable[i] -> customer = NULL;
		hashTable[i] -> next = NULL;
	}
}

CustomerInventory::~CustomerInventory()
{
/*       for (int i = 0; i < MAX; i++) 
	{
		delete hashTable[i];
		hashTable[i] = NULL; 
	}   */ 	
} 

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

// return customer ptr or NULL if customer doesn't exist
Customer* CustomerInventory::getCustomer (int customerID)
{
	int bucket = hashFunction(customerID);
/*   	if (customerExist(customerID))
		return hashTable[customerID];
	return NULL;   */
}

bool CustomerInventory::customerExist (int customerID)
{
	int bucket = hashFunction(customerID);
 /*  	if (hashTable[customerID] == NULL)
		return false; // customer does not exist 
	return true;   */
}
	
bool CustomerInventory::addCustomer(int customerID, string firstName, string lastName)
{
	// check if customer already exists
	if (getCustomer(customerID))
		return false;
	
	int bucket = hashFunction(customerID);
	customerNode* cur = hashTable[bucket] -> next;
	if (cur == NULL)
	{
		cur = new customerNode;
		cur -> customer = new Customer(id, firstName, lastName);
		cur -> next = NULL;
	}
	else
	{
		
	}
	return true;
	
	
	
/*    	if (!customerExist(id) && id < MAX) // add new customer if customer ID is unique
	{
 		hashTable[id] = new Customer (id, firstName, lastName);
		return true; 
	}  
	
	cout << "Customer Already Exists" << endl;
	return false; // there is already customer with the ID.    */
}

bool CustomerInventory::removeCustomer(int customerID)
{
	int bucket = hashFunction(customerID);
/* 	if (customerExist(customerID)) // delete only if customer exists
	{
		delete hashTable[customerID];
		hashTable[customerID] = NULL; 
		return true; 
	}
	return false; */
}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

int CustomerInventory::hashFunction(int id)
{
	return id % MAX;
}