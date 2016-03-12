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
	Classic(char genre, char mediaType, string title, string director, int stock, int yearRelease, int monthReleased, string actor);
	~Classic();

	virtual bool operator == (const Movie&) const; // check if movies are equal
	virtual bool operator != (const Classic&) const; // check if movies are not equal
	virtual bool operator > (const Classic&) const; // check if this movie is greater than rhs movie
	virtual bool operator < (const Classic&) const; // check if this movie is less than rhs movie
	virtual Classic& operator=(const Classic&); // assign this movie to rhs

	virtual void display() const; // print out movie data and return string
    virtual string getMovieInfo() const; //returns string of movie data variables

	// get methods
	virtual int getMonth() const;
	virtual string getActor() const;

private:
	int monthReleased; // month of the movie release
	string actor; // major actor of the movie
};
#endif
