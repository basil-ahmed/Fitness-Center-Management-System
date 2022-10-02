#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

//Function Prototypes
void login(Admin* list[]);
void login(Member* list[], int& currentMember);
string menu(string choice);
Member register_member(string firstname, string lastname);
Admin register_admin(string firstname, string lastname);
FitnessClass addFitnessClass();
void deleteFitnessClass(FitnessClass* list[]);
void updateClassDetails(FitnessClass* list[]);
void bookAClass(FitnessClass* list[], int currentMember);
void viewClassesWithVacancies(FitnessClass* list[]);
void cancelBooking(FitnessClass* list[], int currentMember);
void quitProgram(Admin* admin_list[], Member* member_list[], FitnessClass* fitnessclass_list[]);

#endif