// Store.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Store class holds the business logic for the inventory system
// ----------------------------------------------------------------------------
// The essential business logic is the performTransaction method
// which performs either borrowing or returning a movie,
// printing inventory of all the items,
// and printing transaction history of a customer.
// performTransaction also checks for bad inputs from the input file.
// ----------------------------------------------------------------------------

#include "Store.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

Store::Store()
{
}


Store::~Store()
{	
}	
	

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

bool Store::readCustomerFile (ifstream& in)
{
	// variables for customer
	int id;
	string firstName;
	string lastName;
	
	// read file by line
	string line;
	getline(in,line);
		
	while(!in.eof())
	{		
		// read string as input
		stringstream readLine(line);
		readLine >> id;
		readLine >> firstName;
		readLine >> lastName;
		
		customerTable.addCustomer(id, firstName, lastName); 
		
		// read file by line
		getline(in,line);
	}
}


bool Store::readMovieFile (ifstream& in)
{
}


bool Store::readTransactionFile (ifstream& in) 
{

}


bool Store::performTransaction (Transaction* t)
{
	t -> perform(movieTree, customerTable);
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
