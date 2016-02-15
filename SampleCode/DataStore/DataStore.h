#ifndef DATASTORE_H
#define DATASTORE_H
// DataStore.h - ....
/////////////////////////////////////////////////////////////////////////////
// DataStore.h - Contains a catalog of all files in the file set           //
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
/*
*  Package Operations
* --------------------
* a catalog of all files in the file set, saving each file name only once and saving each path only once, 
while preserving all of the containment relationships between directories and their files. 
*
 
*  Maintenance History:
* ----------------------
*  Ver 1.0 : 8 Feb 15
*  - first release
*/
#include <list>
#include <vector>
#include <map>
#include <set>

class DataStore
{
public:
	using set_iter = std::set < std::string >::iterator;
	using map_iter = std::map<std::string, std::list < std::set < std::string >::iterator >>::iterator;
	
	//counting the number of directories
	int directoryCount() {
		return std::distance(mapSet.begin(), mapSet.end());
	}
	
	//adding the files to the set based on if they are already availaible ;if not they are added to the set
	std::set < std::string >::iterator  checkingList(const  std::string   pathName)
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
	void  addMap(const std::string& filename, const std::string  pathName)
	{
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
	}

	set_iter begin_set() { return mapSet.begin(); }
	set_iter end_set() { return mapSet.end(); }
	map_iter begin() { return mapStore.begin(); }
	map_iter end() { return mapStore.end(); }
	
	using iterator = std::vector<std::string>::iterator;

	void save(const std::string& filespec) { store.push_back(filespec); }
	void save(const std::string& filename, const std::string& path) {}
	void saveset(const std::string & filemame)
	{
		mapSet.insert(filemame);
	}



   
private:
   
  std::map <std::string, std::list < std::set < std::string >::iterator >> mapStore;
  std::set < std::string > mapSet;
  std::vector<std::string> store;

};
#endif
