/*	Calvin Aduma | caduma
	CPSC 1020 | Fall 2020
	C. Kittlestad
	11/26/20
	Project 1
*/

// implementation file for dll_list.h

#include "dll_list.h"

using namespace std;

// constructor definition
List::List() {;}

// prints the Menu option
// inputs: none
// outputs: an integer from the selected menu
int List::printMenu() {
	int choice;
	cout << "1.\tinitialize list of animals from file" << endl;
	cout << "2.\tadd additional animal to front of list" << endl;
	cout << "3.\tadd additional animal to end of list" << endl;
	cout << "4.\tdelete animal" << endl;
	cout << "5.\tsearch animals by type\n";
	cout << "6.\tsearch animals by name\n";
	cout << "7.\tshow number of animals in list\n";
	cout << "8.\tprint animals\n";
	cout << "9.\tquit program\n" << endl;
	cout << "- - > ";
	cin >> choice;
	cout << endl;
	return choice;
}

// called from intializeFromFile(); call newAnimal() to create and initialize a new animal from the file;
// then adds it to end of list; increments the list size for each animal added
// input: address of file containing text
// output: void
void List::listInit (ifstream &inFile) {
	Animal *tempAnimal = new Animal;
	string name, type;
	int count = 0;
	while (!inFile.eof()){
		inFile >> type >> name; // reads and stores input
		tempAnimal->setType(type); // creates a template to be subbed into actual list
		tempAnimal->setName(name);
	//	tempAnimal->setNext(NULL);
	//	tempAnimal->setPrev(NULL);
		if (head==NULL) {
 			head = tempAnimal; // if null
		} else {
			tempAnimal->setPrev(head); // points to old head contents
			head = tempAnimal; // head now points to new and old contents
		}
		count++;
	}
	size = count;
	delete tempAnimal;
}

// calls listInit() sending the input file pointer (the file specified at the command-line)
// input: address of file containing text
// output: void
void List::initializeFromFile (ifstream &inFile) {
	if (size == 0) {
		listInit (inFile);
	} else {
		cout << "List is already initialized\n\n";
	}
}

// I think the purpose of this function is to create a pointer to a temporary animal skeleton
// input: address of a filestream
// output: Animal pointer
Animal* List::newAnimal (ifstream &inFile) {
	Animal *tempAnimal = new Animal;
	return tempAnimal;
}

// creates a new animal from user input and adds it to the front of the list
// input: none
// output: void
void List::addToFront () {
	string type, name;
	Animal *temporary = new Animal;
	cout << "Enter animal type:\t";
	cin >> type;
	cout << endl << "\nEnter animal name:\t";
	cin >> name;
	cout << endl << endl;
	temporary->setName(name);
	temporary->setType(type);
	temporary->setNext(head); // creation of temp animal struct for new animal to be added to front
	head = temporary; // head now equals new animal
	size++;
	delete temporary;
}

// creates a new animal from user input and adds it to the end of the list
// input: none
// output: void
void List::addToRear () {
	string type, name;
	cout << "Enter animal type:\t";
	cin >> type;
	cout << endl << "\nEnter animal name:\t";
	cin >> name;
	cout << endl << endl;
	Animal *temporary = new Animal;;
	temporary->setName(name);
	temporary->setType(type);
	temporary->setPrev(tail); // creation of temp animal strict for new animal to be added to rear
	temporary->setNext(NULL);
	tail = temporary; // tail equals new animal
	size++;
}

// deletes the animal with the aName that matches the parameter animalName; decrements list size;
// if list is empty, prints message that the list is empty
// input: one of the pointers in the structure list_t
// output: void
void List::deleteAnimal (string animalName) {
	Animal *temporary = new Animal;
	Animal *current = new Animal;
	if (isEmpty()==0){
		while (head != NULL) {
			if (animalName == head->getName()) { // match
				cout << endl << "\nDeleting animal: " << head->getType() << " " << head->getName() << endl << endl;
				current = temporary->getNextPointer(); // current equals the data after the animal selected
				temporary->setName(current->getName()); // transfer of data
				temporary->setType(current->getType());
				temporary->setPrev(head->getPrevPointer()); // the data before the animal selected is saved into temp
				temporary->setNext(current->getNextPointer()); // next pointer in the data after the animal selected is saved
				head = temporary; // temp files transfer
			} else {
				head = head->getNextPointer(); // head points to next to check for a match
			}
		}
	} else {
		cout << "The list is empty" << endl << endl;
	}
	delete temporary;
	delete current;
}

// searches the list for aType and returns all found, or message that no animals of that type were found
// input: one of the pointers in the structure list_t
// output: void
void List::searchByType () {
	string type;
	cout << "What is the animal type you are looking for:\t";
	cin >> type;
	cout << endl << endl;
	while (head != NULL) {
		if (type == head->getType()) { // if match
			cout << head->getType() << " " << head->getName() << endl;
			head = head->getNextPointer();
		} else if (type != head->getType() && head->getNextPointer() == NULL) {
			cout << "No animal of type " << type << " were found\n\n";
		} else {
			head = head->getNextPointer();
		}
	}
}

// searches the list for aName and returns all found, or message that no animals of that name were found
// input: one of the pointers in the structure list_t
// output: void
void List::searchByName () {
	string name;
	int count = 1;
	cout << "What is the animal name you are looking for:\t";
	cin >> name;
	cout << endl << endl;
	while (head != NULL) {
		if (name == head->getName()) { // if match
			cout << head->getType() << " " << head->getName() << " is number "<< count << " in the list\n\n";
		} else if (head->getNextPointer() == NULL && name != head->getName()) {
			cout << "No animals of name " << name << " were found \n\n";
		} else {
			count++;
		}
	}
}

// checks to see if list is empty
// inputs: one of the pointer in the structure list_t
// outputs: 1 if list is empty; 0 if not empty
int List::isEmpty () {
	if (head != NULL) { // checks if head and tail pointer is null for emptiness
		return 0; // if not empty
	} else {
		return 1; // if empty
	}
}

// returns the size of the list
// input: one of the pointers in the structure list_t
// output: returns an int
int List::getSize () {
	int i;
	while (head != NULL){ //if head pointer is null, list is empty
		i++;
		head = head->getNextPointer();
	}
	if (head == NULL) {
		i = 0;
	}
	size = i;
	return i;
}

// prints the list of animals created
// input: one of the pointers in the structure list_t
// output: void
void List::printList () {
	cout << "Animals in list:\n" << endl << endl;
	Animal *temporary = new Animal;
	temporary = head;
	while (temporary != NULL) {
		cout << temporary->getType() << temporary->getName() << endl << endl;
		temporary = temporary->getNextPointer();
	}
}
void List::setHead (Animal *node) {
	head = node;
}
void List::setTail (Animal *node) {
	tail = node;
}
void List::setSize (int s) {
	size = s;
}
