class imageOutput {
	int type = 0, id = 0, date = 0;;
	string loc, name, extension;
	vector<string> tag;
	public:
		void setAttributes(int, string, string, int, string, string, string, string, string, string);
		void printInfo();

		// Get functions
		string getLoc() { return loc; }
		string getName() { return name; }
		string getExtension() { return extension; }
		int getID() { return id; }
		int getDate() { return date; }
		string getTag(int num) { return tag[(num-1)]; }
};