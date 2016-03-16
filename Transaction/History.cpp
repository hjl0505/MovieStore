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

//Default Constructor
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

//Get Customer ID
//Returns customer ID
int History::getCustomerID()
{
	return customerID;
}

//Perform
//Returns true if history was perfomred successfully
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
