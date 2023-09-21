/*  Calvin Aduma | caduma
    CPSC 1020 | Fall 2020
    C. Kittlestad
    11/26/20
    Project 2
*/

#ifndef DLL_LIST_H
#define DLL_LIST_H
#include <fstream>
#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

class List {
  private:
    Animal *head;
    Animal *tail;
    int size;
  public:
    List( ); // constructor
    int printMenu( ); // could be stand alone, but included it in the class
    void listInit( ifstream &inFile );
    void initializeFromFile( ifstream &inFile );
    Animal *newAnimal( ifstream &inFile );
    void addToFront( );
    void addToRear( );
    void deleteAnimal( string animalName );
    void searchByType( );
    void searchByName( );
    int isEmpty( );
    int getSize( );
    void printList ( );
    void setHead(Animal *node);
    void setTail(Animal *node);
    void setSize(int s);
};

#endif /* DLL_LIST_H */
