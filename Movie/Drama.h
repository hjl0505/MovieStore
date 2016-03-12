// Drama.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Sub class of Movie, Drama
// ----------------------------------------------------------------------------
// Inherits methods from the Movie object
// Contains overriden display method
// ----------------------------------------------------------------------------

#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"
using namespace std;

class Drama : public Movie
{

public:
	Drama();
	Drama(char genre, char mediaType, string title, string director,
		 int stock, int yearRelease);
	~Drama();
	
	virtual bool operator==(const Movie& otherMovie) const; // check if movies are equal
	//virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
	virtual bool operator > (const Movie& otherMovie) const; // check if this movie is greater than rhs movie
	virtual bool operator < (const Movie& otherMovie) const; // check if this movie is less than rhs movie
	
};
#endif
