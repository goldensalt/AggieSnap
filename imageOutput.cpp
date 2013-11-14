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
	cout << "------\nid:\t" << id << "\nname:\t" << name << "\eExtension:\t" << ext << "\ndate:\t" << date << "\nloc:\t" << loc << "\ntag 1:\t" << tag[0] << "\ntag 2:\t" << tag[1] << "\ntag 3:\t" << tag[2] << "\ntag 4:\t" << tag[3] << "\ntag 5:\t" << tag[4] << "\n------" << endl;
}