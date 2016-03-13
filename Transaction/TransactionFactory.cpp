// TransactionFactory.cpp--------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Factory that creates different transactions
// ----------------------------------------------------------------------------
// create funtion holds a switch to instantiate the correct transaction
// based on the type passed in.
// ----------------------------------------------------------------------------

#include "TransactionFactory.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

// nothing initialized
TransactionFactory::TransactionFactory()
{
}

// no memory leak possible
TransactionFactory::~TransactionFactory()
{
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////


Transaction* TransactionFactory::create(char type, int customerID, Movie* m)
{
	Transaction* transaction = NULL;
	switch(type) 
	{
		case 'B':
			transaction = new Borrow(customerID, m);
			return transaction;
			break;
		case 'R':
			transaction = new Return(customerID, m);
			return transaction;
			break;
		case 'I':
			transaction = new Inventory;
			return transaction;
			break;
		case 'H':
			transaction = new History(customerID);
			return transaction;
			break;
		default:
			cout << "ERROR: " << type << " Invalid Transaction Type. Try Again." << endl;
			return transaction;
			break;
	}
}
