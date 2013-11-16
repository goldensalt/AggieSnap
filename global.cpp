// Header and function definitions
#include "global.h"

// Get current value of counter
int currentCount() {
	string line;
	int count = 0;
	ifstream current("counter");
	if (current.is_open()) {
		getline(current, line);
		count = stoi(line);
		current.close();
	}
	return count;
}

// Update value of counter
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

// Convert a string to lowercase
string strtolower(string str) {
	for (auto i = 0; i < str.length(); ++i) {
		str[i] = tolower(str[i]);
	}
	return str;
}

// Return image object of image based on id
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

	// If it found a match, set all the values of the image object else return a null image object
	if (found) {
		image.setAttributes(stoi(data[0]), data[1], data[2], stoi(data[3]), data[4], data[5], data[6], data[7], data[8], data[9]);
	} else {
		image.setAttributes(0, "", "", 0, "", "", "", "", "", "");
	}
	return image;
}

// Return a vector of image IDs that match specified search parameters
vector<int> searchImages(int mode, string text) {
	vector<int> results;
	switch (mode) {
		// Search by ID
		case SEARCH_ID:
			// Cycle through all of the images
			for (auto i = 1; i < currentCount(); ++i) {
				imageOutput check = getImage(i);
				if (check.getID() == stoi(text)) {
					results.push_back(i);
				}
			}
			break;
		// Search by filename
		case SEARCH_NAME:
			// Cycle through all of the images
			for (auto i = 1; i < currentCount(); ++i) {
				imageOutput check = getImage(i);
				if (check.getName() == text) {
					results.push_back(i);
				}
			}
			break;
		// Search by extension
		case SEARCH_EXT:
			// Cycle through all of the images
			for (auto i = 1; i < currentCount(); ++i) {
				imageOutput check = getImage(i);
				if (strtolower(check.getExtension()) == text) {
					results.push_back(i);
				}
			}
			break;
		// Search by filename.extension
		case SEARCH_NAME_EXT:
			// Cycle through all of the images
			for (auto i = 1; i < currentCount(); ++i) {
				imageOutput check = getImage(i);
				if (check.getName() + "." + strtolower(check.getExtension()) == text) {
					results.push_back(i);
				}
			}
			break;
		// Search by tag
		case SEARCH_TAG:
			// Cycle through all of the images
			for (auto i = 1; i < currentCount(); ++i) {
				imageOutput check = getImage(i);
				if (check.getTag(1) == text || check.getTag(2) == text || check.getTag(3) == text || check.getTag(4) == text || check.getTag(5) == text) {
					results.push_back(i);
				}
			}
			break;
	}
	return results;
}