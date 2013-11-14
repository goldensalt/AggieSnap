all:
	-@rm aggiesnap
	echo "Compiling source files..."
	-@g++-4.7 -std=c++11 aggiesnap.cpp global.cpp imageInput.cpp imageOutput.cpp -o aggiesnap

test:
	-@rm test
	+@echo "Compiling source files..."
	-@g++-4.7 -std=c++11 test.cpp global.cpp imageInput.cpp imageOutput.cpp -o test
clear:
	-@rm -rf images/*; rm db; touch db; rm counter; echo "1" >> counter;
