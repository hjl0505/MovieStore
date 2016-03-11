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
		readLine >> lastName;
		readLine >> firstName;
		
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
			while (!isdigit(temp[0]))
			{
				actor = actor + " " + temp;
				readLine >> temp;
			} 
			istringstream(temp) >> month;
			
		} 
		readLine >> year; // read year
		
		// Create movie and add to the movieTree
 		Movie* newMovie = movieFactory.create(genre, title, director, actor, month, year, stock);
		movieTree.addMovie(newMovie); 
	
		
		actor = "";
		month = 0;		
		getline(in,line);
	}
}


void Store::readTransactionFile (ifstream& in) 
{
	char transType, mediaType, genre;
	int id, month, year;
	string actor, director, title, temp;
	Movie* movie = NULL;
	
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
					cout << "Invalid Media Type. Try Again." << endl;
				else 
				{
					readLine >> genre;
					switch (genre)
					{
						case 'C': // classics
							readLine >> month >> year;
							actor = readStringStream(readLine);
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
			
			//create new transaction and perform
			Transaction* newTrans = transFactory.create(transType, id, movie);
			performTransaction(newTrans);
		}
		getline(in,line);
	}
}


bool Store::performTransaction (Transaction* t)
{
	if (t != NULL)
		t -> perform(movieTree, customerTable);
}

//////////////////////////////////////////////////
////////////   Private Methods   /////////////////
//////////////////////////////////////////////////

// read part of the string stream and 
//return words that are separated by comma or end of line
string Store::readStringStream (stringstream& in)
{
	string words, temp;
	in >> words;
	while(words[words.length() - 1] != ',' && !in.eof()) 
	{
		in >> temp;
		words = words + " " + temp;
	}
	
	if (words[words.length() - 1] == ',')
		words = words.substr(0, words.length() - 1);	
	
	return words;
}