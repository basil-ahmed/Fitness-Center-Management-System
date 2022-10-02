# Fitness-Center-Management-System

## Introduction

This is a simple system for Fitness Center Management, which is accessible by administrative staff and members. It stores and manages the fitness classes at the center. An admin can mainly add/delete fitness classes, and register a member. On the other hand, a member can mainly book a spot in a class, and cancel a booking.

The program utilizes the concepts of object-oriented programming (OOP) (this may include: Classes, inheritance, templates, and error handling).

## Implementation

### Initialization:

1. The system should have at least the following classes defined with their main attributes: 
a) Admin Class – Admin ID, First name, Last name, Username, Password.
b) Member Class – Member ID, First name, Last name, Username, Password.
c) FitnessClass Class – Class ID, Class Name, Class date, Class time, Maximum capacity, Room number, List of members.
 - The list of members should be implemented as an array of member IDs.

2. You need to have a single default (built-in) admin account (i.e., an object of the Admin class) that will act as the first admin user in the system. This means you can automate the creation of this user, in particular, with the following details and credentials:
AdminID: 1, First_name: admin, Last_name: admin, Username: admin1, Password: admin1

### Main Operations:

1. The program should print out a welcome message and ask the user to identify themselves either as an administrative staff or as a member. Figure 1 shows an illustration of the expected user interface and how the different operations should be invoked. Refrain from asking the user to enter a long input to invoke a task; a number from the list should suffice.

2. The system will ask the user to log in by providing their credentials (username and password). If the credentials are valid, the corresponding (terminal) interface will appear with the list of possible actions they can choose from with respect to their category.
  a) If invalid credentials are provided, a message should appear asking the user to re- enter their credentials.
  b) Only registered members can log in to the system.
 
3. login(..): Any registered user should be able to login by entering a valid set of username and password, with respect to their category.

4. registerMember(..): An admin should be able to register a member in the system by providing the member’s first name and the last name. The member ID, username and password of the new member should be generated automatically as follows:
a) Member ID: a randomly generated number of 4 digits. You need to make sure the generated ID is unique. (Hint: you may use the rand() method from cstdlib (sodlib.h) headerfile, e.g. int pw = rand()%100; //pw in the range 0 to 99)
b) Username: lowercase the first name and concatenate it with the member ID.
c) Password: lowercase the last name and concatenate it with another randomly
generated number of 4 digits.

5. registerAdmin(..): An admin should be able to register another admin in the system by providing the admin’s first name and the last name. The admin ID, username and password of the new member should be generated automatically as follows:
a) Admin ID: a randomly generated number of 4 digits. You need to make sure the generated ID is unique.
b) Username: lowercase the first name and concatenate it with the admin ID.
c) Password: lowercase the last name and concatenate it with another randomly
generated number of 4 digits.

6. addFitnessClass(..): An admin should be able to add a new fitness class, which is initially with an empty list of members, by providing the following details:
Class ID, Class Name, Class date, Class time, Maximum capacity, Room number

7. deleteFitnessClass(..): An admin should be able to delete a fitness class by providing its ID.

8. updateClassDetails(..): An admin should be able to update a class assigned name/capacity/room/date/time by providing the class ID and the updated value. The user should be able to choose what data member to update. A single data member is to be updated with every call of this method.

9. bookAClass(..): A member should be able to book a spot in a class, if the maximum capacity has not been reached yet, by providing the class ID.
a) As a result, the member will be added to the list of members of that class.

10. viewClassesWithVacancies(..): Any user should be able to view the list of classes that are not yet full. For each class in the list, display all the class information, except for the class capacity and the list of members.

11.cancelBooking(..): A member should be able to cancel a booking by providing the class ID. The class’s list of members should be updated accordingly.

12. quitProgram(..): Any user should be able to quit the program properly.
The system should create files with the data recorded during the current session:
a) The list of classes should be saved in a “FitnessClassesTable.txt” file. For each class record, the values of all the data members, except for the list of members, should be saved, comma separated, as follows [Class ID, Class Name, Class date, Class time, Maximum capacity, Room number].
An example of a class record: 1,Boxing,23-09-21,16:00,20,2
b) The list of Admin should be saved in a “AdminsTable.txt” file. For each admin record, the values of all the data members should be saved, comma separated, [Admin ID,
First name, Last name, Username, Password].
An example of an admin record: 6564,Mai,Oudah,mai6564,oudah8382
c) The list of members should be saved in a “MembersTable.txt” file. For each member record, the values of all the data members should be saved, comma separated
[Member ID, First name, Last name, Username, Password].
An example of a member record: 5879,Jones,Ray,jones5879,ray8422

• The system should ask for the relevant information (i.e., arguments) needed to be provided by the user for each of the aforementioned operations.
• You can add more classes/operations as you see fit.
• You will need to use big arrays of pointers to the instances created from each class in any open session of the program. Each pointer is initially pointing towards NULL. Once a relevant object is created, the next available pointer in the array can point towards that object. Proper deallocation of the arrays upon quitting the program is required.
• The system should handle errors, missing and invalid input.
• The system should print out a message indicating that an operation was completed successfully.
