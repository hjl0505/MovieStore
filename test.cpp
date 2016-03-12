
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
	//movieStore.readTransactionFile(transactionFile); //process transactions from file 

	

 	Movie* movie = new Movie('C', 'D', "title", "director", 5, 1231);
	//cout << movie -> getGenre() << endl;
	Movie* movieD = new Drama('D', 'D', "titleD", "directorD", 53, 1212);
	//cout << movieD -> getGenre() << endl; 
	Movie* movieA = new Classic('C', 'D', "titleA", "directorA", 2, 1231, 1, "actorName");
	Movie* movieB = new Comedy('F', 'D', "titleB", "directorB", 34, 4534);
	Movie* movieC = new Drama('D', 'D', "titleC", "directorC", 23, 1753);
	
/* 	CustomerInventory CI;
 	CI.getCustomer(0);
	cout << "exist " << CI.customerExist(0) << endl;
	CI.addCustomer(9999, "jin", "lee");
	cout << "exist " << CI.customerExist(9999) << endl;  */
	
 	Customer c(5, "jin", "lee");
/* 	c.display();
	cout << c.getID() << endl;
	cout << c.getName() << endl;
	c.displayHistory();
	c.addHistory("some transaction");
	c.addHistory("some other transaction");
	c.addHistory("most recent transaction");
	c.displayHistory();  */
		
	Movie* C = new Drama('D', 'D', "titleC", "directorC", 0, 0);
	Movie* B = new Comedy('F', 'D', "titleB", "", 0, 4534);
	Movie* A = new Classic('C', 'D', "", "", 2, 1231, 1, "actorName");
	c.addCheckedOut(movieC);
	//c.addCheckedOut(movieA);
	//c.addCheckedOut(movieB);
	cout << "Removing drama movie: 1 = " << c.removeCheckedOut(C) << endl;
	cout << "Removing drama movie again: 1 = " << c.removeCheckedOut(C) << endl;
	//cout << "Removing classic movie: 1 = " << c.removeCheckedOut(A) << endl;
	
	cout << endl;
	cout << (C == movieC) << endl;
	cout << (B == movieB) << endl;
	cout << (A == movieA) << endl;
	
	
/* 	Movie* movieC = new Classic ('C', 'D', "title", "diretor", 10, 2342, 2, "actor name");
	movieC -> display();
	cout << endl;
	
	MovieFactory movieFact;
	Movie movieC2 = movieFact.create('C', " title", "direcot", "actor", 4, 2343, 20);
	movieC2.display();
	cout << endl;
	 */
	 
/* 	Classic* clock = new Classic ('C', 'D', "clockwork orange", "director", 5, 1231, 1, "jin");
	clock -> addActor("derek", 20);
	cout << clock -> actorExists("derek") << endl;
	clock -> display(); */
	
	return 0;
}