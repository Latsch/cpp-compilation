#ifndef _LISTE_INCLUDED_
#define _LISTE_INCLUDED_

#include "LE.h"

template <class type>
class FilterableList
{

private:

	LE<type>* first;
	LE<type>* last;
	size_t size;
	
public:

	//Standard Konstruktor zum erstellen einer leeren Liste
	FilterableList()
	{
		first = 0;
		last = 0;
		size = 0;
	}

	//Destruktor zum löschen der Liste
	~FilterableList()
	{
		removeFirst();
	}

	//Filtert die Liste bezüglich der Elemente
	FilterableList<type> filter(Func<type, boolean) l){
		
		//Todo.. Lambda quatsch müsst ich grad selber nachschauen und muss essen gehen ;P
	}
	
	//Funktion um zu ermitteln ob die Liste leer ist
	bool empty()
	{
		if( first == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//Funktion um ein Element (@param value) hinten an die Liste anzufügen
	void add(type value)
	{
		// Ein neues Listenelemente für den Wert erzeugen.
	    // Das neue Element hat keinen Nachfolger, aber einen Vorgänger
		LE<type>* newLE = new LE<type>(value,last);

		if(first == 0)
		{ 
			first = newLE;
		}
		else
		{
			last->next = newLE;
		}
		
		last = newLE;
		size++;
	}

	size_t getSize()
	{
		return size;
	}

	
	//Funktion um ein Element, das vorne an der Liste steht, zu löschen
	void removeFirst()
	{
		if(first != 0)
		{
			LE<type>* nextFirstLE = first->next;

			delete first;

			first = nextFirstLE;

			if(first == 0)
			{
				last = 0;
			}
		}
	}

	//Funktion um ein Element, das hinten an der Liste steht, zu löschen
	void removeLast()
	{
		if(first != 0)
		{
			LE* nextLastLE = last->prev; 

			delete last;

			last = nextLastLE;

			if(first == 0)
			{
				last = 0;
			}
		}
	}

	
	//Funktion um ein Element an Stelle #index zu löschen
	void remove(unsigned int index){
		
		unsigned int count = 0;
		LE<type>* actualE = first;
		
		while(count < index)
		{
			actualE = actualE->next;
			count++;
		}
		
		if((actualE->prev == 0) & (actualE->next == 0))
		{
			first = 0;
			last = 0;
		}
		else
		{
			if(actualE->prev != 0){
				actualE->prev->next = actualE->next;
			}
			if(actualE->next != 0){
				actualE->next->prev = actualE->prev;
			}
			if(actualE == first){
				first = actualE->next;
			}
			if(actualE == last){
				last = actualE->prev;
			}
		}
		size--;
		delete actualE;
	}

	//Funktion zur ermittlung der größe der Liste
	int getSize() const
	{
		LE *listRunner = first;
		int size = 0;

		while (listRunner != 0) {
			size++;
			listRunner = listRunner->next;
		}

		return size;
	}

	
	//Methode zur Rückgabe des LE am angegebenen Index
	type& has(type valueWanted)
	{
		LE<type>* listRunner = first;
		unsigned int counter = 0;
		boolean hasE = false;

		while (listRunner != 0 && counter < size) {
			counter++;
			if(listRunner->value == valueWanted){
				counter = getSize();
			}else{
				listRunner = listRunner->next;
			}
			
		}

		return hasE;	
	}
	
	
	//Methode zur Rückgabe des LE am angegebenen Index
	type& get(unsigned int index)
	{
		LE<type>* listRunner = first;
		unsigned int counter = 0;

		while (listRunner != 0 && counter < index) {
			counter++;
			listRunner = listRunner->next;
		}

		return listRunner->value;	
	}

};

#endif //_LISTE_INCLUDED