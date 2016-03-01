// Return.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Return Transaction
// ----------------------------------------------------------------------------
// Sub class of Transaction
// adds 1 stock from the Movie in MovieInventory.
// ----------------------------------------------------------------------------

#ifndef RETURN_H
#define RETURN_H

#include "Transaction.h"
#include "../Movie/Movie.h"
#include "../Movie/MovieInventory.h"
#include "../Customer/CustomerInventory.h"
using namespace std;

class Return: public Transaction {

public:
	Return();
	~Return();
	
	virtual string getSummary(); // get summary of borrow transaction
	int getCustomerID(); // get ID of the customer of the transaction
	
	// perform Return movie
	virtual void perform(MovieInventory&, CustomerInventory&); 

private:
	Movie* movie; // movie to Return 
	int customerID; // customer responsible for the transaction
};
#endif