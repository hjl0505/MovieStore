// Borrow.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Borrow Transaction
// ----------------------------------------------------------------------------
// Sub class of Transaction
// subtracts 1 stock from the Movie in MovieInventory.
// ----------------------------------------------------------------------------

#include "Borrow.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

Borrow::Borrow(int id, Movie* m)
{
	customerID = id;
	movie = m;
}

Borrow::~Borrow()
{
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

int Borrow::getCustomerID()
{
	return customerID;
}


bool Borrow::perform(MovieInventory& movies, CustomerInventory& customers)
{
 	// check if customer exists
	if (!customers.customerExist(customerID))
	{
		cout << "ERROR: Borrow Transaction Failed -- " 
			<< "Customer " << customerID << " does not exist" << endl;
		return false;
	}
	
	Customer* customer = customers.getCustomer(customerID);
	if (movie != NULL)
	{
		// movie exists in the stock
		if (movies.movieExist(movie))
		{		
			string movieInfo = "";
			// There was enough stock of movie to borrow from
			if (movies.borrowMovie(movie, movieInfo)) 
			{		
				// update summary of transaction if borrow performed correctly
				string borrowSummary = "Borrowed " + movieInfo;
				
				// add transaction summary to customer's history
				//customer -> addCheckedOut(*movie);
 				//customer -> addCheckedOut(movie);
				customer -> addHistory(borrowSummary); 

				return true;
			} 
			else
			{		
				cout << "ERROR: Borrow Transaction Failed -- " 
					<< "Not enough in the Stock" << endl;
			}
		}
	}
	else
	{
		cout << "ERROR: Borrow Transaction Failed -- " 
			<< "Movie does not Exist in the Inventory" << endl;
	}
	return false; 
			
}
