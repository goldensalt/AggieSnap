class imageInput {
	string loc, name, extension, id;
	int type = 0;
	public:
		int acceptInput();
		void printInfo();
		void addEntry();
		string getID() { return id; }
		string getLoc() { return loc; }
		int getType() { return type; }
		string getName() { return name; }
		string getExtension() { return extension; }
	private:
		bool validExtension(string);
		void setAttributes(string);
		int saveImage();
};