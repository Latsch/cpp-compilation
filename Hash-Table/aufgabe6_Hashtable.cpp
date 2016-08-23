
/**
 * @file   aufgabe6_Hashtable.cpp 
 * @brief  Hashtable mit STL Listen (8 Punkte = 5 + 3)
 *



Hashtabelle mit verketteten Listen 

*/

#include <iostream>
#include "Hashtable.h"

using namespace std;

int main() {
	
	
	Hashtable<int> table(5);
	
	table.put("Key1", 1);
	table.put("Key2", 2);
	table.put("Key3", 3);
	
	try
	{
		cout <<"Wert des Schluessels ist : " <<  table.get("Key2") << endl; 
	}
	catch(invalid_argument& re)
	{
		cout << "Schluessel nicht vorhanden : \"" << re.what()<<  "\"" << endl;
	}
	


	try
	{
		cout << "Wert des Schluessels ist : " << table.get("Key1") << endl;
	}
	catch(invalid_argument& re)
	{
		cout << "Schluessel nicht vorhanden : \"" << re.what()<<  "\"" << endl;
	}

	
	
	table.remove("Key3");
	
	try
	{
		cout <<"Wert des Schluessels ist : " <<  table.get("Key3") << endl; 
	}
	catch(invalid_argument& re)
	{
		cout << "Schluessel nicht vorhanden : \"" << re.what()<<  "\"" << endl;
	}
	
	system("Pause");
	return 0;
}

