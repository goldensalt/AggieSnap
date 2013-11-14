class imageInput {
	string loc, name, extension, id;
	int type = 0;
	public:
		string getID() { return id; }
		int acceptInput();
		string getLoc() { return loc; }
		int getType() { return type; }
		string getName() { return name; }
		string getExtension() { return extension; }
		void printInfo();
		void addEntry();
	private:
		bool validExtension(string);
		void setAttributes(string);
		int saveImage();
};