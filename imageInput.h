class imageInput {
	int type = 0, id = 0;
	string loc, name, extension;
	public:
		int acceptInput();
		void printInfo();
		void addEntry();

		// Get functions
		string getLoc() { return loc; }
		string getName() { return name; }
		string getExtension() { return extension; }
		string getID() { return id; }
		int getType() { return type; }
	private:
		bool validExtension(string);
		void setAttributes(string);
		int saveImage();
};