class imageOutput {
	int id = 0, date = 0;
	string name, ext, loc;
	vector<string> tag;
	public:
		void printInfo();
		void setAttributes(int, string, string, int, string, string, string, string, string, string);
		int getID() { return id; }
		string getName() { return name; }
		string getExtension() { return ext; }
		int getDate() { return date; }
		string getLoc() { return loc; }
		string getTag(int num) { return tag[(num-1)]; }
};