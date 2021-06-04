#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
using namespace std;

int adminView();
int studentView();
int adminLogin();
int studentLogin();
int registerStudent();
int checkListOfStudentsRegistered();
int delay();

// Implement these functions
int deleteAllStudents();
int deleteStudentbyRollno();
int getAllStudentsbyRollNo();
int checkPresenseCountbyRollno();
int getListOfStudentsWithTheirPresenseCount();
int markMyAttendance(string username);
int countMyAttendance(string username);
int checkStudentCredentials(string username, string password);

int delay()
{
for(int i = 0; i<3; i ++)
{
	cout<<"\n Saving records ...";
    for(int ii = 0; ii<20000; ii ++)
    {
    	for(int iii = 0; iii<20000; iii ++)
       	{ }
    }
}
   
cout<<"\n Exiting now ...";
for(int i = 0; i<3; i ++){
   for(int ii = 0; ii<20000; ii ++) { 
     for(int iii = 0; iii<20000; iii ++){
	 }
    } 
}

return 0;
}

int adminView()
{	
int goBack = 0;
while(1)
{
system("clear");
cout<<"\n 1 Register a student";
cout<<"\n 2 Delete all students name registered";
cout<<"\n 3 Delete student by roll number";
cout<<"\n 4 Check list of students registered by username";
cout<<"\n 5 Check presense count of any student by roll number";
cout<<"\n 6 Get list of students with their attendance count";
cout<<"\n 0. Go back <- \n";
int choice;

cout<<"\n Enter your choice: ";
cin>>choice;

switch(choice)
{
	case 1: registerStudent();break;  
	case 2: deleteAllStudents(); break;
	case 3: deleteStudentbyRollno(); break;
	case 4: checkListOfStudentsRegistered(); break;
	case 5: checkPresenseCountbyRollno(); break;
	case 6: getListOfStudentsWithTheirPresenseCount(); break;
	case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();           	
}   

if(goBack == 1)
{
break; //break the loop
}     

}

return 0;
}

int studentLogin()
{
system("clear");	
studentView();
delay();
return 0; 
}


int adminLogin()
{
system("clear");
cout<<"\n --------- Admin Login --------";	

string username;
string password;

cout<<"\n Enter username : ";
cin>>username;
cout<<"\n Enter password : ";
cin>>password;

if(username=="admin" && password=="admin@2") 
{
    adminView();
    getchar();	
    delay();
}   
else
{
cout<<"\n Error ! Invalid credentials..";	
cout<<"\n Press any key for main menu ";
getchar();getchar();
}

return 0;
}


int checkStudentCredentials(string username, string password)
{
// read file line by line & check if username.dat exist?
// if it exists return 1 else 0

ifstream read;
read.open("db.dat");

if (read) {
// The file exists, and is open for input
int recordFound = 0;
string line;
string temp = username + ".dat";
cout<<"\n file name is : "<<temp;
while(getline(read, line)) {
	if(line == temp)
	{
		read.close();
		read.open("student_data/" + temp);
		for(int i = 0; i < 3; i++) {
			getline(read,line);
			if(i == 2 && line == password) {
				recordFound = 1;
			}
		}
		break;
	}
}

if(recordFound == 0)
    return 0;
else
   return 1;
}
else
{
   return 0;
}
    		
}

int getAllStudentsbyName()
{
cout<<"\n List of all students by their name \n";	

cout<<"\n Please enter any key to continue..";
getchar();getchar();

return 0;
}

int getAllStudentsbyRollNo()
{
cout<<"\n List of all students by their roll number \n";

cout<<"\n Please enter any key to continue..";
getchar();getchar();

return 0;		
	
}

int deleteStudentbyRollno()
{
	
cout<<"\n Delete any student by their roll number \n";		

cout<<"\n Please enter any key to continue..";
getchar();getchar();

return 0;
}


int checkPresenseCountbyRollno()
{
cout<<"\n Check presence count of any student by roll number \n";	

cout<<"\n Please enter any key to continue.."	;
getchar();getchar();

return 0;	
}

int checkAllPresenseCountbyRollno()
{
cout<<"\n Check presence count of all students by roll number & name \n";		
cout<<"\n Please enter any key to continue.."	;
getchar();getchar();

return 0;
}

int studentView()
{
cout<<"\n ------- Student Login-------- \n";		

string username, password;

cout<<"\n Enter username : ";
cin>>username;

cout<<"\n Enter password : ";
cin>>password;

int res = checkStudentCredentials(username, password);

if(res  == 0)
{
   cout<<"\n Invalid credentials !!";
   cout<<"\n Press any key for main menu..";
   getchar(); getchar();	
   return 0;
} 

int goBack = 0;
while(1)
{
system("clear");

cout<<"\n 1 Mark attendance for today ";
cout<<"\n 2 Count my attendance";
cout<<"\n 0. Go back <- \n";
int choice;

cout<<"\n Enter your choice: ";
cin>>choice;

switch(choice)
{
	case 1: markMyAttendance(username); break;
	case 2: countMyAttendance(username); break;
	case 0: goBack = 1;break;
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();           	
}   

if(goBack == 1)
{
break; //break the loop
}     
	
}
   
}

int markMyAttendance(string username)
{
cout<<"\n Mark attendance for today !!";	
cout<<"\n Please enter any key to continue..";
//todo: implement this functionality

getchar();getchar();

return 0;	
} 

int countMyAttendance(string username)
{
cout<<"\n Count my attendance for today !!";	
cout<<"\n Please enter any key to continue..";
//todo: implment this functionality

getchar();getchar();

return 0;	
} 

int deleteAllStudents()
{
cout<<"\n To delete all students !!";
cout<<"\n Please enter any key to continue..";
//todo: implement this functionality

getchar(); getchar();
return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{
cout<<"\n All students with their presence count !!";
cout<<"\n Please enter any key to continue..";
//todo: implement this functionality

getchar(); getchar();
return 0;
}

int checkListOfStudentsRegistered(){
cout<<"\n - Check List of Student Registered by Username-- ";	

//check if record already exist..
ifstream read;
read.open("db.dat");

if(read)
{   int recordFound =0; 
    string line;
    while(getline(read, line)) {
    	char name[100];
    	strcpy(name, line.c_str());
    	char onlyname[100];
    	strncpy(onlyname, name, (strlen(name) - 4));
    	cout<<" \n " << onlyname;
    }
     read.close();        
}
else
{
cout<<"\n No record found :(";
}
	
	
cout<<"\n Please enter any key to continue..";
getchar(); getchar();
return 0;
}


int registerStudent()
{
    cout<<"\n ----- Form to Register Student ---- \n";	

    string name, username, password, rollno, address, father, mother;
    
    cout<<"\n Enter name : ";     cin>>name;
    cout<<"\n Enter username : ";     cin>>username;
    cout<<"\n Enter password : ";     cin>>password;
    cout<<"\n Enter roll number : ";     cin>>rollno;
    getchar();
    
    char add[100];
    cout<<"\n Enter address : ";     cin.getline(add, 100);
    cout<<"\n Enter father : ";     cin>>father;
    cout<<"\n Enter mother : ";     cin>>mother;
    
    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {   int recordFound =0; 
	   string line;
	    while(getline(read, line)) {
    	if(line == username+".dat" )
    	{
    		recordFound = 1 ;
    	    break;
		}
        }
        if(recordFound == 1)
        {
    	cout<<"\n Username already registered. Please choose another username ";
    	getchar(); getchar();
    	delay();
    	read.close();
    	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = "student_data/" + username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	out1<<add<<"\n"; 	out1<<father<<"\n";
	out1<<mother<<"\n";
	out1.close();

	cout<<"\n Student registered successfully !!";
    
    cout<<"\n Please enter any key to continue..";
	getchar(); getchar();
	return 0;		
}

int main(int argc, char** argv) {
	
const auto currentDir = fs::current_path();
const auto dir = currentDir / "student_data";
if(fs::is_directory(dir) == 0) {
	// Create student_data directory
	fs::create_directory("./student_data");
}	

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
	cin>>choice;
	
	switch(choice)
	{
	case 1: studentLogin(); break;
	case 2: adminLogin(); break;
	case 0: 
	        while(1)
	        {
		    system("clear");
        	cout<<"\n Are you sure, you want to exit? y | n \n";
        	char ex;
        	cin>>ex;
        	if(ex == 'y' || ex == 'Y')
        	   exit(0);
        	else if(ex == 'n' || ex == 'N')
             {
             	 break;
             }
             else{
             	cout<<"\n Invalid choice !!!";
             	getchar();
             }

     	   }
            break;
             	 
    default: cout<<"\n Invalid choice. Enter again ";
    getchar();
	}   		        

}
	
return 0;
}    