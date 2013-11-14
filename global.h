// This file contains all of the definitions to the functions that we will reference
#include "lib/std_lib_facilities_3.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class imageInput {
	string loc, name, extension, id;
	int type = 0;
	public:
		int acceptInput();
		void printInfo();
		void addEntry();
		string getID() { return id; }
		string getLoc() { return loc; }
		int getType() { return type; }
		string getName() { return name; }
		string getExtension() { return extension; }
	private:
		bool validExtension(string);
		void setAttributes(string);
		int saveImage();
};

class imageOutput {
	int id = 0, date = 0;
	string name, ext, loc;
	vector<string> tag;
	public:
		void printInfo();
		void setAttributes(int, string, string, int, string, string, string, string, string, string);
		int getID() { return id; }
		string getName() { return name; }
		string getExtension() { return ext; }
		int getDate() { return date; }
		string getLoc() { return loc; }
		string getTag(int num) { return tag[(num-1)]; }
};

int currentCount();
void updateCount();
string strtolower(string);
imageOutput getImage(int);
vector<int> searchImages(int, string);