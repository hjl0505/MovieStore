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

void Store::readCustomerFile (ifstream& in)
{
	// variables for customer
	int id;
	string firstName, lastName;
	
	// read file by line
	string line;
	getline(in,line);
		
	while(!in.eof())
	{		
		// read string as input
		stringstream readLine(line);
		readLine >> id;
		readLine >> lastName;
		readLine >> firstName;
		
		// add new customer to customer hash table
		customerTable.addCustomer(id, firstName, lastName); 
				
		// read file by line
		getline(in,line);
	}
}


void Store::readMovieFile (ifstream& in)
{
	// variables for movie
	char genre = 'Z';
	int stock = 0;
	int month = 0;
	int year = 0;
	string director, title, actor;
	
	// read file by line
	string line;
	getline(in, line);
	
	while(!in.eof())
	{
		stringstream readLine(line);
		string temp;
		
		readLine >> temp; // temporary string including commas
		genre = temp[0]; // get first character as genre
		readLine >> stock; 
		readLine >> temp; // read over the ','
		director = readStringStream(readLine); 
		title = readStringStream(readLine); 
		
 		// read classics actor and month
		if (genre == 'C')
		{
 			readLine >> actor >> temp;			
			actor = actor + " " + temp;
			readLine >> temp;
			istringstream(temp) >> month;			
		} 
		readLine >> year; // read year
		
		// Create movie and add to the movieTree
 		Movie* newMovie = movieFactory.create(genre, title, director, actor, month, year, stock);
		if(!movieTree.addMovie(newMovie))
			delete newMovie; 
		
		// reset variables
		title = "";
		director = "";
		actor = "";
		genre = 'Z';
		stock = 0;
		year = 0;
		month = 0;	
		
		// read file by line
		getline(in,line);
	}
}


void Store::readTransactionFile (ifstream& in) 
{
	// variables for transaction and movie
	char transType, mediaType, genre;
	int id, month, year;
	string actor, director, title, temp;
	Movie* movie = NULL;
	Transaction* newTrans = NULL;
	
	// read file by line
	string line;
	getline(in, line);
	
	while(!in.eof())
	{
		stringstream readLine(line);
		readLine >> transType; // read transaction type
		
		// continue reading for history, borrow and return transactions
		if(transType != 'I') 
		{
			readLine >> id;
			
			// continue reading for borrow and return transactions
			if(transType != 'H') 
			{	
				readLine >> mediaType;
				if (mediaType != 'D') // invalid media type
					cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
				else 
				{
					readLine >> genre;
					switch (genre)
					{
						case 'C': // classics
							readLine >> month >> year;
							actor = readStringStreamClassic(readLine);
							break;
						case 'D': // drama
							director = readStringStream(readLine);
							title = readStringStream(readLine);	
							break;
						case 'F': // comedy
							title = readStringStream(readLine);
							readLine >> year;
							break;
					}
					// create new movie
					movie = movieFactory.create(genre, title, director, actor, month, year, 0);
				}
			}
		}
		
		//create new transaction and perform
		newTrans = transFactory.create(transType, id, movie);			
		performTransaction(newTrans);
		delete newTrans;
		delete movie;
		
		
		
		// reset variables
		title = "";
		director = "";
		actor = "";
		genre = 'Z';
		year = 0;
		month = 0;	
		newTrans = NULL;
		movie = NULL;
		
		// read file by line
		getline(in,line);
	}
}


bool Store::performTransaction (Transaction* t)
{
	if (t != NULL)
		return (t -> perform(movieTree, customerTable));
	return false;
}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

// read part of the string stream and 
// return group of words that are separated by comma
string Store::readStringStream (stringstream& in)
{
	string words, temp;
	in >> words;
	
	// read string stream until last character is a comma
	while(words[words.length() - 1] != ',') 
	{
		in >> temp;
		words = words + " " + temp;
	}
	
	// remove the last comma character
	if (words[words.length() - 1] == ',')
		words = words.substr(0, words.length() - 1);	
	
	return words;
}

// read part of the string stream and 
// return group of words read until end of file
string Store::readStringStreamClassic (stringstream& in)
{
	string words, temp;
	in >> words;
	in >> temp;
	
	// read string stream until end of stream
	while(!in.eof()) 
	{
		words = words + " " + temp;
		in >> temp;
	}
	
	return words;
}