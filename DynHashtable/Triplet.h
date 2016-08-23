
/**
 * @file  Triplet.h
 *
 *
  * Objekte dieser Klasse speichern Tripel,
  * bestehend aus einem Schluessel und einem
  * Wert, sowie dem Hashcode des Schluessels. Um Tripel vergleichen zu koennen sollen
  * nur die Schluessel verwendet werden (siehe
  * Operator ==).
 */

#ifndef __PAIR__INCLUDED__
#define __PAIR__INCLUDED__

#include <string>

using namespace std;

template <class type>
class Triplet {
public:
  string    key;
  type      value;
  int hashcode;

  Triplet() {}
  

  Triplet(string key, type value ,int hashcode) {
    this->key = key;
    this->value=value;
	this->hashcode = hashcode;
  }
};

#endif // __PAIR__INCLUDED__
