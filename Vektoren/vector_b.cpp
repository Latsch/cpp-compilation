/**
 * @file   vector_b.cpp
 *
 * Wir betrachten zwei Erweiterungen:
 * <ul>
 *  <li> Ersetzen Sie die assert Vor- und Nachbedingungen durch
 *       eine Ausnahembehandlung
 *  <li> Implementierung Sie Operatoren im Stile der STL
 *   <ul> 
 *     <li> (* iter) liefert den Wert des Elements auf das der Iterator zeigt
 *     <li> iter++ bewegt den Iterator eine Position vorwaerts
 *     <li> iter-- bewegt den Iterator eine Position rueckwaerts
 *   </ul>
 * </ul> 
 * 
 */

#include <string>
#include <iostream>
#include <exception>
using namespace std;

/**
   @brief Link eines einzelnen Elements

  Der Einfachheithalber betrachten wir nur Strings.
  Die Link Klasse verlinkt via 'next' und 'previous'
  die einzelnen String Elemente.

**/


class Link {
  public:
    Link(string s) {
      data = s;
      previous = NULL;
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
	
	Link* link = new Link(s);

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
  
	Link* link = new Link(s);
	iter.previous();
	iter.position = link;
}

/**
   @brief Entfernen des Elements auf das Iterator iter zeigt
   @param [in] Iterator iter

**/

void List::erase(Iterator iter) {
//  assert(iter.position != NULL); /// pre-condition
  
  if ( iter.position != NULL )
	  iter.position = NULL;
  else
	  throw exception();
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
 // assert(position != NULL); /// pre-condition
  
  if ( position != NULL )
	  return position->data;
  else
	  throw exception();
  
}

/**
   @brief Bewege Iterator eine Positon vorwaerts

**/
void Iterator::next() {
 // assert(position != NULL); /// pre-condition

    if ( position != NULL )
	  position = position->next;
  else
	  throw exception();
}

/**
   @brief Bewege Iterator eine Positon rueckwaerts

**/
void Iterator::previous() {
	position = position->previous;
	 //assert(position != NULL); /// post-condition
    if ( position == NULL )
	  throw exception(); 
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
	try
	{
		cout << iter.get() << endl;
	} 
	catch (exception)
	{
		cout << "Position equals Zero!" << endl;
	}
	
	try
	{
		iter.next();	
	} 
	catch (exception)
	{
		cout << "Next is equal Zero!" << endl;
	}
	
	try
	{
		cout << iter.get() << endl;
	} 
	catch (exception)
	{
		cout << "Position equals Zero!" << endl;
	}
	
	iter = list.end();
	
	try
	{
		cout << iter.get() << endl;
	} 
	catch (exception)
	{
		cout << "Position equals Zero!" << endl;
	}

	try
	{
		cout << iter.get() << endl;
	} 
	catch (exception)
	{
		cout << "Position equals Zero!" << endl;
	}
	system("Pause");
	return 0;

	

}


