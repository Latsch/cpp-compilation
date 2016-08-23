/**
 * @file   Hashtable.h
 * @brief  Hashtable Klasse
 *

*/

#ifndef __HASHTABLE__INCLUDED__
#define __HASHTABLE__INCLUDED__

#include "liste.h"
#include "Pair.h"

using namespace std;

template <class type>
class Hashtable {
  liste<Pair<type> >* table;    /// Array mit Listen
  int size;		       /// Laenge des Arrays

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
  
	Hashtable(int nsize)
	{
		this->size = nsize;
		table = new liste<Pair<type>>[size];
	}

  ~Hashtable()
  {
  }

  bool put(string key, type value);
  type get(string key);	
  bool remove(string key);
  bool contains(string key);
};

/** @brief Wert einfügen

  Einen neuen Wert in die Hashtabelle einfuegen. 
  Die Rueckgabe ist true, wenn der Schluessel schon vorher in 
  der Tabelle vorhanden war. In diesem Fall ersetzt der neue Wert 
  den alten. Die Rueckgabe ist false, wenn der Schluessel 
  noch nicht vorhanden war.
**/

template <class type>
bool Hashtable<type>::put(string key, type value) 
{
	 int hashKey = hashcode(key) % size;
	if(contains(key))
	{
		liste<Pair<type> >* search = &table[hashKey];
		for(unsigned int i = 0; i < search->getSize(); i++)
		{
			if(search->get(i).key == key)
				search->get(i).value = value;
		}
	}
	else
	{
		  Pair<type> paar(key, value);
		  table[hashKey].append(paar);
	 }
	 return contains(key);
}

/** @brief Wert zum Schluessel auslesen

Den zum Schluessel passenden Wert aus der Tabelle auslesen. 
Was machen Sie, wenn der Schluessel gar nicht in der 
Tabelle vorhanden ist?
**/
template<class type>
type Hashtable<type>::get(string key) 
{
	int hashKey = hashcode(key) % size;
	if(contains(key))
	{
		type nvalue = NULL;
		liste<Pair<type> >* search = &table[hashKey];
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

/** @brief Schluessel loeschen

Loescht den Wert, der zum Schluessel gehoert, aus der Tabelle. 
Wurde der Schluessel nicht gefunden, dann ist der Rueckgabewert 
false, ansonsten true.

 **/
template <class type>
bool Hashtable<type>::remove(string key) 
{
	 int hashKey = hashcode(key) % size;
	  if (contains(key))
	  {
		liste<Pair<type> >* search = &table[hashKey];
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
		return true;
	   }
	  else
	  {
		return false;
	  }
}

/** @brief Ist der Schluessel vorhanden?

Prueft, ob der Schluessel in der Tabelle vorhanden ist. 
Gibt es ihn bereits, dann ist der Rueckgabewert true, ansonsten false.
**/
template <class type>
bool Hashtable<type>::contains(string key) {
	
	int hashKey = hashcode(key) % size;
	  bool contains = false;
	  liste<Pair<type> >* search = &table[hashKey];
	  for(unsigned int i = 0; i < search->getSize(); i++){
		  if(search->get(i).key == key){
			  contains = true;
			}
	  }
	  return contains;
}



#endif // __HASHTABLE__INCLUDED__
