/////////////////////////////////////////////////////////////////////////////
// FinalDisplay.cpp - Used to display all the information according        //
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



#include "FinalDisplay.h"
 
#include <string>
#include <iostream>
#include "../FileMgr/FileMgr.h"

//function used to display information of the catalogue
void FinalDisplay:: displayCatalogue(DataStore dataObj,bool recurse)
{
	 
	std::cout << "==========================================================";
	std::cout << "\n";
	std::cout << "               DISPLAYING CATALOGUE ";
	std::cout << "\n";
	std::cout << "==========================================================";
	std::cout << "\n";
	for (auto dob : dataObj){

		std::cout << "\n" << char(16) << " File Name: " << dob.first;
		for (auto iter1 : dob.second)
			std::cout << "\n Path ->  " << *(iter1) << "\n";
	}
	 
	std::cout << "\n" << "================================================================================================" << "\n";
	std::cout << "             SUMMARY "<<"\n";
	std::cout << "================================================================================================="<<"\n";
	int fcount = 0;
	for (auto p : dataObj)
		for (auto q : p.second)
			fcount++;
	std::cout << "Summary : " << fcount << " Files Found in  ";
	 
	 
	std::cout << dataObj.directoryCount() << " Directories  \n";
	 
}

//function displays the files where the user input string is found
void FinalDisplay::displayStringFileMatch(std::set < std::string > sampleSet){
	std::cout << "\n" << "------------<Displaying files where the string is found>-----------------------------------" << "\n\n";
	for (auto sample : sampleSet){
		std::cout << "\n" << char(16) << " File Name: " << sample;
			}
	std::cout << "\n\n" << "-------<End of displaying files where the string is found>-----------------------------" << "\n\n";
		}




//function displays list of duplicate files
void FinalDisplay::displayDuplicateFiles(std::set<std::string> repeatedFiles, std::set<std::string> repeatedFilesPath)
{
	std::cout << "\n" << "------------<Displaying duplicate files>-----------------------------------" << "\n\n";
	for (auto rf : repeatedFiles)
		std::cout << rf<<"\n";
	std::cout << "their paths" << "\n";
	for (auto rf : repeatedFilesPath)
		std::cout << rf << "\n";
	std::cout << "\n"<<"---------------------<end of displaying duplicate files>----------------------------------"<< "\n\n";
}


//----< test stub >--------------------------------------------------------
#ifdef TEST_FINALDISPLAY
int main()
{
	std::cout << "\n  Testing Display";

	DataStore ds;
	//FinalDisplay fisDis;

	std::cout << "==========================================================";
	std::cout << "\n";
	std::cout << "               DISPLAYING CATALOGUE ";
	std::cout << "\n";
	std::cout << "==========================================================";
	std::cout << "\n";
	for (auto dob : ds){

		std::cout << "\n" << char(16) << " File Name: " << dob.first;
		for (auto iter1 : dob.second)
			std::cout << "\n Path ->  " << *(iter1) << "\n";
	}

	std::cout << "\n" << "================================================================================================" << "\n";
	std::cout << "             SUMMARY " << "\n";
	std::cout << "=================================================================================================" << "\n";
	int fcount = 0;
	for (auto p : ds)
		for (auto q : p.second)
			fcount++;
	std::cout << "Summary : " << fcount << " Files Found in  ";


	for (auto item : ds)
	{
		// std::cout << "\n  " << item.c_str();
	}
	std::cout << "\n\n";
}
#endif
