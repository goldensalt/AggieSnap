#include "global.h"

int main() {
	string str;

	while (str != "done") {
		cout << "Please enter picture file name:" << '\n';
		cin >> str;
		
		unsigned pos = str.find(".");
		string str3 = str.substr (pos);
		cout << str3 << '\n';
		
		if (validExtension(str))
			cout << "Please Enter a Valid File Name.\n";
		
		string comand = "mv " + str + " images/" + currentCount() + "." + str3;
		system(command.c_str());
		updateCount();
	}
}