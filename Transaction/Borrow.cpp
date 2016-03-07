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
	delete movie;
	movie = NULL;
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
	if (customers.customerExist(customerID));
	{
		cout << "Borrow Transaction Failed" << endl;
		cout << "Customer does not exist" << endl;
		return false;
	}
	
	Customer* customer = customers.getCustomer(customerID);
	
	// movie exists in the stock
	if (movies.movieExist(movie))
	{		
		// There was enough stock of movie to borrow from
		if (movies.borrowMovie(movie)) {
			
			// update summary of transaction if borrow performed correctly
			string borrowSummary = "Borrow "; //+ movie -> getMovieInfo();
			Transaction::setSummary(borrowSummary);
			
			customer -> addCheckedOut (movie);
			customer -> addHistory(borrowSummary);
			
		} 
		else
		{
			cout << "Borrow Transaction Failed" << endl;
			cout << "Not enough in the Stock" << endl;
		}
	}
	else
	{
		cout << "Borrow Transaction Failed" << endl;
		cout << "Movie does not Exist in the Inventory" << endl;
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
