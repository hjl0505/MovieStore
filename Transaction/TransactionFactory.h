// TransactionFactory.h--------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Factory that creates different transactions
// ----------------------------------------------------------------------------
// create funtion holds a switch to instantiate the correct transaction
// based on the type passed in.
// ----------------------------------------------------------------------------

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"


class TransactionFactory {

public:
	TransactionFactory();
	~TransactionFactory();
	
	// create transactions
	Transaction create(char type, int customerID, Movie* m);
};
#endif