/////////////////////////////////////////////////////////////////////////////
// DataStore.cpp - Contains a catalog of all files in the file set         //
//                    to user inputs                                       //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright © Kusum Rudrayya,2015                                         //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2010                             //
// Platform:    Dell XPS 8300, Core i7, Windows 7 SP1                      //
// Application: Spring Projects, 2015                                      //
// Author:       Kusum Rudrayya, Syracuse University                       //
//               krudrayy@syr.edu                                          //
/////////////////////////////////////////////////////////////////////////////

#include "DataStore.h"
#include <iostream>




//----< test stub >--------------------------------------------------------
#ifdef TEST_DATASTORE

int main()
{
	std::cout << "\n  Testing DataStore";

	DataStore ds;
	 
	ds.save("one");
	ds.save("two");
	ds.save("three");
	DataStore::map_iter iter = ds.begin();
	std::cout << "\n  " ;

	for (auto item : ds)
	{
		//std::cout << "\n  " << item.c_str();
	}
	std::cout << "\n\n";
}

#endif


 
 