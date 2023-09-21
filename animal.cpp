/*  Calvin Aduma | caduma
    CPSC 1020 | Fall 2020
    C. Kittlestad
    11/26/20
    Project 2
*/

// Implements the animal.h file

#include "animal.h"

// constructor definition
Animal::Animal (){;}

// creates the Name and Type of animal for user to user
// inputs: two strings
// outputs: void
Animal::Animal (string name, string type) {
  aName = name;
  aType = type;
}

// sets the name of an animal
// inputs: string
// output: void
void Animal::setName (string name) {
  aName = name;
}

// set tje type of animal
// inputs: string
// output: void
void Animal::setType (string type) {
  aType = type;
}

// sets the next node to a specific location
// inputs: Animal pointer
// output: void
void Animal::setNext (Animal *node) {
  next = node;
}

// sets the previous node to a specific location
// inputs: Animal pointer
// outputs: void
void Animal::setPrev (Animal *node) {
  prev = node;
}

// increments the head pointer to the next Animal in the list
// inputs: none
// outputs: Animal pointer to next Animal
Animal* Animal::advanceNext () {
  return next->next;
}

// returns the current next pointer
// inputs: none
// outputs: next pointer
Animal* Animal::getNextPointer () {
  return next;
}

// returns the current prev pointer
// inputs: none
// output: prev pointer
Animal* Animal::getPrevPointer () {
  return prev;
}
// gets the name of the animal of current head pointer
// inputs: none
// outputs: string with name of animal
string Animal::getName () {
  return aName;
}

// gets the type of animal of current head pointer
// inputs: none
// outputs: string with type of animal
string Animal::getType () {
  return aType;
}

// returns 1 if there is another animal in list. 0 if there are no more animals
// inputs: none
// outputs: integer of 0 or 1
int Animal::isNext () {
  if (next != NULL) {
    return 1;
  } else {
    return 0;
  }
}
