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
	for (auto i = 0; i < str.length(); ++i) {
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
    			if (line.substr(offset, pos-offset) != to_string(id) && found == false) {
    				break;
    			}

    			data.push_back(line.substr(offset, pos-offset));
    			offset = pos+1;
    			found = true;
    		}
    	}
    }
	db.close();

	// If it found a match, set all the values of hte image object
	if (found) {
		image.setAttributes(atoi(data[0].c_str()), data[1], data[2], atoi(data[3].c_str()), data[4], data[5], data[6], data[7], data[8], data[9]);
	} else {
		image.setAttributes(0, "", "", 0, "", "", "", "", "", "");
	}
	return image;
}

vector<int> searchImages(int mode, string text) {
	vector<int> results;
	switch (mode) {
		// Search by ID
		case 1:
			for (auto i = 1; i < currentCount(); ++i) {
				imageOutput check = getImage(i);
				if (check.getID() == atoi(text.c_str())) {
					results.push_back(i);
				}
			}
			break;
	}
}