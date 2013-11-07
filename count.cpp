#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void updateCount();
int currentCount();

int main() {
	updateCount();
	int blah = currentCount();
	cout << blah;
}

void updateCount() {
	// Get current value of counter
	string line;
	int count = 0;
	ifstream current("counter");
	if (current.is_open()) {
		getline(current, line);
		count = atoi(line.c_str());
		current.close();
	}
	// Update value of counter
	++count;
	ofstream update("counter");
	if (update.is_open()) {
		update << count;
		update.close();
	}
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