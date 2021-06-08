#pragma once
#include <map>
#include "StudentData.hpp"

class StudentRoster {
    private:
        using Map = std::map<int,StudentData*>;
        Map mMap;
    public:
        StudentRoster() = default;
        void put(int key, StudentData* value);
        StudentData* get(int key) const;
};
