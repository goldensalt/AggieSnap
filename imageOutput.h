class imageOutput {
	int type = 0, id = 0, date = 0;;
	string loc, name, extension;
	vector<string> tag;
	public:
		void setAttributes(int, string, string, int, string, string, string, string, string, string);
		void printInfo();

		// Get functions
		int getID() { return id; }
		string getName() { return name; }
		string getExtension() { return ext; }
		int getDate() { return date; }
		string getLoc() { return loc; }
		string getTag(int num) { return tag[(num-1)]; }
};