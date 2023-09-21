/*  Calvin Aduma | caduma
    CPSC 1020 | Fall 2020
    C. Kittlestad
    11/26/20
    Project 2
*/

#include "animal.h"
#include "dll_list.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	string filename = argv[1], animalName;
	ifstream readfile (filename);
	int choice, loop;
	loop = 1;
 	List listPtr;
  	listPtr.setHead(NULL);
  	listPtr.setTail(NULL);
  	listPtr.setSize(0);
	while (loop) {
		choice = listPtr.printMenu();
    		while (choice<1 || choice>9) {
      			cout << "You must select a number 1-9 from the list!" << endl;
      			choice = listPtr.printMenu();
    		}
		switch (choice) {
			case 1:
				listPtr.initializeFromFile(readfile);
				break;
			case 2:
				listPtr.addToFront();
				break;
			case 3:
				listPtr.addToRear();
				break;
			case 4:
				cout << "Enter the name of the animal you want to delete:\t";
				cin >> animalName;
				cout << endl << endl;
				listPtr.deleteAnimal(animalName);
				break;
			case 5:
				listPtr.searchByType();
				break;
			case 6:
				listPtr.searchByName();
				break;
			case 7:
				cout << "There are " << listPtr.getSize() << " animals.\n\n";
				break;
			case 8:
				listPtr.printList();
				break;
			case 9:
				loop = 0;
		}
	}
	return 0;
}
