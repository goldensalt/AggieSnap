// All of our header files and function definitions
#include "global.h"

int main() {
	int total = 0, error = 0;
	fileObject file;

	cout << "Enter \"done\" when you are finished adding images" << endl << endl;
	do {
		error = file.acceptInput();

		if (file.getLoc() == "done") {
			break;
		}

		// Error codes
		// Invalid extension
		if (error == 1) {
			cerr << "Error: invalid file extension." << endl << endl;
		} else if (error == 2) {
			// invalid url
			cerr << "Error: unable to download file from supplied URL." << endl << endl;
		} else if (error == 3) {
			cerr << "Error: unable to find local file from supplied location." << endl << endl;
		}

		if (file.getLoc() != "done" && error == 0) {
			cout << file.getName() << "." << file.getExtension() << " has been added to the image database!" << endl << endl;
			++total;
		}

		//file.printInfo();
	} while (1);

	cout << "\n" << total << " picture(s) have been added to the image database!" << endl;
}