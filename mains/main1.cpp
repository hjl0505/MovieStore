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

#include <iostream>
#include <fstream>
//#include "Comedy.h" // (Movie) Store class
using namespace std;

int main()
{
	/*
	ifstream customerFile("Store/data4customers.txt");
	ifstream movieFile("Store/data4movies.txt");
	ifstream transactionFile("Store/data4commands.txt");
	
	if (!customerFile)  // repeat for movieFile and transactionFile
		cout << "Customer file cannot be oppened" << endl;
	if (!movieFile)  // repeat for movieFile and transactionFile
		cout << "Movie file cannot be oppened" << endl;
	if (!transactionFile)  // repeat for movieFile and transactionFile
		cout << "Transaction file cannot be oppened" << endl;

	Store movieStore; //create a store
 	//movieStore.readCustomerFile(customerFile); //create customer profiles from file
	//movieStore.readMovieFile(movieFile); //create movie inventory from file
	//movieStore.readTransactionFile(transactionFile); //process transactions from file
     */
    
    Comedy playTime('C', 'D', "Play Time", "Jacques Tati", 5, 1968);
    comedy.display();
    cout << endl;
    
    Classic classic('C', 'B', "The Leopard", "Luchino Visconti", 10, 1963, 7, "Alain Delon");
    classic.display();
    
    Comedy holyGrail('C', 'D', "Monty Python and the Holy Grail", "Terry Gilliam and Terry Jones", 5, 1975);
    holyGrail.display();
    cout << endl;
    
    if (playTime != holyGrail)
    {
        cout << "Play Time is not equal to Holy Grail" << endl;
    }

    
    
    
	 
	return 0;
}