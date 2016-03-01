// main.cpp--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Automated inventory tracking system for a local movie rental store
// ----------------------------------------------------------------------------
// The system has two inventory systems that keep track of movies and customers
// It also performs transactions such as borrow, return, iventory, and history
// ----------------------------------------------------------------------------

#include "Store/Store.h" // (Movie) Store class

int main() {
	
	ifstream customerFile (“Store/data4customers.txt”);
	ifstream movieFile(“Store/data4movies.txt”);
	ifstream transactionFile(“Store/data4commands.txt”);
	
	if (!customerFile)  // repeat for movieFile and transactionFile
		cout << error message;

	Store movieStore; //create a store
	movieStore.readCustomerFile (ifstream customerFile); //create customer profiles from file
	movieStore.readMovieFile (ifstream movieFile); //create movie inventory from file
	movieStore.readTransactionFile (ifstream transactionFile); //process transactions from file
	
	return 0;
}