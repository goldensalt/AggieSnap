#include "global.h"

// Set all of the values of the imageOutput object
void imageOutput::setAttributes(int id, string name, string ext, int date, string loc, string tag_one, string tag_two, string tag_three, string tag_four, string tag_five) {
	this->id = id;
	this->name = name;
	this->ext = ext;
	this->date = date;
	this->loc = loc;
	tag.push_back(tag_one);
	tag.push_back(tag_two);
	tag.push_back(tag_three);
	tag.push_back(tag_four);
	tag.push_back(tag_five);

}

// print image info
void imageOutput::printInfo() {
	cout << "------" << endl;
	cout << "id:\t\t" << id << endl;
	cout << "name:\t\t" << name << endl;
	cout << "Extension:\t" << ext << endl;
	cout << "date:\t\t" << date << endl;
	cout << "loc:\t\t" << loc << endl;
	cout << "tag 1:\t\t" << tag[0] << endl;
	cout << "tag 2:\t\t" << tag[1] << endl;
	cout << "tag 3:\t\t" << tag[2] << endl;
	cout << "tag 4:\t\t" << tag[3] << endl;
	cout << "tag 5:\t\t" << tag[4] << endl;
	cout << "------" << endl;
}
