// LinkedList.h

// tom bailey   0740  5 oct 2010
// Declaration of the List class.

// A List stores and manages a sequence of doubles.

// This version uses a pointer to the first Node of a
//   singly linked list of Nodes.

#include <iostream>
using std::ostream;
using std::cout;

class Node
{
public:
	std::string entry_;
	Node * next_;

public:
	// Constructors

	// post: this Node contains entry and a NULL pointer
	explicit Node(std::string entry);

	// post: this Node contains entry and next
	Node(std::string entry, Node * next);

	// Destructor

	~Node();

private:
	// Inaccessible standard functions
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
};

Node::Node(std::string entry)
	: entry_(entry), next_(NULL) {}

Node::Node(std::string entry, Node * next)
	: entry_(entry), next_(next) {}

Node::~Node() {}

#define ulong unsigned long




// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

// MODIFIED: by rafe cooley 11/13/2017
// change entry type to string for hashing lab

#include <string>
using std::string;

#define ulong unsigned long


class List
{
public:
	//*** Standard functions ***

	// Default constructor
	// post: this List is empty.
	List();

	// Copy constructor
	// post: this List now stores a copy of the sequence stored
	//         in other
	List(const List & other);

	// Destructor
	// post: all the Nodes of this List have been destroyed.
	~List();

	// Assignment operator
	// post: this List now stores a copy of the sequence stored
	//         in other
	const List & operator=(const List & other);


	//*** Accessors ***

	// post: true has been returned just if this List is
	//         empty.
	bool empty() const;

	// post: the doubles in this List have been written to
	//         outfile.
	void print() const;


	//*** Mutators ***

	// post: x has been added as the first double in this
	//         List.
	void insertAsFirst(string x);

	void insertAsLast(string x);
	// pre:  this List is not empty.
	// post: the first double in this List has been removed
	//         from this List and has been returned.
	string removeFirst();

private:
	//*** Inaccessible standard functions ***


	//*** Helper functions ***
	// process part of the linked structure

	// post: a pointer to a copy of the linked structure
	//         targeted by ptr has been returned.
	static Node * clone(Node * ptr);


private:
	Node * first_;

};


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}


const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(string x)
{
	first_ = new Node(x, first_);
}

void List::insertAsLast(string x)
{
	if (!empty())
	{
		Node * ptr = first_;
		while (ptr != NULL)
		{
			if (ptr->next_ == NULL)
			{
				ptr->next_ = new Node(x);
				break;
			}
			else { ptr = ptr->next_; }
		}
	}
	else { insertAsFirst(x); }
}

string List::removeFirst()
{
	string item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print() const
{
	Node * ptr = first_;

	cout << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		while (ptr != NULL)
		{
			if (ptr == first_)
			{
				cout << ptr->entry_;
			}
			else
			{
				cout << " | " << ptr->entry_;
			}
			ptr = ptr->next_;
		}
	}
	cout << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node* List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}