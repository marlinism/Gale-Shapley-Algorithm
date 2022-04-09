//---------------------------------------------------------------------------
// NAME.CPP
// Member function definition for class Name 
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

#include "Name.h"

/* ------------------------------ Name.h ------------------------------ */
//-------------------------- Constructor ------------------------------------
// Default constructor for class Name
// Preconditions:   string name (person/pet), vector type integer of 
//                  preference list, and the integer of that person/ 
//                  pet in the list
// Postconditions:  calling the methods "setName", "setPreferList",
//                  "set_orderNum", "set_orderMatched" to set the 
//                  data inputted.
Name:: Name(string name, vector<int> preferList, int orderNum) {
    this -> setName(name);
    this -> setPreferList(preferList);
    this -> set_orderNum(orderNum);
    this -> set_orderMatched(-1);
}

//-------------------------- setName ------------------------------------
// Set name of the person/pet.
// Preconditions:   string name (person/pet).
// Postconditions:  initialize the name.
void Name:: setName(string n) {
    this -> name = n;
}

//-------------------------- getName ------------------------------------
// Get name of the person/pet.
// Preconditions:   none.
// Postconditions:  return the name.
string Name:: getName() {
    return this -> name;
}

//-------------------------- setPreferList ------------------------------------
// Set vector of the preference list.
// Preconditions:   vector of the preference list.
// Postconditions:  initialize the vector.
void Name:: setPreferList(vector<int> list) {
    this -> preferList = list;
}

//-------------------------- getPreferList ------------------------------------
// Get vector of preference list.
// Preconditions:   none.
// Postconditions:  return the vector.
vector<int> Name:: getPreferList() {
    return this -> preferList;
}

//-------------------------- getPreferList ------------------------------------
// Drop a first index from the preference list.
// Preconditions:   none.
// Postconditions:  Erase the first index of the vector.
void Name:: dropPreferList() {
    this -> preferList.erase(this -> preferList.begin());
}

//-------------------------- set_orderNum ------------------------------------
// Set the order of the name in the list.
// Preconditions:   integer of the order.
// Postconditions:  initialize the order number.
void Name:: set_orderNum(int num) {
    this -> orderNum = num;
}

//-------------------------- get_orderNum ------------------------------------
// Get the order of the name in the list.
// Preconditions:   none.
// Postconditions:  get the order number.
int Name:: get_orderNum() {
    return this -> orderNum;
}

//-------------------------- set_orderMatched ------------------------------------
// Set the order of the matched person/pet in the list.
// Preconditions:   the order number of that matched person/pet.
// Postconditions:  initialize the order number of that matched person/pet.
void Name:: set_orderMatched(int num) {
    this -> orderMatched = num;
}

//-------------------------- get_orderMatched ------------------------------------
// Get the order of the matched person/pet in the list.
// Preconditions:   none.
// Postconditions:  get the order number of that matched person/pet.
int Name:: get_orderMatched() {
    return this -> orderMatched;
} 

//-------------------------- isSingle ------------------------------------
// Determine if this person/pet is not matched.
// Preconditions:   none.
// Postconditions:  true if orderMatched == -1, false if orderMatched != -1.
bool Name:: isSingle() {
    return orderMatched == -1 ? true : false;
}

//-------------------------- compare ------------------------------------
// Compare with the matched order number of this person.
// Preconditions:   integer of the one that want to compare.
// Postconditions:  true if new order number is smaller than the previous 
//                  one; otherwise, it is false.
bool Name:: compare(int newTurn) {
    int newTurn_index, matched_index;

    for(int i = 0; i < this -> preferList.size(); i++) {
        if(preferList[i] == newTurn) {
            newTurn_index = i;
        }

        if(preferList[i] == this -> orderMatched) {
            matched_index = i;
        }
    }

    return newTurn_index < matched_index;
}