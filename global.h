// This file contains all of the definitions to the functions that we will reference
#include "lib/std_lib_facilities_3.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class imageOutput {
	int id = 0, date = 0;
	string name, ext, loc;
	vector<string> tag;
};

int currentCount();
void updateCount();
string strtolower(string);
imageOutput getImage(int);