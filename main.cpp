#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "classes.h"
#include "functions.h"

using namespace std;

int main() {
    
    bool if_end = false, loggedin=false;
    string choice;
    string username;
    string password;
    int currentMember;

    // Create array for members and set to NULL
    Member* member_list[100];
    for (int i = 0; i<100; i++){member_list[i] = NULL;};

    // Create array for admins and set to NULL
    Admin* admin_list[100];
    for (int i = 0; i<100; i++){admin_list[i] = NULL;};

    // Create array for Fitness Classes and set to NULL
    FitnessClass* fitnessclass_list[100];
    for (int i = 0; i<100; i++){fitnessclass_list[i] = NULL;};
    
    admin_list[0] = new Admin(1, "admin", "admin", "admin1", "admin1");
    
    // Loop for when a user logs out
    while (if_end == false) {
            
        cout<<"Welcome to the Fitness Management System!!"<<endl;
        
        cout<<"Please enter the category of your account before logging in: [admin/member]"<<endl;
        cin>>choice;
        while (!(choice == "admin" || choice == "member")) {
            cout<<"Wrong Choice!! Please choose from [admin/member]: ";
            cin>>choice;
        };

        if (choice == "admin") {
            login(admin_list); //Call login function for admin
            loggedin=true;
        }
        else {

            // If no Member exists
            if (member_list[0] == NULL) {
                cout<<"No Member Registered yet!"<<endl;
                if_end = false;
                
           }
            else{
                login(member_list, currentMember); //Call login function for member
                loggedin=true;
            }
        }

        if (loggedin){
            cout<<"You have logged in successfuly!"<<endl;
            
            string menu_choice = menu(choice);
            
            // The Functions for admin
            while (choice == "admin") {
                
                // Register a New Admin
                if (menu_choice == "1") {
                    
                    string firstname;
                    string lastname;
                    int admin_pos;
                    
                    cout<<"Please enter Admin's first name: ";
                    cin>>firstname;
                    
                    cout<<"Please enter Admin's last name: ";
                    cin>>lastname;
                    
                    for (int i = 0; i<100; i++){
                        
                        if (admin_list[i] == NULL) {
                            
                            admin_list[i] = new Admin(register_admin(firstname, lastname)); //Make a new admin object
                            admin_pos = i;
                            
                            break;
                        };
                        
                    };
                    
                    cout<<"Admin ID: "<<admin_list[admin_pos]->getadminID()<<endl;
                    cout<<"First Name: "<<admin_list[admin_pos]->getfirst_name()<<endl;
                    cout<<"Last Name: "<<admin_list[admin_pos]->getlast_name()<<endl;
                    cout<<"Username: "<<admin_list[admin_pos]->getusername()<<endl;
                    cout<<"Password: "<<admin_list[admin_pos]->getpassword()<<endl;
                    
                    menu_choice = menu(choice);
                    
                }
                
                // Register a new member
                else if (menu_choice == "2") {
                    
                    string firstname;
                    string lastname;
                    int member_pos;
                    
                    cout<<"Please enter member's first name: ";
                    cin>>firstname;
                    
                    cout<<"Please enter member's last name: ";
                    cin>>lastname;
                    
                    for (int i = 0; i<100; i++){
                        
                        if (member_list[i] == NULL) {
                            
                            member_list[i] = new Member(register_member(firstname, lastname)); //Make a new member object
                            member_pos = i;
                            
                            break;
                        };
                        
                    };
                    
                    cout<<"Admin ID: "<<member_list[member_pos]->getmemberID()<<endl;
                    cout<<"First Name: "<<member_list[member_pos]->getfirst_name()<<endl;
                    cout<<"Last Name: "<<member_list[member_pos]->getlast_name()<<endl;
                    cout<<"Username: "<<member_list[member_pos]->getusername()<<endl;
                    cout<<"Password: "<<member_list[member_pos]->getpassword()<<endl;
                    
                    menu_choice = menu(choice);
                    
                }
                
                // Create a new Fitness Class
                else if (menu_choice == "3") {
                    
                    int class_pos;
                    
                    for (int i = 0; i<100; i++){
                        
                        if (fitnessclass_list[i] == NULL) {
                            
                            fitnessclass_list[i] = new FitnessClass(addFitnessClass()); // Make a new Fitness Class Object
                            class_pos = i;
                            
                            break;
                        };
                        
                    };
                    
                    menu_choice = menu(choice);
                }
                
                // Delete a Fitness Class
                else if (menu_choice == "4") {
                    
                    deleteFitnessClass(fitnessclass_list);
                    
                    menu_choice = menu(choice);
                }
                
                // Update the Fitness Class Details
                else if (menu_choice == "5") {
                    
                    updateClassDetails(fitnessclass_list);
                    
                    menu_choice = menu(choice);
                }
                
                // View Classes with Space left
                else if (menu_choice == "6") {
                    
                    viewClassesWithVacancies(fitnessclass_list);
                    
                    menu_choice = menu(choice);
                    
                }
                
                // Logout
                else if (menu_choice == "7") {
                    if_end = false;
                    break;
                }
                
                // Quit Program and Create Files
                else if (menu_choice == "8") {

                    quitProgram(admin_list, member_list, fitnessclass_list);
                    return EXIT_SUCCESS;

                }
                
            }
            
            // The functions for a member
            while (choice == "member") {
                
                // Book a class
                if (menu_choice == "1") {
                    
                    bookAClass(fitnessclass_list, currentMember);
                    
                    menu_choice = menu(choice);
                }
                
                // View Classes with Space left
                else if (menu_choice == "2") {
                    
                    viewClassesWithVacancies(fitnessclass_list);
                    
                    menu_choice = menu(choice);
                    
                }
                
                // Cancel Class Booking
                else if (menu_choice == "3") {
                    
                    cancelBooking(fitnessclass_list, currentMember);
                    
                    menu_choice = menu(choice);
                    
                }
                
                // Logout
                else if (menu_choice == "4") {
                    if_end = false;
                    break;
                }
                
                // Exit and Save to Files
                else if (menu_choice == "5") {

                    quitProgram(admin_list, member_list, fitnessclass_list);
                    return EXIT_SUCCESS;

                }
            }
            
        }
    }
}