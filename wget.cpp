#include "wget.h"

int main() {
	string url;
	bool valid = false;

	do {
		cout << "URL: ";
		cin >> url;
		valid = validExtension(url);
	} while (!valid);

	// Download image and save to images folder
	downloadImage(url);
}