#include <iostream>
#include <experimental/filesystem>
#include "options.hpp"

namespace fs = std::experimental::filesystem;
using namespace std;

int main(int argc, char** argv) {

auto choices = options{};
const auto currentDir = fs::current_path();
const auto dir = currentDir / "student_data";
if(fs::is_directory(dir) == 0) {
	// Create student_data directory
	fs::create_directory("./student_data");
}
choices.importData();

while(1)
{
	system("clear");
	cout<<"\n Attendance Management System \n";
	cout<<"-------------------------------------\n\n";
	
	cout<<"1. Student Login\n";
	cout<<"2. Admin Login\n";
	
	cout<<"0. Exit\n";
	int choice;
	
	cout<<"\n Enter your choice: ";
	if(!(cin>>choice)) {
        cout<<"\n Invalid choice. Enter again ";
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
    } else {
		switch(choice)
		{
		case 1: choices.studentLogin(); break;
		case 2: choices.adminLogin(); break;
		case 0: choices.exitApp(); break;
		default: cout<<"\n Invalid choice. Enter again ";
		getchar();
		}
	}   		        

}
	
return 0;
}    