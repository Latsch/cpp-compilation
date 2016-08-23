/**
 * @file   vector_a.cpp
 *
 * Implementation von Vektoren im Stile der STL.
 * Reihe von Vereinfachungen:
 * Elemente sind immer Strings und das Interface besteht nur aus
 * Methoden (sprich keine Ueberladung von Operatoren)
 */

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

/**
   @brief Link eines einzelnen Elements

  Der Einfachheithalber betrachten wir nur Strings.
  Die Link Klasse verlinkt via 'next' und 'previous'
  die einzelnen String Elemente.

**/


class Link {
  public:
    Link(string s, Link* prev) {
      data = s;
      previous = prev;
      next = NULL;
    }
  private:
    string data;
    Link* previous;
    Link* next;
    friend class List;
    friend class Iterator;
};



/**
   @brief Iterator mit Methoden

**/

class Iterator {
  public:
  Iterator() {
    position = NULL;
    last = NULL;
  } 
  string get() const;
  void next();
  void previous();
  bool not_equal(Iterator b) const;
  private:
  Link* position;
  Link* last;
  friend class List;
};

/**
   @brief Liste (Methoden und Link auf ersts und letztes Element)

**/


class List {
  public: 
  List() { 
    first = NULL;
    last = NULL;
  } 
  void push_back(string s);
  void insert(Iterator iter, string s);
  void erase(Iterator iter);
  Iterator begin();
  Iterator end();
    
  private:
  Link* first;
  Link* last;
};


/**
   @brief Einfuegen ans Ende eines Elements
   @param [in] string s
**/

void List::push_back(string s) {
	
	Link* link = new Link(s, last);

	if (first == NULL )
	{
		first = link;
	}
	else
	{ 
		last->next = link;
		
	}
	
	last = link;
	
}

/**
   @brief Einfuegen von Element s vor der Stelle auf die Iterator iter zeigt
   @param [in] Iterator iter
   @param [in] string s
**/

void List::insert(Iterator iter, string s) {
  
	iter.previous();
	iter.position->data = s;
}

/**
   @brief Entfernen des Elements auf das Iterator iter zeigt
   @param [in] Iterator iter

**/

void List::erase(Iterator iter) {
  assert(iter.position != NULL); /// pre-condition

  Iterator itera;
  itera.position = iter.position;

  iter.next();
  
  Iterator it;
  it.position = itera.previous();

  if ( it.position != 0)
	iter.position->previous = it.position;
  else
	  iter.position->previous = 0;

  if (iter.position != 0)
	it.position->next = iter.position;
  else
	  it.position->next = 0;

  iter.position = itera.position;

  delete iter.position;
  iter.position = it.position;
}

/**

**/
/**
   @brief Liefert Iterator der auf Anfang der Liste zeigt
   @return Iterator

**/
Iterator List::begin() {
	
	Iterator iter;
	
	iter.position = first;
	return iter;
}

/**
   @brief Liefert Iterator der auf das Ende der Liste zeigt
   @return Iterator

**/
Iterator List::end() {
	Iterator iter;
	
	iter.position = last;
	return iter;
}

/**
   @brief Liefert Wert des Elements auf das der Iterator zeigt
   @return string

**/

string Iterator::get() const {
  assert(position != NULL); /// pre-condition
  return position->data;
}

/**
   @brief Bewege Iterator eine Positon vorwaerts

**/
void Iterator::next() {
  assert(position != NULL); /// pre-condition
  position = position->next;
}

/**
   @brief Bewege Iterator eine Positon rueckwaerts

**/
void Iterator::previous() {
	position = position->previous;
  assert(position != NULL); /// post-condition
}

/**
   @brief Vergleiche (die Position) zwei(er) Iteratoren
   @param [in] Iterator b
   @return bool

**/
bool Iterator::not_equal(Iterator b) const {
	if(position == b.position)
		return true;
	else
		return false;
}

int main() {

	List list;
	list.push_back("A");
	list.push_back("B");
	list.push_back("C");
	list.push_back("D");

	Iterator iter;
	iter = list.begin();
	cout << iter.get() << endl; 
	iter.next();
	cout << iter.get() << endl;
	list.erase(iter);
	iter = list.begin();
	cout << iter.get() << endl;
	iter.next();
	cout << iter.get() << endl;
	iter.previous();
	cout << iter.get() << endl;
	iter = list.end();
	cout << iter.get() << endl;

	Iterator itor;
	itor = list.end();
	cout << iter.not_equal(itor) << endl;
	system("Pause");
	return 0;

	
	

}


