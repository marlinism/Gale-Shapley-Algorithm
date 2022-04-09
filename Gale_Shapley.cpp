//---------------------------------------------------------------------------
// GALE_SHAPLEY.CPP
// Member function definition for class Gale_Shapley 
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
#include "Gale_Shapley.h"

// Implement the Gale_Shapley algorithm.
// Preconditions:   none.
// Postconditions:  print out the matching after running the algorithm.
void Gale_Shapley:: processAlgorithm() {
    //set up the order
    stack<int> order;
    for(int i = this -> size - 1; i >= 0; i--) {
        order.push(i);
    }

    //initialize the matching vector
    vector<vector<string>> matching (this -> size);
    while(!order.empty()) {
        int human_index = order.top();
        order.pop();
        int pet_index = humanList[human_index] -> getPreferList()[0];
        if(petList[pet_index] -> isSingle()) {     
            humanList[human_index] -> set_orderMatched(pet_index);
            petList[pet_index] -> set_orderMatched(human_index);
            humanList[human_index] -> dropPreferList();
        } else if (petList[pet_index] -> compare(human_index)) {
            order.push(petList[pet_index] -> get_orderMatched());
            humanList[petList[pet_index] -> get_orderMatched()] -> set_orderMatched(-1);
            humanList[human_index] -> set_orderMatched(pet_index);
            petList[pet_index] -> set_orderMatched(human_index);
            humanList[human_index] -> dropPreferList();
        } else {
            order.push(human_index);
            humanList[human_index] -> dropPreferList();
        }
    }

    // print the matches
    for(int i = 0; i < this -> size; i++) {
        int matchedNum = humanList[i] -> get_orderMatched();
        cout << humanList[i] -> getName() << " / " << petList[matchedNum] -> getName() << endl;
    }

    
}

//-------------------------- setSize ------------------------------------
// Set the size.
// Preconditions:   integer of size, , which is the first number of the text.
// Postconditions:  initialize the size.
void Gale_Shapley:: setSize(int nums) {
    this -> size = nums;
}

//-------------------------- getSize ------------------------------------
// Get the size, which is the first number of the text.
// Preconditions:   none.
// Postconditions:  return the size.
int Gale_Shapley:: getSize() {
    return this -> size;
}

//-------------------------- set_Name ------------------------------------
// Set the pointer to the queue of name.
// Preconditions:   queue of name.
// Postconditions:  set the pointer to the queue of name.
void Gale_Shapley::setName(queue<string> nameTemp) {
    this -> name = make_shared<queue<string>>(nameTemp);
}

//-------------------------- get_Name ------------------------------------
// Get the pointer to the queue of name.
// Preconditions:   none.
// Postconditions:  get the pointer to the queue of name.
shared_ptr<queue<string>> Gale_Shapley:: getName() {
    return this -> name;
} 

//-------------------------- set_prefList ------------------------------------
// Set the pointer to the queue of vector preference.
// Preconditions:   queue of vector preference.
// Postconditions:  set the pointer to the queue of vector preference list.
void Gale_Shapley:: set_prefList(queue<vector<int>> preferListTemp) {
    this -> prefList = make_shared<queue<vector<int>>>(preferListTemp);
}

//-------------------------- get_prefList ------------------------------------
// Get the pointer to the queue of vector preference.
// Preconditions:   none.
// Postconditions:  get the pointer to the queue of vector preference list.
shared_ptr<queue<vector<int>>> Gale_Shapley:: get_prefList() {
    return this -> prefList;
}

//-------------------------- set_humanList ------------------------------------
// Set the vector of pointers to humans' Objects.
// Preconditions:   pointers to humans' Objects.
// Postconditions:  create a vector of pointers to humans' Objects.
void Gale_Shapley::set_humanList(shared_ptr<Name> humanPtr) {
    this -> humanList.push_back(humanPtr);
}

//-------------------------- get_humanList ------------------------------------
// Get the vector of pointers to humans' Objects.
// Preconditions:   none.
// Postconditions:  get the vector of pointers to humans' Objects.
vector<shared_ptr<Name>> Gale_Shapley:: get_humanList() {
    return this -> humanList;
}

//-------------------------- set_petList ------------------------------------
// Set the vector of pointers to pets' Objects.
// Preconditions:   pointers to pets' Objects.
// Postconditions:  create a vector of pointers to pets' Objects.
void Gale_Shapley::set_petList(shared_ptr<Name> petPtr) {
    this -> petList.push_back(petPtr);
}

//-------------------------- get_petList ------------------------------------
// Get the vector of pointers to pets' Objects.
// Preconditions:   none.
// Postconditions:  get the vector of pointers to pets' Objects.
vector<shared_ptr<Name>> Gale_Shapley:: get_petList() {
    return this -> petList;   
}

