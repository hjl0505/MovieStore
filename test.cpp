
#include <iostream>
#include <fstream>
#include "Store/Store.h"

using namespace std;

int main()
{
	
	ifstream customerFile("Store/data4customers.txt");
	ifstream movieFile("Store/data4movies.txt");
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
	
	
	

/* 	Movie* movie = new Movie('C', 'D', "title", "director", 5, 1231);
	cout << movie -> getGenre() << endl;
	Movie* movied = new Drama('D', 'D', "titleD", "directorD", 53, 1212);
	cout << movied -> getGenre() << endl; */
	
/* 	CustomerInventory CI;
 	CI.getCustomer(0);
	cout << "exist " << CI.customerExist(0) << endl;
	CI.addCustomer(9999, "jin", "lee");
	cout << "exist " << CI.customerExist(9999) << endl;  */
	
/* 	Customer c(5, "jin", "lee");
	c.display();
	cout << c.getID() << endl;
	cout << c.getName() << endl;
	c.displayHistory();
	c.addHistory("some transaction");
	c.addHistory("some other transaction");
	c.addHistory("most recent transaction");
	c.displayHistory(); */
	
/* 	Movie* movieC = new Classic ('C', 'D', "title", "diretor", 10, 2342, 2, "actor name");
	movieC -> display();
	cout << endl;
	
	MovieFactory movieFact;
	Movie movieC2 = movieFact.create('C', " title", "direcot", "actor", 4, 2343, 20);
	movieC2.display();
	cout << endl;
	 */
	
	return 0;
}