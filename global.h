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
using namespace std;

int currentCount();
void updateCount();
string strtolower(string);
imageOutput getImage(int);
vector<int> searchImages(int, string);