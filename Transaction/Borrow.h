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

using namespace std;

class Borrow: public Transaction {

public:
	Borrow(int, Movie*);
	virtual ~Borrow();
	
	int getCustomerID(); // get ID of the customer of the transaction
	
	// perform borrow movie
	virtual bool perform(MovieInventory&, CustomerInventory&); 

private:
	Movie* movie; // movie to borrow 
	int customerID; // customer responsible for the transaction
};
#endif