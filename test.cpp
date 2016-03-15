
#include <iostream>
#include <fstream>
#include "Store/Store.h"

using namespace std;

int main()
{
	
	ifstream customerFile("Store/data4customers.txt");
	//ifstream movieFile("Store/movieShort.txt");
	ifstream movieFile("Store/data4movies.txt");
	ifstream transactionFile("Store/commandShort.txt");
	//ifstream transactionFile("Store/data4commands.txt");

	if (!customerFile)  // repeat for movieFile and transactionFile
		cout << "Customer file cannot be oppened" << endl;
	if (!movieFile)  // repeat for movieFile and transactionFile
		cout << "Movie file cannot be oppened" << endl;
	if (!transactionFile)  // repeat for movieFile and transactionFile
		cout << "Transaction file cannot be oppened" << endl;

	Store movieStore; //create a store
 	movieStore.readCustomerFile(customerFile); //create customer profiles from file
	movieStore.readMovieFile(movieFile); //create movie inventory from file
	movieStore.readTransactionFile(transactionFile); //process transactions from file
	
	
	//Movie* C = new Drama('D', 'D', "titleC", "directorC", 0, 0);
	//Movie* B = new Comedy('F', 'D', "titleB", "", 0, 4534);
	//Movie* A = new Classic('C', 'D', "", "", 2, 1231, 1, "actorName");

	
/* 	Movie* D = new Movie();
	*D = *C;
	delete C;
	D -> display();
	delete D; */
	
/*   	MovieInventory MI;
	CustomerInventory CI;
 	Movie* clock = new Classic ('C', 'D', "clockwork", "director", 2, 1231, 1, "jin");
	Movie* clock1 = new Classic ('C', 'D', "clockwork apple", "director", 1, 1231, 1, "jin");
	Movie* clock2 = new Classic ('C', 'D', "clockwork orange", "director", 2, 1230, 1, "jin");
	Movie* C = new Drama('D', 'D', "titleC", "directorC", 0, 0);
	Movie* B = new Comedy('F', 'D', "titleB", "", 0, 4534);
	Movie* A = new Classic('C', 'D', "", "", 2, 1231, 1, "actorName");
 	
	MI.addMovie(clock);
	MI.addMovie(clock1);
	MI.addMovie(clock2);   
	MI.addMovie(C);  
	MI.addMovie(B);  
	MI.addMovie(A);  
	
	delete clock1; 
	 */
	 
	//Movie* movie = new Movie('C', 'D', "title", "director", 5, 1231);
	//TransactionFactory TF;
	//Transaction* borrow = TF.create('B', 5555, movie); 
  	//Transaction* history = TF.create('H', 5555, movie);
	//Transaction* inventory = TF.create('I', 5555, movie);
	//Transaction* returntrans = TF.create('R', 5555, movie); 
	//Transaction* errorT = TF.create('q', 5555, movie);
	
	//delete borrow;
 	//delete history;
	//delete inventory;
	//delete returntrans;
	
/* 	delete clock;
	delete clock1;
	delete clock2; */
	

	return 0;
}