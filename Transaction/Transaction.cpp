// Transaction.cpp---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Super class of transactions
// ----------------------------------------------------------------------------
// Contains functions to perform a transaction
// and get summary of the transaction
// ----------------------------------------------------------------------------

#include "Transaction.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

// Default Constructor
// initialize transaction type to "Z"
// Summary indicates default transaction
Transaction::Transaction()
{
	transType = 'Z';
}

// Destructor
// No memory leak possible
Transaction::~Transaction()
{
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

// Default perform
// Nothing performed
bool Transaction::perform(MovieInventory& movies, CustomerInventory& customers)
{
	return true;
}
