#include "global.h"

// Asks the user for an input file and accept it if extension is valid.
int fileObject::acceptInput() {
	int error = 0;
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

	// Download / copy file from URL or local
	error = this->getImage();

	// If there was an error while copying/downloading image
	if (error != 0) {
		return error;
	}

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

int fileObject::getImage() {
	string command;
	int error = 0;

	// if fileObject is a URL, download from internet
	if (this->getType() == 0) {
		command = "wget " + this->getLoc() + " -O images/" + to_string(currentCount()) + "." + this->getExtension() + " >/dev/null 2>&1";
	} else  {
		// copy local file
		command = "cp " + this->getLoc() +  " images/" + to_string(currentCount()) + "." + this->getExtension() + " >/dev/null 2>&1";
	}

	// Execute command
	error = system(command.c_str());

	// Error downloading from URL
	if (error != 0 && this->getType() == 0) {
		return 2;
	}

	// Error copying local file
	if (error != 0 && this->getType() == 1) {
		return 3;
	}

	// Update counter
	updateCount();

	return 0;
}

void fileObject::printInfo() {
	cout << "------\nLocation:\t" << loc << "\nName:\t" << name << "\nExtension:\t" << extension << "\nType:\t" << type << "\n------" << endl;
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