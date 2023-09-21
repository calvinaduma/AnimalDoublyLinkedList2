run: compile
	./P2 animals.txt
compile:
	g++ -g -std=c++11 dll_list.cpp mainDriver.cpp dll_list.h animal.h animal.cpp -o P2 -Wall
clean:
	rm P2
