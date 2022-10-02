#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

class Admin
{
    public:
        Admin(int adminID, string first_name, string last_name, string username, string password);
        int getadminID();
        string getusername();
        string getpassword();
        string getfirst_name();
        string getlast_name();
        
    private:
        int adminID;
        string first_name;
        string last_name;
        string username;
        string password;
        
};

class Member
{
    public:
        Member(int memberID, string first_name, string last_name, string username, string password);
        int getmemberID();
        string getusername();
        string getpassword();
        string getfirst_name();
        string getlast_name();
        friend class Admin;
        
    private:
        int memberID;
        string first_name;
        string last_name;
        string username;
        string password;
};

class FitnessClass
{
private:
    int classID;
    string class_name;
    string class_date;
    string class_time;
    int max_capacity;
    int room_number;
    int current_capacity = 0;
    

public:
    int* list_of_members;
    FitnessClass(int classID, string class_name, string class_date, string class_time, int max_capacity, int room_number);
    int getclassID();
    string getclass_name();
    string getclass_date();
    string getclass_time();
    int getmax_capacity();
    int getroom_number();
    int getcurrent_capacity();
    void increase_capacity();
    void decrease_capacity();
    
    void setclass_name(string name);
    void setclass_date(string date);
    void setclass_time(string time);
    void setmax_capacity(int capacity);
    void setroom_number(int room);


};

#endif