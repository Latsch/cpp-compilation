/**
 * @file   TreeMap.h
   @brief TreeMap Klasse
 */

#ifndef __TREEMAP__INCLUDED__
#define __TREEMAP__INCLUDED__

#include <exception>
#include "Pair.h"
#include "Node.h"

/** @brief Klasse TreeMap
 *
  * Die Klasse beschreibt einen binaeren Suchbaum,
  * in dessen Knoten Paar-Objekte abgelegt 
  * werden. Ein Paar besteht aus einem Schluessel
  * sowie dessen zugehoerigem Wert. Zum Einfuegen
  * und Suchen usw. wird lediglich der Schluessel
  * als Vergleichskriterium verwendet.
  */
template <class keytype, class valuetype>
class TreeMap {
	/// Wurzelknoten
	Node<Pair<keytype, valuetype> >* root;

	/// Kompletten Teilbaum loeschen
	void removeTree(Node<Pair<keytype, valuetype> >* myRoot) {
		if (myRoot == 0) {
			return;
		}

		removeTree(myRoot->getLeft());
		removeTree(myRoot->getRight());
		delete myRoot;
	}

public:
	/**
	  * @brief Konstruktor: Erzeugt einen neuen, leeren Baum.
	  */
	TreeMap() : root(0) {
	}

	/**
	  * @brief Destruktor: Loescht den kompletten Baum vom Heap.
	  */
	~TreeMap() { 
		removeTree(root); 
	}

	/**
	  * @brief Sucht einen Knoten anhand des darin
	  * abgelegten Schluessels.
	  * @param key Gesuchter Schluessel.
	  * @return    Gefundener Wert oder eine Ausnahme,
	  *            falls der Schluessel nicht im Baum vorkam.
	  */
	valuetype find(keytype key) const 
	{
		Node<Pair<keytype, valuetype>>* searchNode = root;

		
		while((searchNode != 0) && (searchNode->getValue().key != key))
		{
				searchNode = (key > searchNode->getValue().key) ?
							  searchNode->getRight() :
							  searchNode->getLeft();
		}
		
		if ( searchNode == 0)
		{
			throw exception();
		}
		else if ( searchNode->getValue().key == key)
		{
			return searchNode->getValue().value;
		}
	return 0;
	}

	/**
	  * @brief Stellt fest, ob ein Schluessel bereits im Baum
	  * abgelegt ist.
	  * @param key Gesuchter Schluessel.
	  * @return    true, falls der Schluessel schon vorhanden ist,
	  *            ansonsten false.
	  */
	bool contains(keytype key) const 
	{
		Node<Pair<keytype, valuetype>>* searchNode = root;

		
		while((searchNode != 0) && (searchNode->getValue().key != key))
		{
				searchNode = (key > searchNode->getValue().key) ?
							  searchNode->getRight() :
							  searchNode->getLeft();
		}
		
		if ( searchNode == 0)
		{
			return false;
		}
		else if ( searchNode->getValue().key == key)
		{
			return true;
		}
	return 0;
	}


	/**
	  * @brief Fuegt einen neuen Schluessel mit Wert in den Baum ein. 
	  * @param key Einzufuegender Schluessel.
	  * @param val Einzufuegender Wert.
	  * @return    true, falls der Schluessel
	  *            vorher noch nicht im Baum war, false ansonsten.
	  */
	bool add(keytype key, valuetype val) 
	{
		Node<Pair<keytype, valuetype>>* searchNode = root;

		if(searchNode == 0)
		{
			root = new Node<Pair<keytype, valuetype>>(Pair<keytype, valuetype>(key, val));
			return true;
		}
		while(true)
		{
			if(key < searchNode->getValue().key)
			{
				if(searchNode->getLeft() == 0)
				{
					searchNode = searchNode->setLeft(new Node<Pair<keytype, valuetype>>(Pair<keytype, valuetype>(key, val) ));
					return true;
				}
				searchNode = searchNode->getLeft();
			}
			else if(key > searchNode->getValue().key)
			{
				if(searchNode->getRight() == 0)
				{
					searchNode = searchNode->setRight(new Node<Pair<keytype, valuetype>>(Pair<keytype, valuetype>(key, val) ));
					return true;
				}
				searchNode = searchNode->getRight();
			}
			else if(key == searchNode->getValue().key)
			{
				return false;
			}
		}
	}

	/** @brief dump tree
	 *
	  * Ausgabe des kompletten Baumes auf dem Bildschirm. Die Methode
	  * kann auch ueber den ueberladenen Operator << aufgerufen werden.
	  */
private:
	void dump(ostream& str, Node<Pair<keytype, valuetype> >* ptr) const {
		if (ptr != 0) {
			dump(str, ptr->getLeft());
			str << ptr->getValue().key << "=" << ptr->getValue().value << " ";
			dump(str, ptr->getRight());
		}
	}

	/** @brief dump
	  * Ausgabe des kompletten Baumes auf dem Bildschirm. Die Methode
	  * kann auch ueber den ueberladenen Operator << aufgerufen werden.
	  */
public:
	void dump(ostream& str) const {
		dump(str, root);
	}
};


/** @brief Stream Ausgabe
 *
  * Ueberladener Operator <<, um "Stilecht" ein Objekt der Klasse TreeMap
  * auf einen Stream auszugeben.
  */
/*
template <class keytype, class valuetype>
ostream& operator << (ostream& str, const TreeMap<keytype, valuetype>& tree) {
	tree.dump(str);
	return str;
}
*/

#endif // __TREEMAP__INCLUDED__
