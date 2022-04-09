//---------------------------------------------------------------------------
// GALE_SHAPLEY.H
// Class Gale_Shapley 
// Authors: TUONG BANH
//---------------------------------------------------------------------------
// Name class:  a class that contains all the list of the human and the pet &
//              process algorithm.
//   includes additional features:
//   -- intialize size, queue of participants' names, queue of vector 
//      preference, vector of pointers to humans' objects and pets' objects
//   -- process the Gale_Shapley algorithm and print out the matching pairs
//
// Assumptions:
//   -- size is initialized to zero.
//   -- all the pointers used are shared pointers.
//---------------------------------------------------------------------------
#ifndef GALE_SHAPLEY_H_
#define GALE_SHAPLEY_H_

#include "Name.h"

class Gale_Shapley {
public:
//-------------------------- processAlgorithm ------------------------------------
// Implement the Gale_Shapley algorithm.
// Preconditions:   none.
// Postconditions:  print out the matching after running the algorithm.
void processAlgorithm();

//-------------------------- setSize ------------------------------------
// Set the size.
// Preconditions:   integer of size, , which is the first number of the text.
// Postconditions:  initialize the size.
void setSize(int nums);

//-------------------------- getSize ------------------------------------
// Get the size, which is the first number of the text.
// Preconditions:   none.
// Postconditions:  return the size.
int getSize();

//-------------------------- set_Name ------------------------------------
// Set the pointer to the queue of name.
// Preconditions:   queue of name.
// Postconditions:  set the pointer to the queue of name.
void setName(queue<string> nameTemp);

//-------------------------- get_Name ------------------------------------
// Get the pointer to the queue of name.
// Preconditions:   none.
// Postconditions:  get the pointer to the queue of name.
shared_ptr<queue<string>> getName();

//-------------------------- set_prefList ------------------------------------
// Set the pointer to the queue of vector preference.
// Preconditions:   queue of vector preference.
// Postconditions:  set the pointer to the queue of vector preference list.
void set_prefList(queue<vector<int>> preferListTemp);

//-------------------------- get_prefList ------------------------------------
// Get the pointer to the queue of vector preference.
// Preconditions:   none.
// Postconditions:  get the pointer to the queue of vector preference list.
shared_ptr<queue<vector<int>>> get_prefList();

//-------------------------- set_humanList ------------------------------------
// Set the vector of pointers to humans' Objects.
// Preconditions:   pointers to humans' Objects.
// Postconditions:  create a vector of pointers to humans' Objects.
void set_humanList(shared_ptr<Name> humanPtr);

//-------------------------- get_humanList ------------------------------------
// Get the vector of pointers to humans' Objects.
// Preconditions:   none.
// Postconditions:  get the vector of pointers to humans' Objects.
vector<shared_ptr<Name>> get_humanList();

//-------------------------- set_petList ------------------------------------
// Set the vector of pointers to pets' Objects.
// Preconditions:   pointers to pets' Objects.
// Postconditions:  create a vector of pointers to pets' Objects.
void set_petList(shared_ptr<Name> petPtr);

//-------------------------- get_petList ------------------------------------
// Get the vector of pointers to pets' Objects.
// Preconditions:   none.
// Postconditions:  get the vector of pointers to pets' Objects.
vector<shared_ptr<Name>> get_petList();

private:
int size;                                           //number of human/pet
shared_ptr<queue<string>> name;                     //pointer to the queue of name
shared_ptr<queue<vector<int>>> prefList;            //pointer to the queue of vector preference
vector<shared_ptr<Name>> humanList;                 //vector of pointers to humans' objects
vector<shared_ptr<Name>> petList;                   //vector of pointers to pets' objects
};

#endif