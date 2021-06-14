#include "StudentRoster.hpp"
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
    mMap.clear();
}