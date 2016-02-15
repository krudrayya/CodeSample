/////////////////////////////////////////////////////////////////////////////
// FileMgr.cpp - Based on the input given ,the path is parsed to get the set // 
// of files to be analysed                                                 //
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

#include "FileMgr.h"
#include "../DataStore/DataStore.h"
 
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>





//----< test stub >--------------------------------------------------------
#ifdef TEST_FILEMGR
int main(int argc, char *argv[])
{
  DataStore ds;
  
  bool recurse = false;
  int i = 1;
  FileMgr fm(".", ds);
  for (int i = 0; i < argc; i++)
  {

  }
   while(  i < argc){
	  std::string userInput = argv[i];
	  if (userInput == "/s") {
		  recurse = true;
		  break;
	  }
	  else
		  recurse = false;
	  i++;
  }
  if (recurse == true)
	  fm.recursiveSearch();
  else
	  fm.search();

  //disObj.displayCatalogue(ds);
  return 0;
}
#endif