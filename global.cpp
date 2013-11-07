#include "global.h"

bool validExtension(string url) {
	int pos = 1;
	string section, ext;
	string exts[] = {"jpg", "gif", "jpeg", "JPG", "GIF", "JPEG"};

	while (1) {
		try {
			section = url.substr(url.length()-pos, pos);

			// Record filename's extension
			if (section.substr(0, 1) == ".") {
				ext = section.substr(1, section.length() - 1);
				break;
			}
			pos++;
		} catch (exception &e) {
			cerr << e.what() << endl;
			exit (EXIT_FAILURE);
		}
	}

	for (int i = 0; i < 6; ++i) {
		if (ext == exts[i]) {
			return 1;
		}
	}
	return 0;
}

string getExtension(string file) {
	// init vars
	int pos = 1;
	string section, ext;

	// Step backwards one character at a time until reach the first period.
	while (1) {
		try {
			section = file.substr(file.length()-pos, pos);

			// Record filename's extension
			if (section.substr(0, 1) == ".") {
				ext = section.substr(1, section.length() - 1);
				break;
			}

			// increment position if period not found
			pos++;
		} catch (exception &e) {
			cerr << e.what() << endl;
			exit (EXIT_FAILURE);
		}
	}

	// Return extension of file
	return ext;
}

string getName(string file) {
	// init vars
	int pos = 1;
	string section, ext, name;

	// Step backwards one character at a time until reach the first period.
	while (1) {
		try {
			section = file.substr(file.length()-pos, pos);

			// Record filename's extension
			if (section.substr(0, 1) == ".") {
				ext = section.substr(1, section.length() - 1);
				break;
			}

			// Record filename
			if (section.substr(0, 1) == "/") {
				name = section.substr(1, section.length()-ext.length()-2);
				break;
			}

			// increment position if period not found
			pos++;
		} catch (exception &e) {
			cerr << e.what() << endl;
			exit (EXIT_FAILURE);
		}
	}

	// Return name of file
	return name;
}

void downloadImage(string url) {
	int pos = 1;
	string section, ext, name, errorStatus;
	bool extFound = false, nameFound = false;

	while (1) {
		try {
			section = url.substr(url.length()-pos, pos);

			// Record filename's extension
			if (section.substr(0, 1) == "." && extFound == false) {
				ext = section.substr(1, section.length()-1);
				extFound = true;
			}

			// Record filename
			if (section.substr(0, 1) == "/" && nameFound == false) {
				name = section.substr(1, section.length()-ext.length()-2);
				nameFound = true;
				break;
			}
			pos++;
		} catch(exception &e) {
			cerr << e.what() << endl;
			exit (EXIT_FAILURE);
		}
	}
	string command = "wget " + url + " -O images/" + name + "." + 
ext + " > nul 2>&1";
	system(command.c_str());
}

void addEntry(string filename, string ext, string url, string tag_one, string tag_two, string tag_three, string tag_four, string tag_five) {
	//ID^file_name^ext^unixtimestamp^URL^tag1^tag2^tag3^tag4^tag5
	string sep = "^";
	ofstream db("db", ios::app);
	if (db.is_open()) {
		db << currentCount() << sep << filename << sep << ext << sep << time(0) << sep << url << tag_one << sep << tag_two << sep << tag_three << sep << tag_four << sep << tag_five << sep;
	}
	db.close();

	// update ID counter
	updateCount();

}

void updateCount() {
	// Get current value of counter
	string line;
	int count = 0;
	ifstream current("counter");
	if (current.is_open()) {
		getline(current, line);
		count = atoi(line.c_str());
		current.close();
	}
	// Update value of counter
	++count;
	ofstream update("counter");
	if (update.is_open()) {
		update << count;
		update.close();
	}
}

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