#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "classes.h"

using namespace std;

Admin::Admin(int adminID, string first_name, string last_name, string username, string password):
        adminID(adminID), first_name(first_name), last_name(last_name), username(username), password(password){};
int Admin::getadminID(){return adminID;};
string Admin::getusername() {return username;};
string Admin::getpassword() {return password;};
string Admin::getfirst_name() {return first_name;};
string Admin::getlast_name() {return last_name;};

Member::Member(int memberID, string first_name, string last_name, string username, string password):
        memberID(memberID), first_name(first_name), last_name(last_name), username(username), password(password){};
int Member::getmemberID(){return memberID;};
string Member::getusername() {return username;};
string Member::getpassword() {return password;};
string Member::getfirst_name() {return first_name;};
string Member::getlast_name() {return last_name;};

FitnessClass::FitnessClass(int classID, string class_name, string class_date, string class_time, int max_capacity, int room_number): 
        classID(classID), class_name(class_name), class_date(class_date), class_time(class_time), max_capacity(max_capacity), room_number(room_number)
        {list_of_members = new int[max_capacity];
        };
int FitnessClass::getclassID(){return classID;};
string FitnessClass::getclass_name() {return class_name;};
string FitnessClass::getclass_date() {return class_date;};
string FitnessClass::getclass_time() {return class_time;};
int FitnessClass::getmax_capacity() {return max_capacity;};
int FitnessClass::getroom_number() {return room_number;};
int FitnessClass::getcurrent_capacity() {return current_capacity;};
void FitnessClass::increase_capacity() {current_capacity++;};
void FitnessClass::decrease_capacity() {current_capacity--;};
void FitnessClass::setclass_name(string name) {class_name = name;}
void FitnessClass::setclass_date(string date) {class_date = date;}
void FitnessClass::setclass_time(string time) {class_time = time;}
void FitnessClass::setmax_capacity(int capacity) {max_capacity = capacity;}
void FitnessClass::setroom_number(int room) {room_number = room;}
