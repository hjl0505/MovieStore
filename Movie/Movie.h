// Movie.h--------------------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Super class of Movie. Abstract base class.
// ----------------------------------------------------------------------------
// Stores data for each movie in the store
// It tracks the current amount of in stock movies for
// each movie, the media type, director, year released, title, and movie code.
// It has functions to add and remove from the movie stock compare movies,
// ----------------------------------------------------------------------------

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream> // input and output
#include <string>
using namespace std;

class Movie
{

public:
	Movie();
    Movie(char genre, char mediaType, string title, string director, int stock, int yearReleased);
	virtual ~Movie();

 	virtual bool operator==(const Movie& otherMovie) const; // check if movies are equal
	virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
	virtual bool operator > (const Movie& otherMovie) const; // check if this movie is greater than rhs movie
	virtual bool operator < (const Movie& otherMovie) const; // check if this movie is less than rhs movie
	virtual Movie& operator=(const Movie& source); // assignment operator

	virtual void display() const; // print out movie data and return string
    virtual string getMovieInfo() const; //returns string of movie data variables

	// Get methods
	char getGenre() const;
	char getMediaType() const;
	string getTitle() const;
	string getDirector() const;
	int getStock() const;
	int getYearReleased() const;
	virtual string getActor() const;
	virtual int getMonth() const;

	bool addToStock(); // add to stock by 1
	bool subtractFromStock(); // subtract from stock by 1

protected:
	char genre; // genre of the movie
	char mediaType; // media type of the movie
	string title; // title of movie
	string director; // director of movie
	int stock; // number of movie left in stock
	int yearReleased; // year released
};
#endif
