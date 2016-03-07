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

#ifndef CLASSIC_H
#define CLASSIC_H

#include "Movie.h"
using namespace std;

class Classic : public Movie
{

public:
	Classic();
	Classic(int monthReleased, string actor);
	~Classic();

	virtual bool operator == (const Movie&); // check if movies are equal
	virtual bool operator != (const Movie&); // check if movies are not equal
	virtual bool operator > (const Movie&); // check if this movie is greater than rhs movie
	virtual bool operator < (const Movie&); // check if this movie is less than rhs movie
	virtual const Movie &operator=(const Movie&); // assign this movie to rhs

	virtual string display(); // print out movie data and return string

	// get methods
	int getMonth();
	string getActor();

private:
	int monthReleased; // month of the movie release
	string actor; // major actor of the movie
};
#endif
