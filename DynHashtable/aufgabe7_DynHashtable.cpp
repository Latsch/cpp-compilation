
/**
 * @file   aufgabe7_DynHashtable.cpp

**/

#include <iostream>
#include "DynHashtable.h"

using namespace std;

int main() {

	DynHashtable<int> dtable(5);

	dtable.put("Key1", 1);
	dtable.put("Key2", 2);
	dtable.put("Key3", 3);
	
	
	dtable.output();
	cout << endl;

	dtable.put("Key1", 33 );
	dtable.put("Key4", 4);
	dtable.put("Key5", 5);
	dtable.output();

	cout << endl;
	dtable.remove("Key1");
	dtable.remove("Key2");
	dtable.remove("Key4");
	dtable.output();

	system("Pause");
	return 0;
}

