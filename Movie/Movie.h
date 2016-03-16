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
#include <iomanip> // formatting output
//#include <string>
using namespace std;

class Movie
{

public:

	// Constructor and Destructor
	Movie();
    Movie(char, char, string, string, int, int); // genre, mediatype, title, director, stock, year released
	virtual ~Movie();

	// Overloaded operators
 	virtual bool operator==(const Movie& otherMovie) const; // check if movies are equal
	virtual bool operator != (const Movie& otherMovie) const; // check if movies are not equal
	virtual bool operator > (const Movie& otherMovie) const; // check if this movie is greater than other movie
	virtual bool operator < (const Movie& otherMovie) const; // check if this movie is less than other movie
	
	// Accessors
	char getGenre() const; 
	char getMediaType() const;
	string getTitle() const;
	string getDirector() const;
	int getStock() const;
	int getYearReleased() const;
	bool getCountedStatus() const;
	virtual string getActor() const;
	virtual int getMonth() const;
	
	virtual void display() const; // print out movie data and return string
    string getMovieInfo() const; //returns string of movie data variables

	// Mutators
	bool addToStock(int); // add to stock
	virtual bool subtractFromStock(int); // subtract from stock
	void setCounted(bool); // mark movie as counted in inventory
	virtual void addSameMovies(Movie*&); // add the same movie to the list of same movies

protected:
	char genre; // genre of the movie
	char mediaType; // media type of the movie
	string title; // title of movie
	string director; // director of movie
	int stock; // number of movie left in stock
	int yearReleased; // year released
	bool counted; // keeps track of inventory status of the movie
};
#endif
