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

History::History(int id)
{
	customerID = id;
}

History::~History()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

int History::getCustomerID()
{
	return customerID;
}

bool History::perform(MovieInventory& movies, CustomerInventory& customers)
{
	if (!customers.customerExist(customerID))
	{
		cout << "ERROR: History Transaction Failed -- " 
			<< "Customer " << customerID << " does not exist" << endl;
		return false;
	}
	
	Customer* c = customers.getCustomer(customerID);
	c -> displayHistory();
	return true;
	
}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

//////////////////////////////////////////////////
//////////     Operator Overloads   //////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////    I/O Stream   ///////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
//////////////   Extra Code   ////////////////////
//////////////////////////////////////////////////
