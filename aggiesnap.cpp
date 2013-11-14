// All of our header files and function definitions
#include "global.h"

int main() {
	int total = 0, error = 0;
	imageInput image;

	cout << "Enter \"done\" when you are finished adding images" << endl << endl;
	do {
		error = image.acceptInput();

		if (image.getLoc() == "done") {
			break;
		}

		// Error codes
		// Invalid extension
		if (error == 1) {
			cerr << "Error: invalid image extension." << endl << endl;
		} else if (error == 2) {
			// invalid url
			cerr << "Error: unable to download image from supplied URL." << endl << endl;
		} else if (error == 3) {
			cerr << "Error: unable to find local image from supplied location." << endl << endl;
		}

		if (image.getLoc() != "done" && error == 0) {
			cout << image.getName() << "." << image.getExtension() << " has been added to the image database!" << endl << endl;
			++total;
		}

		//image.printInfo();
	} while (1);

	cout << "\n" << total << " picture(s) have been added to the image database!" << endl;
}