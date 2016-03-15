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
#include <vector> 
#include "Movie.h"
using namespace std;

struct actorNode 
{
	string actor; // major actor of the movie	
	int stock;
	actorNode* next;
};

class Classic : public Movie
{

public:

	// Constructor and Destructor
	Classic(char genre, char mediaType, string title, string director, int stock, int yearRelease, int monthReleased, string actor);
	~Classic();

	// Overloaded operators
	virtual bool operator == (const Movie&) const; // check if movies are equal
	virtual bool operator != (const Movie&) const; // check if movies are not equal
	virtual bool operator > (const Movie&) const; // check if this movie is greater than rhs movie
	virtual bool operator < (const Movie&) const; // check if this movie is less than rhs movie
	virtual Movie& operator=(const Movie& source); // assignment operator

	// Accessor methods
	virtual int getMonth() const;
	virtual void display() const; // print out movie data and return string
	virtual string getActor() const; // get the major actor for the movie
	virtual bool subtractFromStock(int); // subtract from stock
	virtual void addSameMovies(Movie*&); // add the same movie to the list of same movies
	
	int getTotalStock() const; // get total stock of all the same movies

private:	

	vector<Movie*> sameMoviesList;
	string actor;
	int monthReleased; // month of the movie release
};
#endif
