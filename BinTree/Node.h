/**
 * @file   Node.h

*/

#ifndef __Node__INCLUDED__
#define __Node__INCLUDED__

#include <iostream>

/**
  * Die Klasse beschreibt einen Knoten eines binären
  * Suchbaumes.
  */
template <class type>
class Node {
	// Knotenwert
	type        value;

	// Linker Sohn des Knotens
	Node<type>* left;

	// Rechter Sohn des Knotens
	Node<type>* right;

public:
	/**
	  * Knoten erzeugen.
	  * @param newValue Wert, der in den Knoten eingetragen wird.
	  * @param newLeft  Linker Sohn des neuen Knotens. default: 0 (keiner)
	  * @param newRight Rechter Sohn des neuen Knotens. default: 0 (keiner)
	  */
	Node(const type& newValue, Node<type>* newLeft  = 0,
								 Node<type>* newRight = 0):
		value(newValue),left(newLeft),right(newRight) {
	}

	// Getter- und Setter-Methoden
	Node<type>* setLeft(Node<type>* ptr)  {
		return left = ptr; 
	}

	Node<type>* getLeft() const { 
		return left; 
	}

	Node<type>* setRight(Node<type>* ptr) { 
		return right = ptr; 
	}

	Node<type>* getRight() const {
	  return right; 
	}

	type&	getValue() { 
		return value; 
	}

	const type& getValue() const { 
		 return value; 
	}

	void setValue(type newValue) { 
		value = newValue; 
	}

	void dump(std::ostream& str) const {
		str << "Node: " << this << " " << value 
			<< "-" << left << ":" << right << std::endl;
	}
};

#endif // __Node__INCLUDED__
