/////////////////////////////////////////////////////////////////////////////
// Exec.cpp-it acts like a central module which delegates the work and call // 
//             he required classes for doing various tasks                 //                       
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



#include "Exec.h"
#include "../Display/FinalDisplay.cpp"
#include <iostream>

//to check if user has asked to recursively search for files
bool Exec::ifRecursive(int argc, char *argv[])
{
	int i=1;
	while (i < argc){
		std::string userInput = argv[i];
		if (userInput == "/s") {
			return true;
			break;
		}
		else
			i++;
	}
	
}
//to check if user has asked to display duplicate files
bool Exec::ifDuplicate(int argc, char *argv[])
{
	int i = 1;
	while (i < argc){
		std::string userInput = argv[i];
		if (userInput == "/d") {
			return true;
			break;
		}
		else
			i++;
	}
}
 
int main(int argc, char *argv[])
{
	DataStore ds;
	Exec exObj;
	FinalDisplay disObj;
	bool recurse=false,duplicate = false;
	FileMgr fm(".", ds);
	recurse = exObj.ifRecursive(argc,argv);
	duplicate = exObj.ifDuplicate(argc, argv);
	if (duplicate == true)
	{
		std::set<std::string> duplifiles;
		duplifiles = fm.locatingDuplicateFiles(ds);
		disObj.displayDuplicateFiles(duplifiles);
	}
	if (recurse == true)
		fm.recursiveSearch();
	else
		fm.search();

	disObj.displayCatalogue(ds,recurse);

	
	std::set < std::string > MatchingSet;
	for (int i = 1; ((i < argc)); i++) {
		std::string sw = argv[i];

		if (sw.find('/f', 0) != -1) {
			std::string sub2 = sw.substr(2, sw.size() - 2);

			MatchingSet = fm.stringSearch(ds, sub2,recurse);
			disObj.displayStringFileMatch(MatchingSet);

		}
	}
	disObj.displayUserDefinedSearch();
	return 0;
	std::getchar();
}
