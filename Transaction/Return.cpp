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

Return::Return(int id, Movie* m)
{
	movie = m;
	customerID = id;
}

Return::~Return()
{
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

int Return::getCustomerID()
{
	return customerID;
}


bool Return::perform(MovieInventory& movies, CustomerInventory& customers)
{

 	// check if customer exists
	if (!customers.customerExist(customerID))
	{
		cout << "ERROR: Return Transaction Failed -- " 
			<< "Customer " << customerID << " does not exist" << endl;
		delete movie;
		movie = NULL;
		return false;
	}
	
	Customer* customer = customers.getCustomer(customerID);
	
	if (movie != NULL)
	{
	
		// Check customer's list of movies checked out
		// remove from the list if it exists
		bool checkHistory = customer -> removeCheckedOut(movie);

		// movie was checked out by the customer
		if (checkHistory) 
		{
			// movie exists in the stock
			if (movies.movieExist(movie))
			{		
 				string movieInfo = "";
 				movies.returnMovie(movie, movieInfo);
				
				// update summary of transaction if borrow performed correctly
				string returnSummary = "Returned " + movieInfo;
				customer -> addHistory(returnSummary); 
				return true; 
			}
			else
			{
				cout << "ERROR: Return Transaction Failed -- " 
					<< "Movie does not Exist in the Inventory" << endl;
			}
				
		}
		else
		{
			cout << "ERROR: Return Transaction Failed -- ";
			cout << "Movie was Not Checked Out By the Customer" << endl;
		}
	}
	return false; 
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
