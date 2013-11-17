// This file contains all of the definitions to the functions that we will reference
#include "lib/std_lib_facilities_3.h"
#include "imageInput.h"
#include "imageOutput.h"
#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

// Constants for searchImages function
const int SEARCH_ID 		= 1;
const int SEARCH_NAME 		= 2;
const int SEARCH_EXT 		= 3;
const int SEARCH_NAME_EXT 	= 4;
const int SEARCH_TAG 		= 5;

// Local or URL file
const int FILE_LOCAL		= 0;
const int FILE_URL			= 1;

// Get current value of counter
int currentCount();
// Update value of counter
void updateCount();
// Convert a string to lowercase
string strtolower(string);
// Return image object of image based on id
imageOutput getImage(int);
// Return a vector of image IDs that match specified search parameters
vector<int> searchImages(int, string);