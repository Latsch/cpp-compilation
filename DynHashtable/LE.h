/*
 * LE.h
 * Listenelement
 */

#ifndef LE_H_
#define LE_H_

// Vorwaertsdeklaration, damit liste als friend
// von LE aufgefuehrt werden kann.
template <class type>
class liste;

template <class type>
class LE{
	friend class liste<type>;
	type value;
	LE<type>* next;
	LE<type>* prev;

public:

	LE()
	{
	}

	LE(type value, LE<type>* prev, LE<type>* next = 0) 
	{
		this->value = value;
		this->prev = prev;
		this->next = next;
	}
};


#endif /* LE_H_ */

