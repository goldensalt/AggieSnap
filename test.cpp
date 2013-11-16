#include "global.h"
using namespace std;

int main(int argc, char *argv[]) {
	vector<int> results = searchImages(5, "dog");

	for (int a = 0; a < results.size(); ++a) {
		imageOutput out = getImage(results[a]);
		out.printInfo();
	}
}
