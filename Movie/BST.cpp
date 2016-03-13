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

bool BST::getMovie (const Movie& movieSearch, Movie*& found) const
{
	return retrieveHelper (movieSearch, found, root);
}

bool BST::addMovie(Movie*& movieAdd)
{
	return insertHelper(root, movieAdd);
}

ostream& operator<< (ostream& out, const BST& bst) 
{
  	bst.printHelper(bst.root);
	cout << endl;
	return out;  
}

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

bool BST::retrieveHelper (const Movie& movieSearch, Movie*& found, Node* cur) const 
{
  	if (cur == NULL) // movie not found
		return false;
	else if (*cur -> movie == movieSearch) // movie found
	{		
		found = cur -> movie;
		
		cout << " MOVIE STOCK HERE: " << found -> getStock() << endl;
		
		return true;
	}
	else if (*cur -> movie > movieSearch) 
		return retrieveHelper (movieSearch, found, cur -> left);
	else 						  
		return retrieveHelper (movieSearch, found, cur -> right); 
 
}

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

// inorder
void BST::printHelper (Node* cur) const
{
  	if (cur != NULL) 
	{
		printHelper(cur -> left);
        cur -> movie -> display();
        cout << endl;
		printHelper(cur -> right);
	}  
} 

