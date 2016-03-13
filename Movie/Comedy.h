// Comedy.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Sub class of Movie, Comedy
// ----------------------------------------------------------------------------
// Inherits methods from the Movie object
// Contains overriden display method
// ----------------------------------------------------------------------------

#ifndef COMEDY_H
#define COMEDY_H

#include "Movie.h"
using namespace std;

class Comedy : public Movie
{

public:
	// Constructor and Destructor
    Comedy(char genre, char mediaType, string title, string director,
		 int stock, int yearRelease);
	~Comedy();
	
	// Overloaded operators
	virtual bool operator==(const Movie& otherMovie) const; // check if movies are equal
	virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
	virtual bool operator > (const Movie& otherMovie) const; // check if this movie is greater than other movie
	virtual bool operator < (const Movie& otherMovie) const; // check if this movie is less than other movie
};
#endif
