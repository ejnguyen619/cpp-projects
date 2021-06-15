#include "StudentRoster.hpp"
#include <iostream>
#include <iterator>

void StudentRoster::put(int key, StudentData* value) {
    mMap[key] = value;
}

StudentData* StudentRoster::get(int key) const {
    const auto it = mMap.find(key);
    return it == mMap.end() ? 0 : it->second;
}

string StudentRoster::getAll() {
    string usernames = "";
    for (auto i = mMap.begin(); i != mMap.end(); i++) {
        StudentData data = *(i->second);
        usernames += ("\n" + data.get("username")); 
    }
    return usernames;
}

bool StudentRoster::isEmpty() {
    return mMap.empty();
}

void StudentRoster::clearAllData() {
    if(!isEmpty()) mMap.clear();
    else {
        cout << "No student data available" << endl;
    }
}

int StudentRoster::rosterSize() {
    return mMap.size();
}

void StudentRoster::deleteStudent(int rollNumber) {
    if(!isEmpty()) {
        mMap.erase(rollNumber); 
    } else {
        cout << "No student data available" << endl;
    }
}

bool StudentRoster::keyExists(int key) {
    if(mMap.find(key) != mMap.end()) {
        return true;
    } else {
        return false;
    }
}