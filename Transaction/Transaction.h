// Transaction.h---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Super class of transactions
// ----------------------------------------------------------------------------
// Contains functions to perform a transaction 
// and get summary of the transaction
// ----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../Customer/CustomerInventory.h"
#include "../Movie/Movie.h"
#include "../Movie/MovieInventory.h"
using namespace std;

class Transaction {
	
public:

	// Constructor and Destructor
	Transaction();
	virtual ~Transaction();

	// perform transaction
	virtual bool perform(MovieInventory&, CustomerInventory&);

private:
	char transType; // type of transaction
};
#endif