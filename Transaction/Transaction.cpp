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

Transaction::Transaction()
{
	
}

Transaction::~Transaction()
{
	
}

virtual void Transaction::perform(MovieInventory&, CustomerInventory*)
{
	
}

virtual string Transaction::getSummary()
{
	
}