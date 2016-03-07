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
#include "Comedy.h" // (Movie) Store class
#include "Classic.h"
#include "Drama.h"
using namespace std;

int main()
{
    Comedy playTime('C', 'D', "Play Time", "Jacques Tati", 5, 1968);
    playTime.display();
    cout << endl;

    Classic leopard('C', 'B', "The Leopard", "Luchino Visconti", 10, 1963, 7, "Alain Delon");
    leopard.display();
    cout << endl;

    Comedy holyGrail('C', 'D', "Monty Python and the Holy Grail", "Terry Gilliam and Terry Jones", 5, 1975);
    holyGrail.display();
    cout << endl;
    
    Drama socialNetwork('D', 'B', "The Social Network", "David Fincher", 7, 2010);
    socialNetwork.display();
    cout << endl;

    if (playTime != holyGrail)
    {
        cout << "Play Time is not equal to Holy Grail" << endl;
    }





	return 0;
}
