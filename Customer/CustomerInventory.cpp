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

// intialize hash table of NULL pointers
CustomerInventory::CustomerInventory()
{
	for (int i = 0; i < MAX; i++) 
		hashTable[i] = NULL;
}

CustomerInventory::~CustomerInventory()
{
	for (int i = 0; i < MAX; i++) 
	{
		delete hashTable[i];
		hashTable[i] = NULL;
	}
	//delete[] hashTable;
}

// return customer ptr or NULL if customer doesn't exist
Customer* CustomerInventory::getCustomer (int customerID)
{
	if (customerExist(customerID))
		return hashTable[customerID];
	return NULL;
}

bool CustomerInventory::customerExist (int customerID)
{
	if (hashTable[customerID] == NULL)
		return false; // customer does not exist
	return true;
}
	
bool CustomerInventory::addCustomer(Customer* customer)
{
	int id = customer -> getID();
	if (!customerExist(id)) // add new customer if customer ID is unique
	{
		hashTable[id] = customer;
		return true;
	}
	return false; // there is already customer with the ID.
	
}

bool CustomerInventory::removeCustomer(int customerID)
{
	delete hashTable[customerID];
	hashTable[customerID] = NULL;
}


//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
