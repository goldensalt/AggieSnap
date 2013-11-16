#include "global.h"
using namespace std;

int main(int argc, char *argv[]) {
	imageOutput test = getImage(atoi(argv[1]));
	test.printInfo();
}
