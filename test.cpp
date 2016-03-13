
#include <iostream>
#include <fstream>
#include "Store/Store.h"

using namespace std;

int main()
{
	
	ifstream customerFile("Store/data4customers.txt");
	ifstream movieFile("Store/movieShort.txt");
	ifstream transactionFile("Store/commandShort.txt");
	
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
	

/* 	MovieInventory MI;
	CustomerInventory CI;
	
 	MovieFactory MF;
	//Movie* C = MF.create('C', "classic movie" , "directorC", "actorC", 1, 1999, 3);
	Movie* D = MF.create('D', "Drama movie" , "directorD", "actorD", 13, 1999, 43);
	Movie* D2 = MF.create('D', "Drama movie2" , "directorD2", "actorD2", 132, 19992, 432);
	//Movie* F = MF.create('F', "Comedy movie" , "directorF", "actorF", 11, 1999, 23);
	//C -> display();
	cout << endl;
	D -> display();
	cout << endl;
	//F -> display();
	//cout << endl;
	
	MI.addMovie(D);
	MI.addMovie(D2);
	
	
	//delete C;
	delete D;
	delete D2;
	//delete F; 
	 */
	 
	// Movie* movie = new Classic ('F', 'D', "Comedy movie" , "directorF", 11, 1999, 2, "poopers");
	// Movie* movie1 = new Classic ('F', 'D', "Comedy movie" , "directorG", 11, 2343, 2, "poopers" );
	// Movie* movie2 = new Classic ('F', 'D', "Comedy movie" , "directorF", 11, 1999, 2, "poopers");
	// Movie* movie4 = new Classic ('F', 'D', "Comedy movie5" , "directorF", 11, 1999, 2, "pooperscrap");
	// Movie* movie5 = new Classic ('F', 'D', "Comedy movie" , "directorF", 11, 1999, 4, "poopers");
	// Movie* movie3 = movie;
	
	
 	// cout << "0 = " << (*movie == *movie1) << endl;
	// cout << "1 = " << (*movie == *movie2) << endl;
	// cout << "0 = " <<(*movie == *movie4) << endl;
	// cout << "1 = " <<(*movie == *movie3) << endl;
	// cout << "0 = " <<(*movie == *movie5) << endl;
	
	// cout << "0 = " << (*movie > *movie1) << endl;
	// cout << "0 = " <<(*movie > *movie4) << endl;
	// cout << "0 = " <<(*movie > *movie5) << endl;
	// cout << "1 = " << (*movie < *movie1) << endl;
	// cout << "1 = " <<(*movie < *movie4) << endl;
	// cout << "1 = " <<(*movie > *movie5) << endl;
	
	// delete movie;
	// delete movie1;
	// delete movie2;
	// delete movie4; 
	// delete movie5;
	
	// movie->display();
/* 	movie1->display();
	movie2->display();
	movie3->display(); */
	
	 
	 
	return 0;
}