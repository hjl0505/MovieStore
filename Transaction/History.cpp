// History.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// History Transaction
// ----------------------------------------------------------------------------
// Sub class of Transaction
// prints the transaction history of a customer in first in last out order.
// ----------------------------------------------------------------------------

#include "History.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

//Input Constructor
//Initializes customer for history transaction
History::History(int id)
{
	customerID = id;
}

//Destructor
//No dynamic memory allocated
History::~History()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Perform
//Returns true if history was perfomred successfully
bool History::perform(MovieInventory& movies, CustomerInventory& customers)
{
	// check if cusomer exists
	if (!customers.customerExist(customerID))
	{
		cout << "ERROR: History Transaction Failed -- "
			<< "Customer " << customerID << " does not exist" << endl;
		return false;
	}

	// display customer's history
	Customer* c = customers.getCustomer(customerID);
	c -> displayHistory();
	return true;

}
