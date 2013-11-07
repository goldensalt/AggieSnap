#include "global.h"

int main() {
	string file;
	
	while (file != "done") {
		cout << "Please enter picture file name: ";
		cin >> file;
		
		if (validExtension(file))
			cout << "Please Enter a Valid File Name.\n";
		
		string comand = "mv " + str + " images/" + currentCount() + "." + str3;
		system(command.c_str());
		updateCount();
	}
}