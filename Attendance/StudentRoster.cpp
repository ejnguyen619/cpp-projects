#include "StudentRoster.hpp"
#include <iterator>

void StudentRoster::put(int key, StudentData* value) {
    mMap[key] = value;
}

StudentData* StudentRoster::get(int key) const {
    const auto it = mMap.find(key);
    return it == mMap.end() ? 0 : it->second;
}