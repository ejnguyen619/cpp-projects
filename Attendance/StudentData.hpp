#pragma once
#include <string>
using namespace std;

class StudentData {
    private:
        string name;
        string username;
        string password;
        string rollNum;
        string address;
        string dad;
        string mom;

    public:
        StudentData(string inname, string inusername, string inpassword, 
                    string inrollNum, string inaddress, string indad, string inmom);
        string get(string attr);
        void modify(string attr, string value);
        void printAll();
};