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

		if (file.getLoc() != "done" && error == 0) {
			cout << file.getName() << "." << file.getExtension() << " has been added to the image database!" << endl;
			++total;
		}
		// Error codes
		if (error == 1) {
			cerr << "Error: invalid file extension." << endl;
		}
		file.printInfo();
	} while (1);

	cout << "\n" << total << " picture(s) have been added to the image database!" << endl;
}