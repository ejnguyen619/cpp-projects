#include "StudentData.hpp"
#include <iostream>
#include <string>
using namespace std;

StudentData::StudentData(string inname, string inusername, string inpassword, 
            string inrollNum, string inaddress, string indad, string inmom) 
{
    name = inname;
    username = inusername;
    password = inpassword;
    rollNum = inrollNum;
    address = inaddress;
    dad = indad;
    mom = inmom;
}

string StudentData::get(string attr) {
    string value = "";
    if(attr == "name") {
        value = name;
    } else if(attr == "username") {
        value = username;
    } else if(attr == "password") {
        value = password;
    } else if(attr == "roll") {
        value = rollNum;
    } else if(attr == "address") {
        value = address;
    } else if(attr == "dad") {
        value = dad;
    } else if(attr == "mom") {
        value = mom;
    } else {
        cout << "Student attribute not found!" << endl;
        return value;
    }
}

void StudentData::modify(string attr,string value) {
    if(attr == "name") {
        name = value;
    } else if(attr == "username") {
        username = value;
    } else if(attr == "password") {
        password = value;
    } else if(attr == "roll") {
        rollNum = value;
    } else if(attr == "address") {
        address = value;
    } else if(attr == "dad") {
        dad = value;
    } else if(attr == "mom") {
        mom = value;
    } else {
        cout << "Student attribute not found!" << endl;
    }
}

void StudentData::getAll() {
    cout << "name: " << name << endl;
    cout << "username: " << username << endl;
    cout << "password: " << password << endl;
    cout << "rollNumber: " << rollNum << endl;
    cout << "address: " << address << endl;
    cout << "dad: " << dad << endl;
    cout << "mom: " << mom << endl;
}