all:
	@echo "Compiling AggieSnap source files..."
	-@g++-4.7 -std=c++11 aggiesnap.cpp imageInput.cpp imageOutput.cpp global.cpp -o aggiesnap

test:
	@echo "Compiling test source files..."
	-@g++-4.7 -std=c++11 test.cpp global.cpp imageInput.cpp imageOutput.cpp -o test
clear:
	@echo "Resetting db, counter, and images folder..."
	-@rm -rf images/*; rm db; touch db; rm counter; echo "1" >> counter;
.PHONY: test
