#include "global.h"
using namespace std;

int main(int argc, char *argv[]) {
	vector<int> results = searchImages(SEARCH_TAG, "canine");

	for (int a = 0; a < results.size(); ++a) {
		imageOutput out = getImage(results[a]);
		out.printInfo();
	}
}
