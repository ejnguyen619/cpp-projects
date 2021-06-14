#pragma once
#include <map>
#include "StudentData.hpp"
#include <string>

class StudentRoster {
    private:
        using Map = std::map<int,StudentData*>;
        Map mMap;
    public:
        StudentRoster() = default;
        void put(int key, StudentData* value);
        StudentData* get(int key) const;
        string getAll();
        bool isEmpty();
        void clearAllData();
};
