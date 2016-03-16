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

// Default Constructor
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

//Destructor
//Deletes dynamic memeory allocated by hashTable
CustomerInventory::~CustomerInventory()
{
    for (int i = 0; i < MAX; i++)
	{
		deleteHelper(hashTable[i] -> next); // delete list of customer in bucket

		delete hashTable[i] -> customer; // delete dummy node customer
		hashTable[i] -> customer = NULL;

		delete hashTable[i]; // delete dummy node
		hashTable[i] = NULL;
	}
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

// Get Customer
// return customer ptr or NULL if customer doesn't exist
Customer* CustomerInventory::getCustomer (int customerID)
{
	int bucket = hashFunction(customerID);
	customerNode* cur = hashTable[bucket] -> next;
   	if (cur == NULL)
		return NULL; // customer does not exist

	// traverse the bucket to get customer
	while (cur != NULL)
	{
		if (cur -> customer -> getID() == customerID)
			return cur -> customer;
		cur = cur -> next;
	}
	return NULL;
}

//Customer Exists
//Returns true if the customer is in the hash table
bool CustomerInventory::customerExist (int customerID)
{
	int bucket = hashFunction(customerID);
	customerNode* cur = hashTable[bucket] -> next;
   	if (cur == NULL)
		return false; // customer does not exist

	// traverse the bucket
	while (cur != NULL)
	{
		if (cur -> customer -> getID() == customerID)
			return true;
		cur = cur -> next;
	}
	return false;
}

//Add Customer
//Returns true if the customer was added to the hash table
bool CustomerInventory::addCustomer(int customerID, string firstName, string lastName)
{
  	// check if customer already exists
 	if (customerExist(customerID))
		return false;

	int bucket = hashFunction(customerID);
	customerNode* cur = hashTable[bucket] -> next;
	if (cur == NULL) // insert for first customer in bucket
	{
		cur = new customerNode;
		cur -> customer = new Customer(customerID, firstName, lastName);
		cur -> next = NULL;
		hashTable[bucket] -> next =  cur;
	}
	else // insert additional customers in the bucket
	{
		customerNode* temp = new customerNode;
		temp -> customer = new Customer(customerID, firstName, lastName);
		temp -> next = cur;
		hashTable[bucket] -> next = temp;
	}

	return true;
}

//Remove Customer
//Returns true if the customer was removed from the hash table
bool CustomerInventory::removeCustomer(int customerID)
{
 	if (customerExist(customerID)) // delete only if customer exists
	{
		int bucket = hashFunction(customerID);
		customerNode* cur = hashTable[bucket] -> next;
		customerNode* prev = hashTable[bucket];
		while (cur != NULL)
		{
			// delete customer ptr and customer node from hash table
			if (cur -> customer -> getID() == customerID) 
			{
				prev -> next = cur -> next;
				cur -> next = NULL;
				delete cur -> customer;
				cur -> customer = NULL;
				delete cur;
				cur = NULL;

				return true;
			}
			
			// current ptr moves to next customer
			prev = cur;
			cur = cur -> next;
		}
	}
	return false;
}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//Hash Function
//Returns the index where to store the customer in the hash table
int CustomerInventory::hashFunction(int id)
{
	return id % MAX;
}

//Delete Helper
//Recursive helper function for destructor
//Deletes dynamic memory created by hash table
void CustomerInventory::deleteHelper(customerNode* cur)
{
	customerNode* deleteNode = cur;
	while (cur != NULL)
	{
		cur = cur -> next;
		delete deleteNode -> customer;
		deleteNode -> customer = NULL;
		delete deleteNode;
		deleteNode = cur;

	}
}
