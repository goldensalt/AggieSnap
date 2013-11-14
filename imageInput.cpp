#include "global.h"

// Asks the user for an input file and accept it if extension is valid.
int imageInput::acceptInput() {
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

	// Set the value of the imageInput's name and extension
	setAttributes(loc);

	// Download / copy file from URL or local
	error = saveImage();

	// If there was an error while copying/downloading image
	if (error != 0) {
		return error;
	}

	// Input new entry into image database
	addEntry();

	return 0;


}

// Checks the file for a valid extension and also updates value of object's extension
bool imageInput::validExtension(string file) {
	int pos = 1;
	string section, ext;
	vector <string>exts = {"jpg", "gif", "jpeg", "bm", "bmp", "pbm", "pgm", "png", "ppm", "xbm", "xpm"};

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

	for (int i = 0; i < exts.size(); ++i) {
		if (strtolower(ext) == exts[i]) {
			return 1;
		}
	}
	return 0;
}

// Sets the values of the imageInput's name and extension
void imageInput::setAttributes(string file) {
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

				// Set imageInput's extension
				this->extension = ext;
			}

			// Record filename
			if (section.substr(0, 1) == "/" || pos == file.length()) {
				name = section.substr(1, section.length()-ext.length()-2);

				// Set imageInput's name
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

	// Set image ID
	id = to_string(currentCount());
}

// save the image
int imageInput::saveImage() {
	string command;
	int error = 0;

	// if imageInput is a URL, download from internet
	if (getType() == 0) {
		command = "wget --no-check-certificate " + getLoc() + " -O images/" + getID() + "." + getExtension() + " >/dev/null 2>&1";
	} else  {
		// copy local file
		command = "cp " + getLoc() +  " images/" + getID() + "." + getExtension() + " >/dev/null 2>&1";
	}

	// Execute command
	error = system(command.c_str());

	// Error downloading from URL
	if (error != 0 && getType() == 0) {
		// remove file that is downloaded since it is invalid
		command = "rm images/" + getID() + "." + getExtension();
		system(command.c_str());

		return 2;
	}

	// Error copying local file
	if (error != 0 && getType() == 1) {
		return 3;
	}

	// Update counter
	updateCount();

	return 0;
}

// print image info
void imageInput::printInfo() {
	cout << "------\nlocation:\t" << loc << "\nname:\t" << name << "\nextension:\t" << extension << "\ntype:\t" << type << "\n------" << endl;
}

// Add image to db
void imageInput::addEntry() {
	// Update value of counter
	ofstream db("db", ios::app);
	if (db.is_open()) {
		// 1^reveilleVIII.jpg^1029475849^null^tag1^tag2^tag3^tag4^tag5
		db << getID() << "^" << getName() << "^" << getExtension() << "^" << time(0) << "^" << getLoc() << "^^^^^^\n";
		db.close();
	}
}