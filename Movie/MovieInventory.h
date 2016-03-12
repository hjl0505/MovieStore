// MovieInventory.h---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Holds inventory of the movies.
// ----------------------------------------------------------------------------
// This class keeps track of all the movies the store owns
// in an array of binary search trees.
// ----------------------------------------------------------------------------

#ifndef MOVIEINVENTORY_H
#define MOVIEINVENTORY_H

#include <vector> 
#include "Movie.h"
#include "BST.h"

class MovieInventory
{

public:

	MovieInventory();
	~MovieInventory();

	Movie* getMovie (Movie*); // retrieves movie equal to the parameter movie
	bool movieExist (Movie*); // checks if movie exists
	void printInventory(); // print all the movies in the stock

	bool addMovie (Movie*); // add new movie
	bool borrowMovie (Movie*, string&); // borrow a movie, and updates string with movie info
	bool returnMovie (Movie*); // return a movie

private:
	vector<BST> movieType; // array of BSTs there are 3 for each genre of movies
							// idx 0 for comedy, 1 for drama, 2 for classic
};
#endif
