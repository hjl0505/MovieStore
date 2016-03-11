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
	// variables for movie
	char type;
	int stock;
	string director;
	string title;
	string actor = "";
	int month = 0;
	int year;
	
	string line;
	getline(in, line);
	
	while(!in.eof())
	{
		stringstream readLine(line);
		string temp;
		
		readLine >> temp; // temporary string including commas
		type = temp[0]; // read type
		readLine >> stock; // read stock
		
		// ',' as temp and first part of director
		readLine >> temp >> director; 
		
		// read director until next ','
		while(director[director.length() - 1] != ',') 
		{
			readLine >> temp;
			director = director + " " + temp;
		}
		director = director.substr(0, director.length() - 1);

		// read title until next ','
		readLine >> title;
		while(title[title.length() - 1] != ',') 
		{
			readLine >> temp;
			title = title + " " + temp;
		}
		title = title.substr(0, title.length() - 1);
		
 		// read classics actor and month
		if (type == 'C')
		{
 			readLine >> actor >> temp;
			while (!isdigit(temp[0]))
			{
				actor = actor + " " + temp;
				readLine >> temp;
			} 
			istringstream(temp) >> month;
			
		} 
		
		// read year
		readLine >> year;
		
		Movie* newMovie = movieFactory.create(type, title, director, actor, month, year, stock);
		//movieTree.addMovie(newMovie);
			
		actor = "";
		month = 0;		
		getline(in,line);
	}
	
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
