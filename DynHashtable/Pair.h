
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

template <class type>
class Pair {
public:
  string    key;
  type      value;
  unsigned int hashcode;
  Pair();

  Pair(string key, type value , unsigned int hashcode) {
    this->key = key;
    this->value = value;
	this->hashcode = hashcode;
  }
};

#endif // __PAIR__INCLUDED__
