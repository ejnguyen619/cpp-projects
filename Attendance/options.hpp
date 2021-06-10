#include "StudentRoster.hpp"
#include <string>
using namespace std;

class options {
    public:
        options() = default;
        int adminView();
        int studentView();
        void adminLogin();
        void studentLogin();
        int checkStudentCredentials(string username, string password);
        int registerStudent();
        int checkListOfStudentsRegistered();
        int deleteAllStudents();
        int delay();
        // Implement these functions
        int deleteStudentbyRollno();
        int checkPresenseCountbyRollno();
        int getListOfStudentsWithTheirPresenseCount();
        int markMyAttendance(string username);
        int countMyAttendance(string username);
        int getLastRoll();
        void exitApp();
    private:
        StudentRoster map = StudentRoster{};
};