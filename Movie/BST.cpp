// BST.cpp---------------------------------------------------------------------
// Hyungjin Lee CSS 343
// 3/5/16
// ----------------------------------------------------------------------------
// ADT Binary Search Tree using nodes
// ----------------------------------------------------------------------------
// Includes all of the common BST functions
// ----------------------------------------------------------------------------

#include "BST.h"

// Default Constructor --------------------------------------------------------
// Creates an empty tree
// Preconditions: NONE
// Postconditions: This BST is constructed, but empty
// ----------------------------------------------------------------------------
BST::BST ()
{
	root = NULL;
}

// Destructor -----------------------------------------------------------------
// Empty out the tree and deletes the root
// Preconditions: NONE
// Postconditions: BST is completely empty
// ----------------------------------------------------------------------------
BST::~BST ()
{
	makeEmptyHelper(root);
}

//Get Movie
//Returns true if movieSearch is found in BSTree
//Assigns found movie to the found Movie pointer parameter
bool BST::getMovie (const Movie& movieSearch, Movie*& found) const
{
	return retrieveHelper (movieSearch, found, root);
}

bool BST::addMovie(Movie*& movieAdd)
{
	return insertHelper(root, movieAdd);
}

//Outstream operator
//Calls recursive helper function to print the contents
//of the BSTree
ostream& operator<< (ostream& out, const BST& bst)
{
  	bst.printHelper(bst.root);
	cout << endl;
	return out;
}

//Insert Helper
//Recursive helper function
//Inserts the newMovie pointer into the BSTree
bool BST::insertHelper(Node* &cur, Movie*& newMovie)
{
	if (cur == NULL) // insert
	{
		cur = new Node;
		cur -> right = NULL;
		cur -> left = NULL;
		cur -> movie = newMovie;
		return true;
	}
	else if (*cur -> movie == *newMovie) // duplicate exists, data not inserted
		return false;
	else if (*cur -> movie > *newMovie)
		return insertHelper (cur -> left, newMovie);
	else
		return insertHelper (cur -> right, newMovie);
}

//Retrieve Helper
//Returns true if the movieSearch movie is found in the BSTree
//Retrieves the movieSearch movie from the BSTree
//and assigns it to the found Movie pointer
bool BST::retrieveHelper (const Movie& movieSearch, Movie*& found, Node* cur) const
{
  	if (cur == NULL) // movie not found
		return false;
	else if (*cur -> movie == movieSearch) // movie found
	{
		found = cur -> movie;
		return true;
	}
	else if (*cur -> movie > movieSearch)
		return retrieveHelper (movieSearch, found, cur -> left);
	else
		return retrieveHelper (movieSearch, found, cur -> right);

}

//Make Empty Helper
//Recursive helper function for destructor
//Deletes dynamic memory
void BST::makeEmptyHelper(Node* &cur)
{
  	if (cur != NULL)
	{
		makeEmptyHelper(cur -> left);
		makeEmptyHelper(cur -> right);

		delete cur -> movie;
		cur -> movie = NULL;
		delete cur;
		cur = NULL;
	}
}

//Print Helper
//Prints inorder traversal of BSTree
void BST::printHelper (Node* cur) const
{
  	if (cur != NULL)
	{
		printHelper(cur -> left);
		if (!cur -> movie -> getCountedStatus()) // if the movie has not been counted already
		{
			cur -> movie -> display();
			cur -> movie -> setCounted(true);
			cout << endl;
		}
		printHelper(cur -> right);
	}
}

//Reset Counted
//Resets all the Classic movies counted to false
//Uses recursive helper function
void BST::resetCounted()
{
	resetHelper(root);
}

//Reset Helper
//Recursive helper function for resetCounted()
//Sets all Classic movies' counted variable to false
void BST::resetHelper(Node* cur)
{
	if (cur != NULL)
	{
		resetHelper(cur -> left);
        cur -> movie -> setCounted(false);
		resetHelper(cur -> right);
	}
}

//Get Movie By Title
//Returns true if movie is found in BSTree by its title
//Calls recursive helper function
bool BST::getMovieByTitle(string title, int year, Movie*& found)
{
	return getMovieByTitleHelper(title, year, found, root);
}

//Get Movie By Title Helper
//Recursive helper function for gotMovieByTitle()
//Returns true if the movie is found by its title
bool BST::getMovieByTitleHelper (string title, int year, Movie*& found,  Node* cur)
{
  	if (cur == NULL) // movie not found
		return false;
	else if (cur -> movie -> getTitle() == title && cur -> movie -> getYearReleased() == year && !cur -> movie -> getCountedStatus()) // movie found
	{
		found = cur -> movie;
		found -> setCounted(true);
		return true;
	}
	else
		return getMovieByTitleHelper (title, year, found, cur-> left) || getMovieByTitleHelper (title, year, found, cur-> right);
}
