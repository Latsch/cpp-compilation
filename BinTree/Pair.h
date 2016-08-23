
/**
 * @file   Pair.h
 *
 *
  * Objekte dieser Klasse speichern Paare,
  * bestehend aus einem Schluessel und einem
  * Wert. Um Paare vergleichen zu koennen sollen
  * nur die Schluessel verwendet werden (siehe
  * Operator ==).
 */

#ifndef __PAIR__INCLUDED__
#define __PAIR__INCLUDED__

#include <string>

using namespace std;

/**
  * Objekte dieser Klasse speichern Paare,
  * bestehend aus einem Schluessel und einem
  * Wert. Um Paare vergleichen zu koennen sollen
  * nur die Schluessel verwendet werden (siehe
  * Operator ==).
  */
template <class keytype, class valuetype>
class Pair {
public:
	keytype   key;
	valuetype value;

	Pair(keytype key, valuetype value = valuetype()) {
		this->key = key;
		this->value = value;
	}
};

#endif // __PAIR__INCLUDED__
