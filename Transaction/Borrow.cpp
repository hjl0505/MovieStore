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

//Input Constructor
//Initialize customer and movie for borrow
Borrow::Borrow(int id, Movie* m)
{
	customerID = id;
	movie = m;
}

//Default Destructor
//No dynamic memory allocated
Borrow::~Borrow()
{
	
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Perform
//Returns true if borrow was performed successfully
bool Borrow::perform(MovieInventory& movies, CustomerInventory& customers)
{
 	// check if customer exists
	if (!customers.customerExist(customerID))
	{
		cout << "ERROR: Borrow Transaction Failed -- "
			<< "Customer " << customerID << " does not exist" << endl;

		// delete movie ptr after failed borrow transaction
		delete movie;
		movie = NULL;
		
		return false;
	}

	Customer* customer = customers.getCustomer(customerID);
	if (movie != NULL)
	{
		// check if movie exists in the stock
		if (movies.movieExist(movie))
		{
			string movieInfo = "";

			// check if enough stock of movie to borrow from
			if (movies.borrowMovie(movie, movieInfo))
			{
				// update summary of transaction if borrow performed correctly
				string borrowSummary = "Borrowed " + movieInfo;

				// add transaction summary to customer's history
 				customer -> addCheckedOut(movie);
				customer -> addHistory(borrowSummary);
				return true;
			}
			else
			{
				cout << "ERROR: Borrow Transaction Failed -- "
					<< "Not enough in the Stock" << endl;
			}
		}
		else
		{
			cout << "ERROR: Borrow Transaction Failed -- "
				<< "Movie does not Exist in the Inventory" << endl;
		}
	}

	// delete movie ptr after failed borrow transaction
	delete movie;
	movie = NULL;
	
	return false;

}
