// History.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// History Transaction
// ----------------------------------------------------------------------------
// Sub class of Transaction
// prints the transaction history of a customer in first in last out order.
// ----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "Transaction.h"
#include "../Movie/MovieInventory.h"
#include "../Customer/Customer.h"
#include "../Customer/CustomerInventory.h"

using namespace std;

class History: public Transaction {

public:
	History(int);
	virtual ~History();
	
	int getCustomerID();
		
	// perform history
	virtual bool perform(MovieInventory&, CustomerInventory&); 

private:
	int customerID; // customer responsible for the transacti
};
#endif