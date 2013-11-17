#include "global.h"
using namespace std;

int main(int argc, char *argv[]) {
	imageOutput out = getImage(stoi(argv[1]));
	out.printInfo();
	/*
	time_t rawtime = 1384640064;
	struct tm *timeinfo;
	char buffer [80];

	timeinfo = localtime (&rawtime);

	strftime (buffer,80,"Now it's %I:%M%p.",timeinfo);
	puts (buffer);

	return 0;
	*/
}
