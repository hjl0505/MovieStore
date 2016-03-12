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
#include "Comedy.h"
#include "Classic.h"
#include "Drama.h"
#include "MovieInventory.h"
#include "MovieFactory.h"
using namespace std;

int main()
{
    MovieInventory store;
    MovieFactory factory;

    Movie* playTime = factory.create('F', "Play Time", "Jacques Tati", "", -1, 1968, 10);

    Movie* leopard = factory.create('C', "The Leopard", "Luchino Visconti", "Alain Delon", 10, 1963, 10);

    Movie* leopard2 = factory.create('C', "The Leopard", "Luchino Visconti", "Claudia Cardinale", 10, 1963, 10);

    Movie* leopard3 = factory.create('C', "The Leopard", "Luchino Visconti", "Burt Lancaster", 10, 1963, 10);

    Movie* holyGrail = factory.create('F', "Monty Python and the Holy Grail", "Terry Gilliam and Terry Jones", "", -1, 1975, 10);

    Movie* socialNetwork = factory.create('D', "The Social Network", "David Fincher", "", -1, 2010, 10);


    store.addMovie(playTime);
    store.addMovie(leopard);
    store.addMovie(leopard2);
    store.addMovie(leopard3);
    store.addMovie(holyGrail);
    store.addMovie(socialNetwork);

    cout << store.getMovie(leopard)->getActor() << endl;
    
    store.printInventory();


	return 0;
}



/*
 MovieInventory store;

 Movie* playTime;
 playTime = new Comedy('F', 'D', "Play Time", "Jacques Tati", 5, 1968);

 Movie* leopard;
 leopard = new Classic('C', 'B', "The Leopard", "Luchino Visconti", 10, 1963, 7, "Alain Delon");

 Movie* holyGrail;
 holyGrail = new Comedy('F', 'D', "Monty Python and the Holy Grail", "Terry Gilliam and Terry Jones", 5, 1975);

 Movie* socialNetwork;
 socialNetwork = new Drama('D', 'B', "The Social Network", "David Fincher", 7, 2010);

 store.addMovie(playTime);
 store.addMovie(leopard);
 store.addMovie(holyGrail);
 store.addMovie(socialNetwork);

 store.printInventory();
 */
