#ifndef FINALDISPLAY_H
#define FINALDISPLAY_H
/////////////////////////////////////////////////////////////////////////////
// FinalDisplay.h - Used to display all the information according		   //
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
*
*This package helps in displaying the information according to the user inputs parsed
*

*  Maintenance History:
* ----------------------
*  Ver 1.0 : 8 Feb 15
*  - first release
*/
 
#include "../DataStore/DataStore.h"
#include "../DataStore/DataStore.cpp"

#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>
#include <string>
class FinalDisplay
{
public :
	void displayCatalogue(DataStore ds,bool recurse);
	void displayStringFileMatch(std::set < std::string > textset);
	void displayDuplicateFiles(std::set<std::string> duplifiles, std::set<std::string> repeatedFilesPath);
};
#endif
