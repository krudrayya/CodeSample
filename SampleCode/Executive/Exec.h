#ifndef EXEC_H
#define EXEC_H


/////////////////////////////////////////////////////////////////////////////
// Exec.h -it acts like a central module which delegates the work and call // 
//             he required classes for doing various tasks                 //                       
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
*Exec.h-it acts like a central module which delegates the work and call 
*the required classes for doing various tasks.
*
*Based on the input given by user,the information is parsed and
*information is given to the fileMgr class to get the required files
*
*Based on requirement ,the information is displayed using Display class
*

*  Maintenance History:
* ----------------------
*  Ver 1.0 : 8 Feb 15
*  - first release
*/

#include "../FileMgr/FileMgr.h"

#pragma once
class Exec
{
public:
	bool ifRecursive(int argc, char *argv[]);
	bool ifDuplicate(int argc, char *argv[]);
	int displayUserDefinedSearch(FileMgr fm, DataStore ds);
//	void ifUserString(int argc, char *argv[], FinalDisplay fd, DataStore ds, FileMgr fm);
};

#endif