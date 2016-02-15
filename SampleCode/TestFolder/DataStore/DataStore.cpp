/////////////////////////////////////////////////////////////////////////////
// DataStore.cpp - Used to display all the information according        //
//                    to user inputs                                       //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright © Kusum Rudrayya,2015                                          //
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


//adding the files to the set based on if they are already availaible ;if not they are added to the set
/*std::set < std::string >::iterator DataStore::checkingList(const  std::string  pathName)
{
	if (mapSet.find(pathName) != mapSet.end())

		return mapSet.find(pathName);
	else
	{
		mapSet.insert(pathName);
		return mapSet.find(pathName);
	}

}

//adding the filename as key and values has the list of iterators with path reference
  void DataStore::  addMap(const std::string& filename, const std::string  pathName){
	if (mapStore.find(filename) == mapStore.end()) {
		if (mapSet.find(pathName) == mapSet.end())
			mapSet.insert(pathName);
		std::list < std::set < std::string >::iterator >  secondList;
		secondList.push_back(mapSet.find(pathName));
		mapStore.insert(std::pair <std::string, std::list < std::set < std::string >::iterator> >(filename, secondList));
}
	else {

		(mapStore.find(filename)->second).push_back(checkingList(pathName));
	}

}*/

