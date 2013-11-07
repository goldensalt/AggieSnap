// This file contains all of the definitions to the functions that we will reference
#include "std_lib_facilities_3.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int currentCount();
void updateCount();

class fileObject {
		string loc, name, extension;
		int type;
	public:
		int acceptInput();
		string getLoc() { return loc; }
		int getType() { return type; }
		string getName() { return name; }
		string getExtension() { return extension; }
		void printInfo();
	private:
		bool validExtension(string);
		void setFileAttributes(string);
		int getImage();
};