/**
 * @file   DynHashtable.h
 * @brief  DynHashtable Klasse
 *

*/

#ifndef __DYNHASHTABLE__INCLUDED__
#define __DYNHASHTABLE__INCLUDED__

#include "Liste.h"
#include <cassert>
#include "Triplet.h"
#include <iostream>

using namespace std;

template<class type>
class DynHashtable {
  liste<Triplet<type> >* table;    /// Array mit Listen
  int size;						/// Laenge des Arrays
  int max;                     /// Schwellenwert in % Maximum
  int min;                     /// Schwellenwert in % Minimum
  int elements;					///Anzahl der Elemente in der Hashtable

  int hashcode(string key) /// Hashwert ermitteln
	{
		unsigned int result = 0;

		for(unsigned int i = 0; i < key.length(); i++)
		{
			result += key[i];
		}

		return result;
	}


public:
  
	
DynHashtable(int nsize, int min=25, int max=75) 
  { 
	  this->size = nsize;
	  this->max = max;
	  this->min = min;
	  this->elements = 0;
	  table = new liste<Triplet<type>>[size];
  };
  
  ~DynHashtable() 
  {

  }
  
  bool put(string key, type value);
  type get(string key);	
  bool remove(string key);
  bool contains(string key);
  void resizeBig();
  void resizeSmall();
  void output();
};

/** @brief Ist der Schluessel vorhanden?

Prueft, ob der Schluessel in der Tabelle vorhanden ist. 
Gibt es ihn bereits, dann ist der Rueckgabewert true, ansonsten false.
**/
template <class type>
bool DynHashtable<type>::contains(string key) 
{
	int hashKey = hashcode(key) % size;
	bool contains = false;
	liste<Triplet<type> >* search = &table[hashKey];
	  
	for(unsigned int i = 0; i < search->getSize(); i++)
	{
		if(search->get(i).key == key)
		{
			contains = true;
		}
	}

	return contains;
}

template <class type>
void DynHashtable<type>::output()
{
	for(int j = 0; j < size; j++)
	{
		if( !(table[j].empty()) ) 
		{
			for(unsigned int i = 0; i < table[j].getSize(); i++)
			{
				Triplet<type> x = table[j].get(i);
				int entry = x.hashcode % size;
				cout << "HashKey : " <<  entry <<" enthält Hashcode : " << x.hashcode << " Schluessel : " << x.key << " Wert : " << x.value << endl;
			}
		}
	}

}

/** @brief Wert einfügen

  Einen neuen Wert in die Hashtabelle einfuegen. 
  Die Rueckgabe ist true, wenn der Schluessel schon vorher in 
  der Tabelle vorhanden war. In diesem Fall ersetzt der neue Wert 
  den alten. Die Rueckgabe ist false, wenn der Schluessel 
  noch nicht vorhanden war.
**/

template <class type>
bool DynHashtable<type>::put(string key, type value) 
{
	int hashcd = hashcode(key);
	int hashKey = hashcd % size;
	if(contains(key))
	{
		liste<Triplet<type> >* search = &table[hashKey];
		for(unsigned int i = 0; i < search->getSize(); i++)
		{
			if(search->get(i).key == key)
				search->get(i).value = value;
		}
	}
	else
	{
		  Triplet<type> tripel(key, value, hashcd);
		  table[hashKey].append(tripel);
		  elements++;
	}
	
	float elementsb = elements * 100;
	float sizeb = size * 100;
	float sampleb = (elementsb/sizeb)*100;
	int sample = sampleb;

	if(  sample > max	)
		resizeBig();
	
	return contains(key);
}

/** @brief Hashtabelle vergrößern

  Die größe der Hashtabelle wird verdoppelt.
  Es wird eine Kopie der Hashtabelle erstellt, die Hashtabelle 
  wird verdoppelt und von der Kopie in die neue, doppelt
  so große Hashtabelle eingefügt.
**/
template<class type>
void DynHashtable<type>::resizeBig()
{
	int oldSize = size;
	size *= 2;
	
    liste<Triplet<type>>* oldTable = table; //wirklich hashtabelle? macht flache kopie probleme?
	
	table = new liste<Triplet<type>>[size];

	for(int j = 0; j < oldSize; j++)
	{
		if( !(oldTable[j].empty()) ) 
		{
			for(unsigned int i = 0; i < oldTable[j].getSize(); i++)
			{
				Triplet<type> x = oldTable[j].get(i);
				int entry = x.hashcode % size;
				table[entry].append(x);
			}
		}
	}
}

/** @brief Wert zum Schluessel auslesen

Den zum Schluessel passenden Wert aus der Tabelle auslesen. 
Was machen Sie, wenn der Schluessel gar nicht in der 
Tabelle vorhanden ist?
**/
template<class type>
type DynHashtable<type>::get(string key) {
  
	int hashKey = hashcode(key) % size;
	if(contains(key))
	{
		type nvalue = NULL;
		liste<Triplet<type> >* search = &table[hashKey];
		for(unsigned int i = 0; i < search->getSize(); i++)
		{
			if(search->get(i).key == key)
			 nvalue = search->get(i).value;
		}
		return nvalue;	
	}
	else
	{
		throw invalid_argument(key);
		
	}
}


template <class type>
void DynHashtable<type>::resizeSmall()
{
	int oldSize = size;
	size = size/2;
	
	liste<Triplet<type>>* oldTable = table; //wirklich hashtabelle? macht flache kopie probleme?
	table = new liste<Triplet<type>>[size];

	//table inhalt löschen?

	for(int j = 0; j < oldSize; j++)
	{
		if( !(oldTable[j].empty()) ) 
		{
			for(unsigned int i = 0; i < oldTable[j].getSize(); i++)
			{
				Triplet<type> x = oldTable[j].get(i);
				int entry = x.hashcode % size;
				table[entry].append(x);
			}
		}
	}
	//delete oldTable;
}

/** @brief Schluessel loeschen

Loescht den Wert, der zum Schluessel gehoert, aus der Tabelle. 
Wurde der Schluessel nicht gefunden, dann ist der Rueckgabewert 
false, ansonsten true.

 **/
template <class type>
bool DynHashtable<type>::remove(string key) 
{
	int hashKey = hashcode(key) % size;
	  if (contains(key))
	  {
		liste<Triplet<type> >* search = &table[hashKey];
		unsigned int count = 0;

		while(count < search->getSize())
		{
			if(search->get(count).key == key)
			{
				search->remove(count);
			}
			else
			{
				count++;
			}
			
		}
		
		elements--;

		float elementsb = elements * 100;
		float sizeb = size * 100;
		float sampleb = (elementsb/sizeb)*100;
		int sample = sampleb;

		if( sample < min	)
			resizeSmall();

		return true;
	  
	  }
	  else
	  {
		return false;
	  }
}


#endif // __DYNHASHTABLE__INCLUDED__
