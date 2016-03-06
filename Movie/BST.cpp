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

Movie*& BST::getMovie (Movie* movieSearch)
{
	
}

bool BST::addMovie(Movie* movieAdd)
{
	
}

bool BST::removeMovie(Movie* movieRemove)
{
	
}

ostream& operator<< (ostream& out, const BST& bst) 
{
	bst.printHelper(bst.root);
	cout << endl;
	return out;
}

Movie*& BST::retrieveHelper (const Movie& movie, Node* cur) const 
{
	if (cur == NULL) // movie not found
		return false;
	else if (*cur -> movie == movie) // movie found
	{
		foundData = cur -> movie;
		return true;
	}
	else if (*cur -> movie > movie) 
		return retrieveHelper (movie, cur -> left);
	else 						  
		return retrieveHelper (movie, cur -> right);

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

void BST::printHelper (Node* cur) const
{
	if (cur != NULL) 
	{
		printHelper(cur -> left);
		cout << *cur ->movie << " ";
		printHelper(cur -> right);
	}
}

