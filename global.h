// This file contains all of the definitions to the functions that we will reference
#include "std_lib_facilities_3.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

// Checks if the file has a valid Extension
bool validExtension(string);
// Returns the file's extension
string getExtension(string);
// Returns the file's name
string getName(string);
// Downloads the file from a URL and moves it into the images folder
void downloadImage(string);
// Adds the file data into the image db
void addEntry(string, string, string, string, string, string, string, string);
// Gets the current file ID count
int currentCount();
// Updates the file ID counter
void updateCount();