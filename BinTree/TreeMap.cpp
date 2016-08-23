/**
 * @file   TreeMap.cpp
 

 */

#include <string>
#include "TreeMap.h"

using namespace std;

int main() 
{
	TreeMap<int,string> tree;
	
	tree.add(42, "Lets");
	tree.add(30, "Ho");
	tree.add(20, "Hey");
	tree.add(68, "Go");
	tree.add(18, "Party");
	tree.add(70, "Trololol");
	tree.add(33, "U Mad");
	
	
	cout << tree.contains(10) << endl;
	try
	{
		cout << "Der Wert zum Schluessel ist : " << tree.find(42) << endl;
	} 
	catch (exception)
	{
		cout << "Key not available!" << endl;
	}
	cout << tree.contains(42)<< endl;
	tree.dump(cout);
	cout << endl;
	system("Pause");
	return 0;
}
