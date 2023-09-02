#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

using namespace std;

class Student {
    int admno;
    char grade;
    string firstName, lastName;
    string dateOfBirth, gender;
    string phoneNumber, emailAddress;
    float percentage, english, maths,science, hindi;
    
    public:

    // handles admin login credentials
    void adminLogin();
    
    // Contains functions for admin operations.
    void adminModules();            

    // Adds student data to a CSV file.
    void addStudentData();

    // Updates student data in a CSV file.
    void updateStudentData();
    
    // Displays all student data from a CSV file.
    void viewStudentData();
    
    // Deletes student data from a CSV file.
    void deleteStudentData(); 

    // mark attendance for students
    void markAttendance();

    // calculates percentage
    float calculatePercentage(float english, float maths, float science, float hindi);

    // calculte grades according to the percentage
    char getGrade(float per);

    // return the current date 
    string getCurrentDate();
    
};

#endif // ADMIN_H