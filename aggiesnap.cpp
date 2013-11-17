// Header and function definitions
#include "global.h"

int main() {
	// Init. vars
	int total = 0, error = 0;
	bool done = false;
	imageInput image;

	// GUI stuff eventually
	cout << "Enter \"done\" when you are finished adding images" << endl << endl;
	do {
		// Get error level that is returned
		error = image.acceptInput();

		if (image.getLoc() == "done") {
			done = true;
		}

		// Error codes
		// Invalid extension
		switch (error) {
			case 0:
				// No error occured
				break;
			case 1:
				cerr << "Error: Invalid image extension." << endl << endl;
				break;
			case 2:
				cerr << "Error: Unable to download image from supplied URL." << endl << endl;
				break;
			case 3:
				cerr << "Error: Unable to find local image from supplied location." << endl << endl;
				break;
			default:
				cerr << "Error: Unknown error." << endl << endl;

		}

		// If user hasn't finished adding images and no error occured, report image has been added and increment total
		if (image.getLoc() != "done" && error == 0) {
			cout << image.getName() << "." << image.getExtension() << " has been added to the image database!" << endl << endl;
			++total;
		}

	} while (!done);

	// Report final number of images added to database
	cout << "\n" << total << " picture(s) have been added to the image database!" << endl;
}