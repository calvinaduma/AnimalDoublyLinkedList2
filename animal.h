/*  Calvin Aduma | caduma
    CPSC 1020 | Fall 2020
    C. Kittlestad
    11/26/20
    Project 2
*/

#ifndef ANIMAL_H
#define ANIMAL_H
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Animal {
  private:
    string aName;
    string aType;
    Animal *next = {};
    Animal *prev = {};
  public:
    Animal( ); // constructor
    Animal( string name, string aType ); // constructor
    void setName( string name ); // setter functions
    void setType( string type );
    void setNext( Animal * node );
    void setPrev( Animal * node );
    Animal * advanceNext( ); // increments to the next animal in the list
    string getName( ); // getter functions
    string getType( );
    int isNext( ); // returns 1 if there is another animal in list
    // returns 0 is there are no more animals'
    Animal* getNextPointer();
    Animal* getPrevPointer();
};

#endif /* ANIMAL_H */
