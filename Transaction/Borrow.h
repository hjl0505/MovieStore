// Borrow.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Borrow Transaction
// ----------------------------------------------------------------------------
// Sub class of Transaction
// subtracts 1 stock from the Movie in MovieInventory.
// ----------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H

#include "Transaction.h"
#include "../Movie/Movie.h"
#include "../Movie/MovieInventory.h"
#include "../Customer/CustomerInventory.h"

class Borrow: public Transaction {

public:
	Borrow();
	~Borrow();
	
	virtual string getSummary(); // get summary of borrow transaction
	int getCustomerID(); // get ID of the customer of the transaction
	
	// perform borrow movie
	virtual void perform(MovieInventory& movieStock, CustomerInventory& customStock); 

private:
	Movie* movie; // movie to borrow 
	int customerID; // customer responsible for the transaction
};
#endif