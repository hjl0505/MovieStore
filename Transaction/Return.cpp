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

//Default Constructor
Return::Return(int id, Movie* m)
{
	movie = m;
	customerID = id;
}

//Destructor
//No dynamic memory allocated
Return::~Return()
{
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Get Customer ID
//Returns the customer ID
int Return::getCustomerID()
{
	return customerID;
}

//Perform
//Returns true if return is performed successfully
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


		// movie exists in the stock
		if (movies.movieExist(movie))
		{

			// Check customer's list of movies checked out
			// remove from the list if it exists
			bool checkHistory = customer -> removeCheckedOut(movie);

			// movie was checked out by the customer
			if (checkHistory)
			{
					string movieInfo = "";
					movies.returnMovie(movie, movieInfo);

					// update summary of transaction if borrow performed correctly
					string returnSummary = "Returned " + movieInfo;
					customer -> addHistory(returnSummary);

					delete movie;
					movie = NULL;
					return true;
			}
			else
			{
				cout << "ERROR: Return Transaction Failed -- ";
				cout << "Movie was Not Checked Out By the Customer" << endl;
			}
		}
		else
		{
			cout << "ERROR: Return Transaction Failed -- "
				<< "Movie does not Exist in the Inventory" << endl;
		}

	}

	delete movie;
	movie = NULL;
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
