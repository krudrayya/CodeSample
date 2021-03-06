// FileMgr.cpp

#include "FileMgr.h"
#include "../DataStore/DataStore.h"
#include <iostream>

int main()
{
  DataStore ds;
  FileMgr fm(".", ds);
  fm.addPattern("*.h");
  fm.addPattern("*.partial");
  fm.search();
  for (auto fs : ds)
  {
    std::cout << "\n  " << fs;
  }
  std::cout << "\n\n";
  return 0;
}