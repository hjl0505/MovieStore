
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

	
	return 0;
}