#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//2 file streams
//call member function
vector<string> readNames(string fileName) {
    vector<string> nameList;
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        string name;
        while (getline(inputFile, name)) {
            nameList.push_back(name);
        }
        inputFile.close();
    }
    else {
        cout << "Error: Could not open file " << fileName << endl;
    }
    return nameList;
}

//Return a Boolean value
bool searchForStringInVector(string name, vector<string> nameList) {
    for (int i = 0; i < nameList.size(); i++) {
        if (nameList[i] == name) {
            return 1;
        }
    }
    return 0;
}


void display(vector<string> names) {
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << "\n";

    }
}



//report
int main() {
    //call read File (twice)
    vector<string> girlNameList = readNames("GirlNames.txt");
    vector<string> boyNameList = readNames("BoyNames.txt");

    //call display to check (twice)
    cout << "These are the Girl's names:" << endl;
    display(girlNameList);

    cout << "These are the Boy's names:" << endl;
    display(boyNameList);

    string boyName, girlName;
    cout << "Enter a boy's name: ";
    getline(cin, boyName);
    cout << "Enter a girl's name: ";
    getline(cin, girlName);

    //call search
    if (searchForStringInVector(boyName, boyNameList)) {
        cout << boyName << " is a popular boy's name." << endl;
    }
    else {
        cout << boyName << " is not a popular boy's name." << endl;
    }

    if (searchForStringInVector(girlName, girlNameList)) {
        cout << girlName << " is a popular girl's name." << endl;
    }
    else {
        cout << girlName << " is not a popular girl's name." << endl;
    }

    return 0;
}


