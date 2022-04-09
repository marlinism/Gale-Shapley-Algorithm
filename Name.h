//---------------------------------------------------------------------------
// NAME.H
// Class Name 
// Authors: TUONG BANH
//---------------------------------------------------------------------------
// Name class:  a class that contains all the similar characteristics between 
//              the human and the pet
//   includes additional features:
//   -- intialize name, order number, order number of the matched one and 
//      preference list.
//   -- get name, order number, order number of the matched one and 
//      preference list.
//   -- check if the owner of this class is single or not
//   -- compare the new person/pet that wants to be matched with its own order
//      number of matched person/pet.
//
// Assumptions:
//   -- order number of the matched are initialized to negative one
//---------------------------------------------------------------------------

#ifndef NAME_H_
#define NAME_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>  
#include <memory>
#include <algorithm>

using namespace std;

class Name {
public:
//-------------------------- Constructor ------------------------------------
// Default constructor for class Name.
// Preconditions:   string name (person/pet), vector type integer of 
//                  preference list, and the integer of that person/ 
//                  pet in the list.
// Postconditions:  calling the methods "setName", "setPreferList",
//                  "set_orderNum", "set_orderMatched" to initialize the 
//                  data inputted.
Name(string name, vector<int> preferenceList, int orderNum);

//-------------------------- setName ------------------------------------
// Set name of the person/pet.
// Preconditions:   string name (person/pet).
// Postconditions:  initialize the name.
void setName(string n);

//-------------------------- getName ------------------------------------
// Get name of the person/pet.
// Preconditions:   none.
// Postconditions:  return the name.
string getName();

//-------------------------- setPreferList ------------------------------------
// Set vector of the preference list.
// Preconditions:   vector of the preference list.
// Postconditions:  initialize the vector.
void setPreferList(vector<int> list);

//-------------------------- getPreferList ------------------------------------
// Get vector of preference list.
// Preconditions:   none.
// Postconditions:  return the vector.
vector<int> getPreferList();

//-------------------------- getPreferList ------------------------------------
// Drop a first index from the preference list.
// Preconditions:   none.
// Postconditions:  Erase the first index of the vector.
void dropPreferList();

//-------------------------- set_orderNum ------------------------------------
// Set the order of the name in the list.
// Preconditions:   integer of the order.
// Postconditions:  initialize the order number.
void set_orderNum(int num);

//-------------------------- get_orderNum ------------------------------------
// Get the order of the name in the list.
// Preconditions:   none.
// Postconditions:  get the order number.
int get_orderNum();

//-------------------------- set_orderMatched ------------------------------------
// Set the order of the matched person/pet in the list.
// Preconditions:   the order number of that matched person/pet.
// Postconditions:  initialize the order number of that matched person/pet.
void set_orderMatched(int num); 

//-------------------------- get_orderMatched ------------------------------------
// Get the order of the matched person/pet in the list.
// Preconditions:   none.
// Postconditions:  get the order number of that matched person/pet.
int get_orderMatched();

//-------------------------- isSingle ------------------------------------
// Determine if this person/pet is not matched.
// Preconditions:   none.
// Postconditions:  true if orderMatched == -1, false if orderMatched != -1.
bool isSingle();

//-------------------------- compare ------------------------------------
// Compare with the matched order number of this person.
// Preconditions:   integer of the one that want to compare.
// Postconditions:  true if new order number is smaller than the previous 
//                  one; otherwise, it is false.
bool compare(int newTurn);
 
private:
    string name;                       // name of the person/pet
    int orderNum;                      // the order of that person/pet in the list
    int orderMatched;                  // the order of the matched pet/person
    vector<int> preferList;            // the vector represents for the preference list
};

#endif