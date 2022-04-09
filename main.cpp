//---------------------------------------------------------------------------
// MAIN.CPP
// Member function definition for class Gale_Shapley 
// Authors: TUONG BANH
//---------------------------------------------------------------------------
// Name class:  a class that read the information from the text file and run the
//              method that process the Algorithm.
//   includes additional features:
//   -- read from the text file. 
//   -- run the method that process the Gale_Shapley algorithm and print out the
//      matching pairs
//---------------------------------------------------------------------------
#include "Gale_Shapley.h"
#include "Name.cpp"
#include "Gale_Shapley.cpp"

// read the information from the text file and run the process Algorithm method.
// Preconditions:   none.
// Postconditions:  print out the matching after reading and running the algorithm.
int main() {
    Gale_Shapley first;
    fstream newfile;
    string fileName = "program1data.txt";
    newfile.open(fileName.c_str());

    string line;
    ifstream inputFile(fileName);
    queue<string> storeInformation;
    if (!inputFile) {
        cout << "Could not open the file - '" << fileName << "'" << endl;
    return 0;
    }

    while(inputFile >> line) {
        storeInformation.push(line);
    }

    //get number of human/pet
    first.setSize(stoi(storeInformation.front()));
    storeInformation.pop();

    //get queue of name of human
    queue<string> nameTemp;
    for(int i = 0; i < first.getSize(); i++) {
        nameTemp.push(storeInformation.front());
        storeInformation.pop();
    }
    first.setName(nameTemp);

    //get queue of pref List of human
    queue<vector<int>> prefListTemp;
    for(int i = 0; i < first.getSize(); i++) {
        vector<int> eachPrefList (first.getSize());
        for(int j = 0; j < first.getSize(); j++) {
            string eachLine = storeInformation.front();
            storeInformation.pop();
            eachPrefList[j] = (stoi(eachLine) - 1);
        }
        prefListTemp.push(eachPrefList);
    }   
    first.set_prefList(prefListTemp);

    //making objects and shared_ptr pointing to those objects
    shared_ptr<Name> human[first.getSize()];
    for(int i = 0; i < first.getSize(); i++) {
        human[i] = make_shared<Name>(first.getName() -> front(), first.get_prefList() -> front(), i + 1);
        first.getName() -> pop();
        first.get_prefList() -> pop();
        first.set_humanList(human[i]);
    }

    //get queue of name of pet
    queue<string> pet_nameTemp;
    for(int i = 0; i < first.getSize(); i++) {
        pet_nameTemp.push(storeInformation.front());
        storeInformation.pop();
    }
    first.setName(pet_nameTemp);

    //get queue of pref List of pet
    queue<vector<int>> pet_prefListTemp;
    for(int i = 0; i < first.getSize(); i++) {
        vector<int> eachPrefList (first.getSize());
        for(int j = 0; j < first.getSize(); j++) {
            string eachLine = storeInformation.front();
            storeInformation.pop();
            eachPrefList[j] = (stoi(eachLine) - 1);
        }
        pet_prefListTemp.push(eachPrefList);
    }
    first.set_prefList(pet_prefListTemp);

    //making objects and shared_ptr pointing to those objects
    shared_ptr<Name> pet[first.getSize()];
    for(int i = 0; i < first.getSize(); i++) {
        pet[i] = make_shared<Name>(first.getName() -> front(), first.get_prefList() -> front(), i + 1);
        first.getName() -> pop();
        first.get_prefList() -> pop();
        first.set_petList(pet[i]);
    }
    first.processAlgorithm();

    return 0;
}