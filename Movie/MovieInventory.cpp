// MovieInventory.cpp---------------------------------------------------------
// Hyungjin Lee, Chris Knakal
// CSS 343 HW 4: Movie Store
// 2/29/2016
// ----------------------------------------------------------------------------
// Holds inventory of the movies.
// ----------------------------------------------------------------------------
// This class keeps track of all the movies the store owns
// in an array of binary search trees.
// ----------------------------------------------------------------------------

#include "MovieInventory.h"

//////////////////////////////////////////////////
//////////   Constructors/Destructor   ///////////
//////////////////////////////////////////////////

//Default Constructor
//Initialize 3 BST for each movie genre
MovieInventory::MovieInventory()
{
    BST comedy, classic, drama;
    movieType.push_back(comedy);
    movieType.push_back(classic);
    movieType.push_back(drama);
}

//Destructor
//Delete the dynamic memory allocated by the movieType vector
MovieInventory::~MovieInventory()
{
	movieType.clear();
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

//Get Movie
//Returns a pointer to the movie in the BSTree
Movie* MovieInventory::getMovie (Movie* moviePtr)
{
    Movie *foundPtr = NULL;
    switch (moviePtr->getGenre())
    {
        case 'F': // Comedy
            movieType[0].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;

        case 'C': // Classic
            movieType[1].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;

        case 'D': // Drama
            movieType[2].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;

        default:
            foundPtr = NULL;
            break;
    }
    return foundPtr;
}

//Movie Exists
//Returns true if the movie is in the inventory
bool MovieInventory::movieExist (Movie* moviePtr)
{
	Movie* foundPtr = getMovie(moviePtr);
    if (foundPtr!= NULL)
        return true;
    else
        return false;
}

//Print Inventory
//Displays all the movies in the inventory by genre
//Displays each movie's information
void MovieInventory::printInventory()
{
    for (int i = 0; i < movieType.size(); i++)
    {
		// Print Headers
        cout << "---------------------------" << endl;
        switch (i)
        {
            case 0: // Comedy
                cout << "Comedies:" << endl << endl;
				cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20)
					<< "Director" << setw(7) << "Year" << setw(7) << "Stock" << endl;
                break;

            case 1: // Classic
                cout << "Classics:" << endl << endl;
				cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20)
					<< "Director" << setw(7) << "Month" << setw(7)<< "Year" << setw(7)  << "Stock" << endl;
                break;

            case 2: // Drama
                cout << "Dramas:" << endl << endl;
				cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20)
					<< "Director" << setw(7) << "Year" << setw(7) << "Stock" << endl;
                break;

            default:
                break;
        }
		
		// print movie inventory, then reset movies counted back to false
        cout << movieType[i];
		movieType[i].resetCounted();
    }
}

//Add Movie
//Returns true if the movie was added into the inventory
bool MovieInventory::addMovie (Movie*& moviePtr)
{
	bool success = false;
	if (moviePtr) {
		 switch (moviePtr->getGenre())
		{
			case 'F': // Comedy
				success = movieType[0].addMovie(moviePtr);
				return success;
				break;

			case 'C': // Classic
				success = movieType[1].addMovie(moviePtr);
				if (success) // insert pointers to the same movies with different actors
				{
					moviePtr -> setCounted(true);
					addAllSameMovies(moviePtr, 1);
					movieType[1].resetCounted();
				}
				return success;
				break;

			case 'D': // Drama
				success = movieType[2].addMovie(moviePtr);
				return success;
				break;

			default:
				return success;
				break;
		}
	}
    return success;
}

//Borrow Movie
//Returns true if the movie was able to be borrowed from the inventory
//Subracts one from movie's stock if able to be borrowed
bool MovieInventory::borrowMovie (Movie* moviePtr, string& movieInfo)
{
	bool successful = false;
    if (movieExist(moviePtr))
    {
		Movie* movieToBorrow = getMovie(moviePtr);
		if (movieToBorrow -> subtractFromStock(1)) // borrow movie
		{
			movieInfo = movieToBorrow -> getMovieInfo(); // title and year of the movie borrowed
			successful = true;
		}
    }

	// reset movie counted back to false
	for (int i = 0; i < movieType.size(); i++) 
		movieType[i].resetCounted();

    return successful;
}

//Return Movie
//Returns true if the movie is able to be returned to the inventory
//Adds one to the movies stock if able to be returned
bool MovieInventory::returnMovie (Movie* moviePtr, string& movieInfo)
{
    if (movieExist(moviePtr))
    {
		Movie* movieToReturn = getMovie(moviePtr);
        movieToReturn->addToStock(1); // return movie

		movieInfo = movieToReturn -> getMovieInfo(); // title and year of the movie borrowed
        return true;
    }
    else
        return false;
}

//Get Movie By Title
//Returns movie pointer to the movie in the BSTree/Inventory
Movie* MovieInventory::getMovieByTitle (int genreIndex, string title, int year)
{
	Movie* found = NULL;
	movieType[genreIndex].getMovieByTitle(title, year, found);
	return found;
}

//Add All Same Movies
//Used by Classics
//Adds pointers to all movies with same title, but different actors to the
//movie's sameMovieList vector
void MovieInventory::addAllSameMovies (Movie* current, int idx)
{
 	Movie* found = getMovieByTitle(idx, current -> getTitle(), current -> getYearReleased());
	while(found != NULL)
	{
 		current -> addSameMovies(found); // add same movie to current movie's sameMovielist
		found -> addSameMovies(current); // add current movie to the other movie's  sameMovielist
		found = getMovieByTitle(idx, current -> getTitle(), current -> getYearReleased());
	}
}
