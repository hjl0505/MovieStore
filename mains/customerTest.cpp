#include "Customer/CustomerInventory.h"
#include <iostream>
using namespace std;

int main() {
	Customer a;
	Customer b(10, "bob", "smith");
	
	a.display();
	b.display();
	
	a.addHistory("history1");
	a.addHistory("history2");
	a.addHistory("history3");
	a.addHistory("history4");
	a.displayHistory();
	
	return 0;
}