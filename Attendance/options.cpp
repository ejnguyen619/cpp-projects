#include "options.hpp"
#include "StudentData.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

vector<string> options::listStudentFiles() {
    ifstream read;
    read.open("db.dat");
    vector<string> usernameList;

    if (read) {
        string line;
        while(getline(read, line)) {
            if(!line.size()) continue;
            usernameList.push_back(line);
        }
        read.close();
        return usernameList; 
    } else {
        return {};
    }
}

void options::importStudentData(string data) {
    ifstream read;
	string temp = "student_data/" + data;
    string name, username, password, rollNum, address, dad, mom;
    string line;
	read.open(temp.c_str());
    for(int i = 0; i < 7; i++) {
        getline(read,line);
        switch(i) {
            case 0: name = line; break;
            case 1: username = line; break;
            case 2: password = line; break;
            case 3: rollNum = line; break;
            case 4: address = line; break;
            case 5: dad = line; break;
            case 6: mom = line; break;
        }
    }
    StudentData *student = new StudentData(name,username,password,rollNum,address,dad,mom);
    map.put(stoi(rollNum),student);
    read.close();
}

int options::adminView() {
    int goBack = 0;
    while(1)
    {
    system("clear");
    cout<<"\n 1 Register a student";
    cout<<"\n 2 Delete all students name registered";
    cout<<"\n 3 Delete student by roll number";
    cout<<"\n 4 Check list of students registered by username";
    cout<<"\n 5 Check presence count of any student by roll number";
    cout<<"\n 6 Get list of students with their attendance count";
    cout<<"\n 0. Go back <- \n";
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

    }

    return 0;
}

int options::studentView() {
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
    if(!(cin>>choice)) {
        cout<<"\n Invalid choice. Enter again ";
        cin.clear();
        cin.ignore(10000, '\n');
        continue;
    } else {
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
}

void options::adminLogin() {
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
}

void options::studentLogin() {
    system("clear");	
    studentView();
    delay();  
}

int options::checkStudentCredentials(string username, string password) {
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

int options::registerStudent() {
    cout<<"\n ----- Form to Register Student ---- \n";	

    string name, username, password, rollno, address, father, mother;
    
    cout<<"\n Enter name : ";     cin>>name;
    cout<<"\n Enter username : ";     cin>>username;
    cout<<"\n Enter password : ";     cin>>password;
	rollno = to_string(getLastRoll()+1);
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

    // Put student data into map
    StudentData data(name,username,password,rollno,address,father,mother);
    map.put(stoi(rollno),&data);

	cout<<"\n Student registered successfully !!";
    
    cout<<"\n Please enter any key to continue..";
	getchar(); getchar();
	return 0;
}

int options::checkListOfStudentsRegistered() {
    cout<<"\n - Check List of Student Registered by Username--";	

    //check if record already exist..
    if(!map.isEmpty()) {
        string usernameList = map.getAll();
        cout << usernameList;
    } else {
        cout<<"\n No record found :(";
    }  
        
    cout<<"\n Please enter any key to continue..";
    getchar(); getchar();
    return 0;
}

int options::deleteAllStudents() {
    while(1) {
        cout<<"\n Are you sure, you want to delete? y | n \n";
        char ex;
        cin>>ex;
        if(ex == 'y' || ex == 'Y'){
            system("rm -fr student_data/*.dat");
            system("rm db.dat");
            map.clearAllData();
            cout<<"\n All students are deleted!!";
            break;
        }
        else if(ex == 'n' || ex == 'N')
        {
            break;
        }
        else{
            cout<<"\n Invalid choice !!!";
            getchar();
        }	
    }
    cout<<"\n Please enter any key to continue..";
    getchar(); getchar();
    return 0;
}

int options::delay() {
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

int options::deleteStudentbyRollno() {
    cout<<"\n Delete any student by their roll number \n";		

    while(1) {
        int ex;
        cout<<"\n Enter roll number or 0 to cancel \n";
        if(!(cin>>ex)) {
            cout<<"\n Invalid choice. Enter again ";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            if(ex == 0) break;
            else {
                if(map.keyExists(ex)) {
                    StudentData student = *map.get(ex);
                    string filepath = "rm student_data/" + student.get("username") + ".dat";
                    char* command = const_cast<char*>(filepath.c_str());
                    system(command);
                    updateDB(student.get("username") + ".dat");
                    map.deleteStudent(ex);
                    cout<<"\n Student is deleted!!";
                    break; 
                } else {
                    cout << "\n No results found. Try again";
                }
            }
        }	
    }
    
    cout<<"\n Please enter any key to continue..";
    getchar(); getchar();
    return 0;
}

int options::checkPresenseCountbyRollno() {
    cout<<"\n Check presence count of any student by roll number \n";	

    cout<<"\n Please enter any key to continue.."	;
    getchar();getchar();

    return 0; 
}

int options::getListOfStudentsWithTheirPresenseCount() {
    cout<<"\n All students with their presence count !!";
    cout<<"\n Please enter any key to continue..";
    //todo: implement this functionality

    getchar(); getchar();
    return 0;  
}

int options::markMyAttendance(string username) {
    cout<<"\n Mark attendance for today !!";	
    cout<<"\n Please enter any key to continue..";
    //todo: implement this functionality

    getchar();getchar();

    return 0;   
}

int options::countMyAttendance(string username) {
    cout<<"\n Count my attendance for today !!";	
    cout<<"\n Please enter any key to continue..";
    //todo: implment this functionality

    getchar();getchar();

    return 0;	
}

int options::getLastRoll() {
    if(!map.isEmpty()) {
        return map.rosterSize();
    } else {
        return 0;
    }
}

void options::exitApp() {
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
}

void options::updateDB(string filename) {
    ifstream filein("db.dat");
    ofstream fileout("db2.dat");
    string line;
    while(filein >> line) {
        if(line == filename) {
            continue;
        }
        line += "\n";
        fileout << line;
    }
    system("rm db.dat");
    system("mv db2.dat db.dat");
}