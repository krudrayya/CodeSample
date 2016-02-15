#ifndef FILEMGR_H
#define FILEMGR_H
/////////////////////////////////////////////////////////////////////////////
// FileMgr.h - Based on the input given ,the path is parsed to get         //
//the set of files to be analysed                                          //                    
//                                                                         //
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
*This package Based on the input given ,the path is parsed to get the set of 
* files to be analysed 
*

*  Maintenance History:
* ----------------------
*  Ver 1.0 : 8 Feb 15
*  - first release
*/
#include "FileSystem.h"
#include "../DataStore/DataStore.h"
#include "../DataStore/DataStore.cpp"
#include <iostream>

class FileMgr
{
public:
  using iterator = DataStore::map_iter;
  using patterns = std::vector<std::string>;

  FileMgr(const std::string& path, DataStore& ds) : path_(path), store_(ds)
  {
    patterns_.push_back("*.*");
  }
  //function to add patterns to the patterns list
  void addPattern(const std::string& patt)
  {
    if (patterns_.size() == 1 && patterns_[0] == "*.*")
      patterns_.pop_back();
    patterns_.push_back(patt);
  }

  //to search for files  recursively
  void recursiveSearch() {
	  recurviseFind(path_);
  }

  //to search for files non recursively
	 void search() {
		 try{
			 for (auto patternName : patterns_) {
				 std::set<std::string> iterPaths;
				 std::vector<std::string> files = FileSystem::Directory::getFiles(path_, patternName);
				 std::vector<std::string> resultDirs = FileSystem::Directory::getDirectories(path_, "*.*");

				 for (auto reDIr : resultDirs)
				 {
					 if (reDIr != "." && reDIr != "..")
						 store_.saveset(FileSystem::Path::getFullFileSpec(path_) + "\\" + reDIr);
				 }
				  
				 for (auto f : files) {
					store_.addMap(f, FileSystem::Directory::getCurrentDirectory());
				 } }}
		 catch (...) {
			 std::cout << "file not found";
		 }
  }


   //to find the files recursively
  void recurviseFind(const std::string &userPath) {

	  try{
		   
		  for (auto patternName : patterns_) {
			  std::vector<std::string> resultFiles = FileSystem::Directory::getFiles(userPath, patternName);
			  for (auto fileName : resultFiles) {
				  store_.addMap(fileName, FileSystem::Path::getFullFileSpec(userPath));
			  }
			  std::vector<std::string> resultDirectries = FileSystem::Directory::getDirectories(userPath, "*.*");
			  std::vector<std::string> resultPaths;
			  for (auto resPaths : resultDirectries)
			  {
				  if (resPaths != "." && resPaths != "..")
					  resultPaths.push_back(FileSystem::Path::getFullFileSpec(userPath) + "\\" + resPaths);
			  }
			  for (auto recurseDir : resultPaths)
				  recurviseFind(recurseDir);
		  }
	  }
	  catch (...)
	  {
		  std::cout << "file not found";
	  }
  }


  //function to search for a given string by user in various files
  std::set < std::string >  stringSearch(DataStore ds, const std::string givenInput,bool recurse){

	  std::set < std::string > paths, pathresult;
	  for (auto store1 : ds)
		  for (auto round1 : store1.second)
			  if (recurse==true)
			  paths.insert(*round1+"\\" + store1.first);
			  else
				  paths.insert(*round1);
	  for (auto store2 : paths)
	  {
		  FileSystem::File resultFile(store2);
		  resultFile.open(FileSystem::File::in);
		  std::string info = resultFile.readAll(true);
		  int result = info.find(givenInput);

		  if (result != -1)
		  {
			  pathresult.insert(resultFile.name());
		  }
	  }

	  return pathresult;
  }

  //stores a list of duplicate files
  std::set < std::string >  locatingDuplicateFiles(DataStore Checkds){
	  std::set < std::string > files;
	  for (auto iter : Checkds){
		  if ((iter.second).size() > 1)
			  files.insert(iter.first);
		   
	  }
	  return files;
  }
  //stores a list of duplicate file's  paths 
  std::set < std::string >  locatingDuplicateFilePath(DataStore Checkds){
	   
	  std::set <std::string > filePath;
	  for (auto iter : Checkds){
		  if ((iter.second).size() > 1)
			  for (auto iter1 : iter.second)
			  filePath.insert(*iter1);
	  }
	  return filePath;
  }
   
private:
  std::string path_;
  DataStore& store_;
  patterns patterns_;
};

#endif
