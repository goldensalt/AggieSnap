all:
	rm -rf images/*; rm db; touch db; rm counter; echo "1" >> counter;
	-@rm aggiesnap
	g++-4.7 -std=c++11 aggiesnap.cpp global.cpp imageInput.cpp -o aggiesnap