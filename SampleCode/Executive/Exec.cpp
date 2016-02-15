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
		if (userInput == "/s" || userInput=="/S") {
			return true;
			break;
		}
		else
		{
			i++;
			
		}
		
	}
	return false;
	
}
//to check if user has asked to display duplicate files
bool Exec::ifDuplicate(int argc, char *argv[])
{
	int i = 1;
	while (i < argc){
		std::string userInput = argv[i];
		if (userInput == "/d" || userInput=="/D") {
			return true;
			break;
		}
		else
		{
			i++;
			
		}
	}
	return false;
}

//used to extract the files based on string input given by user 
int Exec::displayUserDefinedSearch(FileMgr fm, DataStore ds)
{
	std::string n;
	std::set < std::string > textset;


MatchingFiles:
	std::cout << "\n Enter any text to search :";
	std::getline(std::cin, n);
	if (n == ""){
		goto endloop;
	}
	else if (n != "")
	{
		std::vector<std::string> bits, pattern, stext;


		std::istringstream iStringInput(n);
		copy(std::istream_iterator<std::string>(iStringInput),
			std::istream_iterator<std::string>(),
			back_inserter(bits));
		int count = 0, tmpcount = 0;
		for (auto ab : bits)
			if (ab.front() == '"' || ab.back() == '"')
				count++;

		for (auto check : bits){
			if (check[0] == '"'){
				pattern.push_back(check);
				tmpcount++;
			}
			else if (check.back() == '"')
			{
				pattern.back() = pattern.back() + " " + check;
				tmpcount++;


			}
			else if (pattern.size()>0 && tmpcount < count)
			{
				pattern.back() = pattern.back() + " " + check;

			}
		}
		for (auto tok : pattern)
		{
			if (tok[0] == '"' && tok[1] != '*' && tok[2] != '.'){
				std::string sub3 = tok.substr(1, tok.size() - 2);
				textset = fm.stringSearch(ds, sub3, true);
			}

			for (auto bits1 : bits){
				if (bits1[0] == '*' && bits1[1] == '.')
				{
					std::string sub3 = bits1.substr((bits1.find(".") + 1), bits1.size() - (bits1.find(".")));

					for (auto fs1 : textset)

					{
						std::string token = fs1.substr((fs1.find(".") + 1), (fs1.size() - (fs1.find("."))));
						if (token == sub3 || sub3 == "*")
							std::cout << fs1 << "\n";
					}
				}
		}
}
		goto MatchingFiles;
	}

endloop:
	return 0;
}
int main(int argc, char *argv[])
{
	DataStore ds;
	Exec exObj;
	FinalDisplay disObj;
	bool recurse=false,duplicate = false;
	std::string p = argv[1];
	FileMgr fm(p, ds);
	for (int i = 1; i < argc; i++){
		std::string s = argv[i];
		
		if (s == "*.h" || s== "*.cpp" || s == "*.*" || s == "*.txt"){
			fm.addPattern(argv[i]);
		}
	}
	
	recurse = exObj.ifRecursive(argc,argv);
	duplicate = exObj.ifDuplicate(argc, argv);
	
	if (recurse == true)
		fm.recursiveSearch();
	else
		fm.search();

	disObj.displayCatalogue(ds,recurse);

	if (duplicate == true){
		std::set<std::string> repeatedFiles, repeatedFilesPath;
		repeatedFiles = fm.locatingDuplicateFiles(ds);
		repeatedFilesPath = fm.locatingDuplicateFilePath(ds);
		disObj.displayDuplicateFiles(repeatedFiles, repeatedFilesPath);
	}
	
	std::set < std::string > MatchingSet;
	for (int i = 1; ((i < argc)); i++) {
		std::string sw = argv[i];

		if (sw.find("/f", 0) != -1 || sw.find("/F",0)!=-1) {
			std::string sub2 = sw.substr(2, sw.size() - 2);

			MatchingSet = fm.stringSearch(ds, sub2,recurse);
			disObj.displayStringFileMatch(MatchingSet);

		}
	}
	exObj.displayUserDefinedSearch(fm,ds);
	return 0;
	std::getchar();
}
