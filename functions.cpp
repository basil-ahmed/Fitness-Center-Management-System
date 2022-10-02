#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "classes.h"
#include "functions.h"

using namespace std;

// Admin Login Function
void login(Admin* list[]){
    
    string username; string password; int admin_pos = 0;
    bool end = false;
    
    while(end ==false)
    {
        cout<<"Please enter a valid username: ";
        cin>>username;
        cout<<"Please enter a valid password: ";
        cin>>password;
        for (int i = 0; i<100; i++)
        {
            if (list[i]!=NULL)
            {
                // Validation for correct credentials
                if ( username == list[i]->getusername() && password==list[i]->getpassword())
                {
                    admin_pos = i;
                    end = true;
                    break;
                }
            }
        }
        if (end == false)
        cout << "WRONG CREDENTIALS!"<<endl;
    }
};

// Member Login Function
void login(Member* list[], int& currentMember){
    
    string username; string password; int member_pos = 0;
    bool end = false;
    
    
    while(end ==false)
    {
        cout<<"Please enter a valid username: ";
        cin>>username;
        cout<<"Please enter a valid password: ";
        cin>>password;
        for (int i = 0; i<100; i++)
        {
            if (list[i]!=NULL)
            {
                // Validation for correct credentials
                if ( username == list[i]->getusername() && password==list[i]->getpassword())
                {
                    member_pos = i;
                    currentMember = list[i]->getmemberID();
                    end = true;
                    break;
                }
            }
        }
        if (end == false)
        cout << "WRONG CREDENTIALS!"<<endl;
    }
};

// To show Menu and get user input Function
string menu(string choice) {
    
    string admin_choice;
    string member_choice;
    
    if (choice == "admin") {
        
        cout<<"The list of available operations for Admins are: "<<endl;
        cout<<"1) Register a new Admin"<<endl;
        cout<<"2) Register a new Member"<<endl;
        cout<<"3) Add a Fitness Class"<<endl;
        cout<<"4) Delete a Fitness Class"<<endl;
        cout<<"5) Update the details of a fitness class"<<endl;
        cout<<"6) Display the classes with vacancies"<<endl;
        cout<<"7) Logout"<<endl;
        cout<<"8) Quit the Program"<<endl;
        
        cout<<"Enter the number of required action from the list: [1-8]"<<endl;
        cin>>admin_choice;
        while (!(admin_choice == "1" || admin_choice == "2" || admin_choice == "3" || admin_choice == "4" || admin_choice == "5" || admin_choice == "6" || admin_choice == "7" || admin_choice == "8")) {
            cout<<"Wrong Choice! Enter the number of required action from [1-8]: ";
            cin>>admin_choice;
        }
        
        return admin_choice;
    }
    else{
        
        cout<<"The list of available operations for Members are: "<<endl;
        cout<<"1) Book a Class"<<endl;
        cout<<"2) Display the classes with vacancies"<<endl;
        cout<<"3) Cancel Booking"<<endl;
        cout<<"4) Logout"<<endl;
        cout<<"5) Quit the Program"<<endl;
        
        cout<<"Enter the number of required action from the list: [1-5]"<<endl;
        cin>>member_choice;
        while (!(member_choice == "1" || member_choice == "2" || member_choice == "3" || member_choice == "4" || admin_choice == "5")) {
            cout<<"Wrong Choice! Enter the number of required action from [1-5]: ";
            cin>>member_choice;
        }
        
        return member_choice;
    };
};

Member register_member(string firstname, string lastname) {
    
    srand (time(NULL));
    
    string first_name = firstname;
    string last_name = lastname;
    
    int memberID = rand()%8999+1000; // Random 4 digit generator

    // Username generator
    for (int i = 0; i< firstname.length(); i++) {

        firstname[i] = tolower(firstname[i]);
    }
    string username = firstname + to_string(memberID);
    
    // Password generator
    for (int i = 0; i< lastname.length(); i++) {

        lastname[i] = tolower(lastname[i]);
    }
    string password = lastname + to_string(rand()%8999+1000);

    
    return Member(memberID, first_name, last_name, username, password);
};

Admin register_admin(string firstname, string lastname) {
    
    srand (time(NULL));
    
    string first_name = firstname;
    string last_name = lastname;
    
    int adminID = rand()%8999+1000; // Random 4 digit generator

    // Username generator
    for (int i = 0; i< firstname.length(); i++) {

        firstname[i] = tolower(firstname[i]);
    }
    string username = firstname + to_string(adminID);
    
    // Password generator
    for (int i = 0; i< lastname.length(); i++) {

        lastname[i] = tolower(lastname[i]);
    }
    string password = lastname + to_string(rand()%8999+1000);

    
    return Admin(adminID, first_name, last_name, username, password);
};

FitnessClass addFitnessClass() {
    
    int classID;
    string class_name;
    string class_date;
    string class_time;
    int max_capacity;
    int room_number;
    
    cout<<"Add the ID of the Fitness Class: ";
    cin>>classID;
    
    cout<<"Add the Name of the Fitness Class: ";
    cin>>class_name;
    
    cout<<"Add the Date of the Fitness Class: ";
    cin>>class_date;
    
    cout<<"Add the time of the Fitness Class: ";
    cin>>class_time;
    
    cout<<"Maximum Capacity of the Fitness Class: ";
    cin>>max_capacity;
    
    cout<<"Room Number of the Fitness Class: ";
    cin>>room_number;
    
    cout<<endl<<"Class Added!"<<endl;

    return FitnessClass(classID, class_name, class_date, class_time, max_capacity, room_number);
};

void deleteFitnessClass(FitnessClass* list[]) {
    
    int classID; bool done = false;
    
    cout<<"Enter the ID of the Fitness Class to be deleted: ";
    cin>>classID;
    
    for (int i = 0; i<100; i++){
        
        // If fitness class found only then delete
        if (list[i]!=NULL && list[i]->getclassID() == classID) {
            
            delete list[i];
            list[i] = NULL;
            done = true;
            cout<<endl<<"Class Deleted!"<<endl;
            break;
        };
        
    };
    
    if (done == false) {
        cout<<"This Class ID does not exist!!"<<endl<<endl;
    }
    
}

void updateClassDetails(FitnessClass* list[]) {
    
    int classID;
    string updateChoice;
    string updatedStrValue;
    int updatedIntValue;
    bool done = false;
    
    cout<<"Enter the ID of the Fitness Class to be updated: ";
    cin>>classID;
    
    cout<<"1: Class Name"<<endl<<"2: Max Capacity"<<endl<<"3: Room Number"<<endl<<"4: Class Date"<<endl<<"5: Class Time"<<endl;
    cout<<"What aspect of the Class do you want to change [1-5]?: ";
    cin>>updateChoice;
    
    // Validation for update choices
    while (updateChoice != "1" && updateChoice != "2" && updateChoice != "3" && updateChoice != "4" && updateChoice != "5") {
        cout<<"ERROR! Choose from [1-5]: "<<endl;
        cin>>updateChoice;
    }
    
    for (int i = 0; i<100; i++){
        
        // If fitness class found only then update
        if (list[i]!=NULL && list[i]->getclassID() == classID) {
            
            if (updateChoice == "1") {
                cout<<"New Name of the Class: "; cin>>updatedStrValue;
                list[i]->setclass_name(updatedStrValue);
            }
            if (updateChoice == "2") {
                cout<<"Updated Maximum Capacity: "; cin>>updatedIntValue;
                list[i]->setmax_capacity(updatedIntValue);
            }
            if (updateChoice == "3") {
                cout<<"New Room Number of the Class: "; cin>>updatedIntValue;
                list[i]->setroom_number(updatedIntValue);
            }
            if (updateChoice == "4") {
                cout<<"New Date of the Class: "; cin>>updatedStrValue;
                list[i]->setclass_date(updatedStrValue);
            }
            if (updateChoice == "5") {
                cout<<"New Time of the Class: "; cin>>updatedStrValue;
                list[i]->setclass_time(updatedStrValue);
            }
            
            cout<<endl<<"Class Updated!"<<endl;

            done = true;

            break;
        }
    }
    
    if (done == false) {
        cout<<endl<<"This Class ID does not exist!!"<<endl<<endl;
    }
    
}

void bookAClass(FitnessClass* list[], int currentMember) {
    
    bool done = false;
    int classID;
    
    cout<<"Enter the ID of the Fitness Class to be booked: ";
    cin>>classID;
    
    for (int i = 0; i<100; i++){
        
            if (list[i]!=NULL && list[i]->getclassID() == classID && list[i]->getcurrent_capacity() < list[i]->getmax_capacity()) {
                    
                list[i]->list_of_members[list[i]->getcurrent_capacity()] = currentMember;
                list[i]->increase_capacity();
                done = true;
                cout<<"Class Booked Successfully!!"<<endl<<endl;
                break;
            }
    }
    
    if (done == false) {
        cout<<"Class not found or Class not Empty!!"<<endl<<endl;
    }
    
}

void viewClassesWithVacancies(FitnessClass* list[]) {
    
    bool done = false;
    
    for (int i = 0; i<100; i++){
        
            if (list[i]!=NULL && list[i]->getcurrent_capacity() < list[i]->getmax_capacity()) {
                
                done = true;
                cout<<endl<<"Class ID: "<<list[i]->getclassID()<<endl;
                cout<<"Class Name: "<<list[i]->getclass_name()<<endl;
                cout<<"Class Date: "<<list[i]->getclass_date()<<endl;
                cout<<"Class Time: "<<list[i]->getclass_time()<<endl;
                cout<<"Class Room Number: "<<list[i]->getroom_number()<<endl<<endl;
            }
    }
    
    if (done == false) {
        cout<<"No Empty Class!!"<<endl<<endl;
    }
    
}

void cancelBooking(FitnessClass* list[], int currentMember) {
    
    bool done = false;
    int classID; int max;
    int* newMemberIDs = new int[max];
    
    cout<<"Enter the ID of the Fitness Class to be booked: ";
    cin>>classID;
    
    for (int i = 0; i<100; i++){
            
        max = list[i]->getmax_capacity();
            
            if (list[i]!=NULL && list[i]->getclassID() == classID) {
                    
                for (int j = 0; j<list[i]->getmax_capacity(); j++) {
                    
                    if (list[i]->list_of_members[j] == currentMember) {
                        continue;
                    }
                    
                    newMemberIDs[j] = list[i]->list_of_members[j];
                    
                }
                
                list[i]->list_of_members = newMemberIDs;
                list[i]->decrease_capacity();
                done = true;
                cout<<"Class Booking Cancelled Successfully!!"<<endl<<endl;
                break;
            }
    }
    
    if (done == false) {
        cout<<"Class not found"<<endl<<endl;
    }
}

void quitProgram(Admin* admin_list[], Member* member_list[], FitnessClass* fitnessclass_list[])
{
    //create input files for admin data, member data, Fitness classes data
    ofstream adminData;
    adminData.open("AdminsTable.txt", ios::out);
    if (adminData.fail())
    {
        cerr << "Error! File could not be opened." << endl;
        exit(1);
    }

    ofstream memberData;
    memberData.open("MembersTable.txt", ios::out);
    if (memberData.fail())
    {
        cerr << "Error! File could not be opened." << endl;
        exit(1);
    }
    
    ofstream classesData;
    classesData.open("FitnessClassesTable.txt", ios::out);
    if (classesData.fail())
    {
        cerr << "Error! File could not be opened." << endl;
        exit(1);
    }
    
    //traverse through the arrays and add the data of the object into the file line by line
    int i = 0;
    while(i < 100)
    {
        if (admin_list[i] != NULL)
        {
            adminData << admin_list[i]->getadminID() << "," << admin_list[i]->getfirst_name() << "," << admin_list[i]->getlast_name() << "," << admin_list[i]->getusername() << "," << admin_list[i]->getpassword() << endl;
        }
        i++;
    }
    int j = 0;
    while(j < 100)
    {
        if (member_list[j] != NULL)
        {
            memberData << member_list[j]->getmemberID() << "," << member_list[j]->getfirst_name() << "," << member_list[j]->getlast_name() << "," << member_list[j]->getusername() << "," << member_list[j]->getpassword() << endl;
        }
        j++;
    }
    int k = 0;
    while(k < 100)
    {
        if (fitnessclass_list[k] != NULL)
        {
            classesData << fitnessclass_list[k]->getclassID() << "," << fitnessclass_list[k]->getclass_name() << "," << fitnessclass_list[k]->getclass_date() << "," << fitnessclass_list[k]->getclass_time() << "," << fitnessclass_list[k]->getmax_capacity() << "," << fitnessclass_list[k]->getcurrent_capacity() << "," << fitnessclass_list[k]->getroom_number() << endl;
        }
        k++;
    }
    
    //de-allocating the memory for all the elements inside the array
    for (int i=0; i<100; i++)
    {
        delete admin_list[i];
        delete member_list[i];
        delete fitnessclass_list[i];
    }
    
    exit(0); //exit(0) is done so that the program automatically regardless just exits

}