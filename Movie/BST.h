// BST.h---------------------------------------------------------------------
// Hyungjin Lee CSS 343 
// 3/8/16
// ----------------------------------------------------------------------------
// ADT Binary Search Tree using nodes
// ----------------------------------------------------------------------------
// Includes some of the common BST functions,
// Specialized node that points to movies
// ----------------------------------------------------------------------------


#ifndef BST_H
#define BST_H

#include <iostream>  //input and output
#include "Movie.h" 
using namespace std;

// BST Node contains pointer for left, right, and movie
struct Node 	
{
	Node* left;
	Node* right;
	Movie* movie;
};
	
class BST {
	
	// Overloaded << : prints BST in correct structure
	friend ostream& operator<< (ostream&, const BST&);
	
public:
	
	// Constructors
	BST ();
	
	// Desctructor
	~BST ();
	
	Movie*& getMovie (const Movie*) const; // get movie from the tree 
	bool addMovie(Movie*); // add movie node
	bool removeMovie(Movie*); // removie movie node
	
	
private:
	Node* root; // Points to the root of the BST
	
	// private functions
	void makeEmptyHelper (Node* &);
	void printHelper (Node* cur) const;
	
};
#endif