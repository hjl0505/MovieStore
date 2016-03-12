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

// initialize transaction type to "Z"
// Summary indicates default transaction
Transaction::Transaction()
{
	transType = 'Z';
	summary = "Default Transaction";
}

// No memory leak possible
Transaction::~Transaction()
{
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

// Nothing performed
bool Transaction::perform(MovieInventory& movies, CustomerInventory& customers)
{
	return true;
}

string Transaction::getSummary()
{
	return summary;
}

void Transaction::setSummary(string transSummary)
{
	summary = transSummary;
}


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
