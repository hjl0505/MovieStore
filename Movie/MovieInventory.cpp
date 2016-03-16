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
MovieInventory::MovieInventory()
{
    BST comedy, classic, drama;
    movieType.push_back(comedy);
    movieType.push_back(classic);
    movieType.push_back(drama);
}

MovieInventory::~MovieInventory()
{
	movieType.clear();
}

//////////////////////////////////////////////////
//////////     Public Methods    /////////////////
//////////////////////////////////////////////////

Movie* MovieInventory::getMovie (Movie* moviePtr)
{
    Movie *foundPtr = NULL;
    switch (moviePtr->getGenre())
    {
        case 'F':
            movieType[0].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;
            
        case 'C':
            movieType[1].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;
        
        case 'D':
            movieType[2].getMovie(*moviePtr, foundPtr);
            return foundPtr;
            break;
            
        default:
            foundPtr = NULL;
            break;
    }
    return foundPtr;
}

bool MovieInventory::movieExist (Movie* moviePtr)
{
	Movie* foundPtr = getMovie(moviePtr);
    if (foundPtr!= NULL)
        return true;
    else 
        return false;
}

void MovieInventory::printInventory()
{
    for (int i = 0; i < movieType.size(); i++)
    {
        cout << "---------------------------" << endl;
        switch (i)
        {
            case 0:
                cout << "Comedies:" << endl << endl;
				cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20) 
					<< "Director" << setw(7) << "Year" << setw(7) << "Stock" << endl;
                break;
                
            case 1:
                cout << "Classics:" << endl << endl;
				cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20) 
					<< "Director" << setw(7) << "Month" << setw(7)<< "Year" << setw(7)  << "Stock" << endl;
                break;
            
            case 2:
                cout << "Dramas:" << endl << endl;
				cout << setw(7) << "Genre" << setw(7) << "Media" << setw(35) << "Title" << setw(20) 
					<< "Director" << setw(7) << "Year" << setw(7) << "Stock" << endl;
                break;
                
            default:
                break;
        }
        cout << movieType[i];
		movieType[i].resetCounted();
    }
}

bool MovieInventory::addMovie (Movie*& moviePtr)
{
	bool success = false;
	if (moviePtr) {
		 switch (moviePtr->getGenre())
		{
			case 'F':
				success = movieType[0].addMovie(moviePtr);
				return success;
				break;
				
			case 'C':
				success = movieType[1].addMovie(moviePtr);
				if (success)
				{
					moviePtr -> setCounted(true);
					addAllSameMovies(moviePtr, 1);
					movieType[1].resetCounted();
				}
				return success;
				break;
				
			case 'D':
				success = movieType[2].addMovie(moviePtr);
				return success;
				break;
				
			default:
				return success;
				break;
		}  
	}
}

bool MovieInventory::borrowMovie (Movie* moviePtr, string& movieInfo)
{
	bool successful = false;
    if (movieExist(moviePtr))
    {
		Movie* movieToBorrow = getMovie(moviePtr);
		if (movieToBorrow -> subtractFromStock(1))
		{
			movieInfo = movieToBorrow -> getMovieInfo();
			successful = true;
		}
    }
	
	for (int i = 0; i < movieType.size(); i++)
		movieType[i].resetCounted();
	
    return successful;
}

bool MovieInventory::returnMovie (Movie* moviePtr, string& movieInfo)
{
    if (movieExist(moviePtr))
    {
		Movie* movieToReturn = getMovie(moviePtr);
        movieToReturn->addToStock(1);
		
		movieInfo = movieToReturn -> getMovieInfo();
        return true;
    }
    else
        return false;
}

Movie* MovieInventory::getMovieByTitle (int genreIndex, string title, int year)
{
	Movie* found = NULL;
	movieType[genreIndex].getMovieByTitle(title, year, found);
	return found;
}

void MovieInventory::addAllSameMovies (Movie* current, int idx)
{
 	Movie* found = getMovieByTitle(idx, current -> getTitle(), current -> getYearReleased());
	while(found != NULL)
	{
 		current -> addSameMovies(found);
		found -> addSameMovies(current); 
		found = getMovieByTitle(idx, current -> getTitle(), current -> getYearReleased());
	} 
}