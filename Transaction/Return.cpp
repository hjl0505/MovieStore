// Return.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Return Transaction
// ----------------------------------------------------------------------------
// Sub class of Transaction
// adds 1 stock from the Movie in MovieInventory.
// ----------------------------------------------------------------------------

#include "Return.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

Return::Return()
{

}

Return::~Return()
{

}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

int Return::getCustomerID()
{

}


void Return::perform(MovieInventory& movies, CustomerInventory& customers)
{

	// check if customer exists
	if (customers.customerExist(customerID));
	{
		cout << "Return Transaction Failed" << endl;
		cout << "Return does not exist" << endl;
		return false;
	}
	
	Customer* customer = customers.getCustomer(customerID);
	
	// Check customer's list of movies checked out
	// remove from the list if it exists
	bool checkHistory = customer -> removeCheckedOut(movie);
	
	// movie was checked out by the customer
	if (checkHistory) 
	{
		// movie exists in the stock
		if (movies.movieExist(movie))
		{		
				movies.returnMovie(movie);
				
				// update summary of transaction if borrow performed correctly
				summary = "Return " + returnMovie.display();
				Transaction:setSummary(summary);
				
				customer -> addHistory(summary);
		}
		else
		{
			cout << "Return Transaction Failed" << endl;
			cout << "Movie does not Exist in the Inventory" << endl;
		}
			
	}
	else
	{
		cout << "Borrow Transaction Failed" << endl;
		cout << "Movie was Not Checked Out By the Customer" << endl;
	}
	
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
