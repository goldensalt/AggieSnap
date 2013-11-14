#include "global.h"

int currentCount() {
	// Get current value of counter
	string line;
	int count = 0;
	ifstream current("counter");
	if (current.is_open()) {
		getline(current, line);
		count = atoi(line.c_str());
		current.close();
	}
	return count;
}

void updateCount() {
	// Get current value of counter
	int count = currentCount();

	// Update value of counter
	++count;
	ofstream update("counter");
	if (update.is_open()) {
		update << count;
		update.close();
	}
}

string strtolower(string str) {
	for (int i = 0; i < str.length(); ++i) {
		str[i] = tolower(str[i]);
	}

	return str;
}

imageOutput getImage(int id) {
	string line;
    ifstream db("db");
    vector<string> data;
    bool found = false;
    imageOutput image;

    // If file opened successfully
    if (db) {
    	// get each line of file
    	while (getline(db, line) && found == false) {
    		int offset = 0, pos = 0;
    		// While it keeps finding delimeters
    		while (line.find("^", offset) != string::npos) {
    			pos = line.find("^", offset);

    			// Check to see if id matches id being searched for. If not, break out of current search and look in next string
    			if (line.substr(offset, pos-offset) != to_string(id)) {
    				break;
    			}

    			data.push_back(line.substr(offset, pos-offset));
    			offset = pos+1;
    			found = true;
    		}
    	}
    }
	db.close();

	// If it found a match, store data into imageObject
	if (found) {

	}
	return image;
}