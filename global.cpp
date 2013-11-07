#include "global.h"

// Asks the user for an input file and accept it if extension is valid.
int fileObject::acceptInput() {
	cout << "Please enter a URL or local picture filename: ";
	cin >> loc;

	// Determines if file is a local file or a URL
	if ((loc.substr(0, 7) == "http://" || loc.substr(0, 8) == "https://") || loc.substr(0, 4) == "www.") {
		type = 0;
	} else {
		// local file
		type = 1;
	}

	// Invalid extension
	if (!validExtension(loc)) {
		return 1;
	}

	// Set the value of the fileObject's name and extension
	setFileAttributes(loc);


	return 0;


}

// Checks the file for a valid extension and also updates value of object's extension
bool fileObject::validExtension(string file) {
	int pos = 1;
	string section, ext;
	string exts[] = {"jpg", "gif", "jpeg", "JPG", "GIF", "JPEG"};

	while (1) {
		try {
			section = file.substr(file.length()-pos, pos);

			// Record filename's extension
			if (section.substr(0, 1) == ".") {
				ext = section.substr(1, section.length() - 1);
				break;
			}
			pos++;
		} catch (exception &e) {
			return 0;
		}
	}

	for (int i = 0; i < 6; ++i) {
		if (ext == exts[i]) {
			return 1;
		}
	}
	return 0;
}

// Sets the values of the fileObject's name and extension
void fileObject::setFileAttributes(string file) {
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

				// Set fileObject's extension
				this->extension = ext;
			}

			// Record filename
			if (section.substr(0, 1) == "/" || pos == file.length()) {
				name = section.substr(1, section.length()-ext.length()-2);

				// Set fileObject's name
				this->name = name;
				break;
			}

			// increment position if period not found
			pos++;
		} catch (exception &e) {
			cerr << e.what() << endl;
			exit (EXIT_FAILURE);
		}
	}
}

void fileObject::printInfo() {
	cout << "------\nLocation:\t" << loc << "\nName:\t" << name << "\nExtension:\t" << extension << "\nType:\t" << type << "\n------" << endl;
}