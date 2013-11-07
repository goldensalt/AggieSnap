#include <iostream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

// Detects if image contains a valid extension
bool validExtension(string);
void downloadImage(string);
void addEntry(string, string, string, string, string, string, string, string);
void updateCount();
int currentCount();