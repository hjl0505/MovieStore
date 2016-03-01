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

#include "../Movie/Movie.h"

class Transaction {
	
public:
	virtual void perform() // perform transaction
	virtual string getSummary() //return summary of transactions

private:
	char transType // type of transaction
	string summary // summary of transaction include all attributes
};
#endif