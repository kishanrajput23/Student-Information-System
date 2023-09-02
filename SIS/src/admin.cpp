#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <exception>
#include <regex>
#include "../include/admin.h"

using namespace std;

int loginCount = 0;

// Function to check if a string contains only alphabetic characters.
bool isAlpha(const string &str)
{
    return all_of(str.begin(), str.end(), ::isalpha);
}

// Function to check if a date string is in the format 'YYYY-MM-DD'.
bool isValidDate(const string &date)
{
    regex datePattern(R"(\d{4}-\d{2}-\d{2})");
    return regex_match(date, datePattern);
}

// Function to check if a gender string is valid ('M', 'F', or 'NB').
bool isValidGender(const string &gender)
{
    return (gender == "M" || gender == "F" || gender == "NB");
}

// Function to check if a phone number string consists of 10 digits.
bool isValidPhoneNumber(const string &phoneNumber)
{
    regex phonePattern(R"(\d{10})");
    return regex_match(phoneNumber, phonePattern);
}

// Function to check if an email string is valid.
bool isValidEmail(const std::string &email)
{
    regex emailPattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    return regex_match(email, emailPattern);
}

// calculate percentage for a student
float Student::calculatePercentage(float eng, float mat, float sci, float hin)
{
    float total = eng + mat + sci + hin;
    float per = (total / 400) * 100;
    return per;
}

// calculate grades accordring to the percentage
char Student::getGrade(float percentage)
{
    if (percentage >= 90)
    {
        return 'A';
    }
    else if (percentage >= 80)
    {
        return 'B';
    }
    else if (percentage >= 70)
    {
        return 'C';
    }
    else if (percentage >= 60)
    {
        return 'D';
    }
    else if (percentage >= 50)
    {
        return 'E';
    }
    else
    {
        return 'F';
    }
}

// return the current date
string Student::getCurrentDate()
{
    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    struct tm timeInfo;
    localtime_r(&currentTime, &timeInfo); // For POSIX systems, use localtime_r

    char buffer[11]; // YYYY-MM-DD + null terminator
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeInfo);

    return string(buffer);
}

// Admin login function.
void Student::adminLogin()
{
    // Hardcoded admin username and password for simplicity.
    string userId = "admin";
    string password = "12345";
    string id, pass;

    // Display a welcome message.
    cout << "\n\n------------------------------------------" << endl;
    cout << "         Welcome To The Login Page         " << endl;
    cout << "------------------------------------------" << endl;
    cout << "\n\nPlease Enter Your Username & Password For Authentiocation" << endl;

    try
    {
        // Prompt for username and password.
        cout << "\nEnter Your Username : ";
        cin >> id;

        cout << "\nEnter Your Password : ";
        cin >> pass;

        // Loop until a correct username and password are provided or the login limit is reached.
        while (id != userId || pass != password)
        {
            cout << "\n!!!Login Error!!!" << endl;
            cout << "Please check your username or password again\n"
                 << endl;

            loginCount++;

            // If login attempts exceed 3, deny access.
            if (loginCount == 3)
            {
                cout << "ACCESS DENIED" << endl;
                cout << "You have reached your limit." << endl;
                exit(1);
            }

            cout << "\nEnter Your Username : ";
            cin >> id;

            cout << "\nEnter Your Password : ";
            cin >> pass;
        }
    }

    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }

    // Successful login message.
    cout << "\nCongratulations " << userId << endl;
    cout << "Your login as an administrator is successful.\n"
         << endl;

    // Proceed to adminModules.
    adminModules();
}

// Admin modules function, presenting options for administrative tasks.
void Student::adminModules()
{
    try
    {
        cout << "\nHere's your Dashboard \nPlease enter your choice to perform particular tasks" << endl;
        cout << "\n\n--------------------------------------------------------" << endl;
        cout << "\tEnter 1 -> To Add Student Data" << endl;
        cout << "\tEnter 2 -> To Update Student Data" << endl;
        cout << "\tEnter 3 -> To View Student Data" << endl;
        cout << "\tEnter 4 -> To Delete Student Data" << endl;
        cout << "\tEnter 5 -> To Mark Student Attendance" << endl;
        cout << "\tEnter 6 -> To Quit From This Session" << endl;
        cout << "--------------------------------------------------------" << endl;

        int choice;
        cout << "\n\nPlease enter your choice : ";
        cin >> choice;

        // Validate input choice to ensure it's a number between 1 and 5.
        while (cin.fail() || choice < 1 || choice > 6)
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a number between 1 and 5: ";
            cin >> choice;
        }

        // Perform the selected action based on the user's choice.
        switch (choice)
        {
        case 1:
            addStudentData();
            break;
        case 2:
            updateStudentData();
            break;
        case 3:
            viewStudentData();
            break;
        case 4:
            deleteStudentData();
            break;
        case 5:
            markAttendance();
            break;
        case 6:
            cout << "Thank you, will see you soon." << endl;
            break;

        default:
            cout << "Please choose valid Option" << endl;
            break;
        }
    }
    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

void Student::addStudentData()
{
    try
    {
        cout << "Enter the student's required information below" << endl;

        // Validate admission number
        cout << "Enter student admission number: ";
        while (!(cin >> admno) || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid admission number: ";
        }
        cin.ignore(256, '\n');

        // Validate first name
        cout << "Enter student first name: ";
        while (!(cin >> firstName) || !isAlpha(firstName))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid first name: ";
        }
        firstName[0] = toupper(firstName[0]);

        // Validate last name
        cout << "Enter student last name: ";
        while (!(cin >> lastName) || !isAlpha(lastName))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid last name: ";
        }
        lastName[0] = toupper(lastName[0]);

        // Validate date of birth
        cout << "Enter student date of birth (YYYY-MM-DD): ";
        while (!(cin >> dateOfBirth) || !isValidDate(dateOfBirth))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid date of birth (YYYY-MM-DD): ";
        }

        // Validate gender
        cout << "Enter student gender (M/F/NB): ";
        while (!(cin >> gender) || !isValidGender(gender))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid gender (M/F/NB): ";
        }

        // Clear newline character from previous input
        cin.ignore();

        // Validate phone number
        cout << "Enter student phone number: ";
        while (!(cin >> phoneNumber) || !isValidPhoneNumber(phoneNumber))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid phone number: ";
        }

        // Validate email address
        cout << "Enter student email address: ";
        while (!(cin >> emailAddress) || !isValidEmail(emailAddress))
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid email address: ";
        }

        cout << endl
             << "Now enter subject marks of the student below :" << endl;
        cout << "Enter english marks : ";
        while (!(cin >> english) || english < 1 || english > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> english;
        }

        cin.ignore(256, '\n');

        cout << "Enter math marks : ";
        while (!(cin >> maths) || maths < 1 || maths > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> maths;
        }
        cin.ignore(256, '\n');

        cout << "Enter science marks : ";
        while (!(cin >> science) || science < 1 || science > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> science;
        }
        cin.ignore(256, '\n');

        cout << "Enter hindi marks : ";
        while (!(cin >> hindi) || hindi < 1 || hindi > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> hindi;
        }
        cin.ignore(256, '\n');

        percentage = calculatePercentage(english, maths, science, hindi);
        grade = getGrade(percentage);

        // transferrinng all the student details into an csv file.
        ofstream f1("/Users/KI20449224/Downloads/SIS/data/student_details.csv", ios::app);
        f1 << admno << ", " << firstName << ", " << lastName << ", " << dateOfBirth << ", "
           << gender << ", " << phoneNumber << ", " << emailAddress << ", " << english << ", " << maths << ", " << science << ", " << hindi << ", " << percentage << ", " << grade << endl;

        cout << "\n Student record has been added successfully.\n"
             << endl;

        // transferring admin to its dashboard or giving option to quit from the session
        string opt;
        cout << "\nDo you want to add another student details (yes/no) : ";
        cin >> opt;

        // Input validation for opt
        while (true)
        {
            // Convert choice to lowercase for case-insensitive comparison
            transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

            if (opt == "yes")
            {
                addStudentData();
                break;
            }
            else if (opt == "no")
            {
                adminModules();
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 'yes' or 'no': ";
                cin >> opt;
            }
        }
    }
    catch (const std::exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

void Student::updateStudentData()
{
    int searchAdmNo;
    cout << "Enter the admission number of the student to update data: ";
    while (!(cin >> searchAdmNo) || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid input. Please enter a valid admission number: ";
    }
    cin.ignore(256, '\n');

    ifstream inputFile("/Users/KI20449224/Downloads/SIS/data/student_details.csv");
    ofstream tempFile("/Users/KI20449224/Downloads/SIS/data/temp.csv");

    bool found = false;
    string line;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string column;
        int admno;

        getline(ss, column, ',');
        admno = stoi(column); // Convert the string to integer

        if (admno == searchAdmNo)
        {
            found = true;

            cout << "Student found with admission number " << searchAdmNo << ". Please enter updated data:" << endl;
            cout << "Enter student first name : ";
            while (!(cin >> firstName) || !isAlpha(firstName))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid first name: ";
            }
            firstName[0] = toupper(firstName[0]);

            cout << "Enter student last name : ";
            while (!(cin >> lastName) || !isAlpha(lastName))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid last name: ";
            }
            lastName[0] = toupper(lastName[0]);

            cout << "Enter student date of birth (YYYY-MM-DD): ";
            while (!(cin >> dateOfBirth) || !isValidDate(dateOfBirth))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid date of birth (YYYY-MM-DD): ";
            }

            cout << "Enter student gender (M/F/NB): ";
            while (!(cin >> gender) || !isValidGender(gender))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid gender (M/F/NB): ";
            }

            cin.ignore();

            cout << "Enter student phone number: ";
            while (!(cin >> phoneNumber) || !isValidPhoneNumber(phoneNumber))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid phone number: ";
            }

            cout << "Enter student email address: ";
            while (!(cin >> emailAddress) || !isValidEmail(emailAddress))
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Invalid input. Please enter a valid email address: ";
            }

            cout << endl
             << "Now enter subject marks of the student below :" << endl;
        cout << "Enter english marks : ";
        while (!(cin >> english) || english < 1 || english > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> english;
        }

        cin.ignore(256, '\n');

        cout << "Enter math marks : ";
        while (!(cin >> maths) || maths < 1 || maths > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> maths;
        }
        cin.ignore(256, '\n');

        cout << "Enter science marks : ";
        while (!(cin >> science) || science < 1 || science > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> science;
        }
        cin.ignore(256, '\n');

        cout << "Enter hindi marks : ";
        while (!(cin >> hindi) || hindi < 1 || hindi > 100 || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "\nInvalid input. Please enter a marks between 1 and 100: ";
            cin >> hindi;
        }
        cin.ignore(256, '\n');

        percentage = calculatePercentage(english, maths, science, hindi);
        grade = getGrade(percentage);

            // Write the updated data to temp file
            tempFile << admno << ", " << firstName << ", " << lastName << ", " << dateOfBirth << ", " << gender <<", " << phoneNumber << ", " << emailAddress << ", " << english << ", " << maths << ", " << science << ", " << hindi << ", " << percentage << ", " << grade  << endl;
        }
        else
        {
            // Write the original data to temp file
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!found)
    {
        cout << "Student with admission number " << searchAdmNo << " not found." << endl;
    }
    else
    {
        // Rename the temp file to replace the original file
        remove("/Users/KI20449224/Downloads/SIS/data/student_details.csv");
        rename("/Users/KI20449224/Downloads/SIS/data/temp.csv", "/Users/KI20449224/Downloads/SIS/data/student_details.csv");
        cout << "Student data updated successfully." << endl;
    }

    string opt;
    cout << "\nDo you want to update another student details (yes/no) : ";
    cin >> opt;

    // Input validation for opt
    while (true)
    {
        // Convert choice to lowercase for case-insensitive comparison
        transform(opt.begin(), opt.end(), opt.begin(), ::tolower);

        if (opt == "yes")
        {
            updateStudentData();
            break;
        }
        else if (opt == "no")
        {
            adminModules();
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'yes' or 'no': ";
            cin >> opt;
        }
    }
}

void Student::viewStudentData()
{
    try // exception handling if it might occur during execution of the program
    {
        ifstream file("/Users/KI20449224/Downloads/SIS/data/student_details.csv");
        if (!file.is_open())
        {
            throw runtime_error("Error opening file: student.csv");
        }

        cout << "Below are the list of students" << endl;

        cout << setw(21) << "Adm No" << setw(19) << "First Name" << setw(19) << "Last Name" << setw(13) << "DOB" << setw(25) << "Gender" << setw(15) << "PH No." << setw(15) << "Email" << setw(27) << "English" <<setw(18) << "Math" <<setw(20) << "Science" <<setw(19) << "Hindi" <<setw(20) << "Percentage" <<setw(18) << "Grade" <<  endl;

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string column;

            while (getline(ss, column, ','))
            {
                // Remove commas from each column
                column.erase(remove(column.begin(), column.end(), ','), column.end());

                cout << setw(19) << column; // set width of 19 size
            }
            cout << endl;
        }
        file.close();

        string choice;

        cout << "/n Do you want to continue with the session (yes/no)";
        cin >> choice;

        // Input validation for choice
        while (true)
        {
            // Convert choice to lowercase for case-insensitive comparison
            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            if (choice == "yes")
            {
                adminModules(); // Call the function with ()
                break;
            }
            else if (choice == "no")
            {
                cout << "See you again" << endl;
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 'yes' or 'no': ";
                cin >> choice;
            }
        }
    }
    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

void Student::deleteStudentData()
{
    try
    {
        int searchAdmNo;
        cout << "Enter the admission number of the student to delete data: ";
        while (!(cin >> searchAdmNo) || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid input. Please enter a valid admission number: ";
        }
        cin.ignore(256, '\n');

        ifstream inputFile("/Users/KI20449224/Downloads/SIS/data/student_details.csv");
        ofstream tempFile("/Users/KI20449224/Downloads/SIS/data/temp.csv");

        bool found = false;
        string line;

        while (getline(inputFile, line))
        {
            stringstream ss(line);
            string column;
            int admno;

            getline(ss, column, ',');
            admno = stoi(column); // Convert the string to integer

            if (admno == searchAdmNo)
            {
                found = true;
                cout << "Student found with admission number " << searchAdmNo << ". Data deleted." << endl;
            }
            else
            {
                // Write the original data to temp file
                tempFile << line << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        if (!found)
        {
            cout << "Student with admission number " << searchAdmNo << " not found." << endl;
        }
        else
        {
            // Rename the temp file to replace the original file
            remove("/Users/KI20449224/Downloads/SIS/data/student_details.csv");
            rename("/Users/KI20449224/Downloads/SIS/data/temp.csv", "/Users/KI20449224/Downloads/SIS/data/student_details.csv");
            cout << "Student data deleted successfully." << endl;
        }

        string choice;

        cout << "/n Do you want to continue with the session (yes/no) : ";
        cin >> choice;

        // Input validation for choice
        while (true)
        {
            // Convert choice to lowercase for case-insensitive comparison
            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            if (choice == "yes")
            {
                adminModules(); // Call the function with ()
                break;
            }
            else if (choice == "no")
            {
                cout << "See you again" << endl;
                break;
            }
            else
            {
                cout << "Invalid input. Please enter 'yes' or 'no': ";
                cin >> choice;
            }
        }
    }
    catch (exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }
}

// mark aatendance for students
void Student::markAttendance()
{
    try
    {
        ifstream inputFile("/Users/KI20449224/Downloads/SIS/data/student_details.csv");

        if (!inputFile.is_open())
        {
            cerr << "Error opening file for reading: student_data.csv" << endl;
            return;
        }

        ofstream tempFile("/Users/KI20449224/Downloads/SIS/data/temp.csv");

        if (!tempFile.is_open())
        {
            cerr << "Error opening file for writing: temp.csv" << endl;
            return;
        }

        string line;
        while (getline(inputFile, line))
        {
            tempFile << line << endl; // Copy original data to temp file
        }

        inputFile.close();
        tempFile.close();

        ifstream tempInputFile("/Users/KI20449224/Downloads/SIS/data/temp.csv");
        ofstream outputFile("/Users/KI20449224/Downloads/SIS/data/student_attendance.csv");

        if (!tempInputFile.is_open())
        {
            cerr << "Error opening file for reading: temp.csv" << endl;
            return;
        }

        if (!outputFile.is_open())
        {
            cerr << "Error opening file for writing: student_details.csv" << endl;
            return;
        }

        cout << "Mark attendance for each student (Type 'P' for Present || Type 'A' for Absent):" << endl;

        string currentDate = getCurrentDate(); // Implement this function to get the current date in YYYY-MM-DD format

        while (getline(tempInputFile, line))
        {
            outputFile << line; // Copy original data to output file

            int lastCommaPos = line.find_last_of(',');
            string admnoStr = line.substr(0, lastCommaPos);
            int admno = stoi(admnoStr);

            cout << "Student with Admission Number " << admno << ": ";
            char attendanceStatus;
            while (true)
            {
                cin >> attendanceStatus;
                cin.ignore(256, '\n'); // Clear the newline character left in the buffer

                if (attendanceStatus == 'P' || attendanceStatus == 'A')
                {
                    break; // Valid input, exit the loop
                }
                else
                {
                    cout << "Invalid input. Please enter 'P' for Present or 'A' for Absent: ";
                }
            }

            outputFile << ", " << currentDate << ": " << attendanceStatus << endl;
        }

        tempInputFile.close();
        outputFile.close();

        remove("/Users/KI20449224/Downloads/SIS/data/temp.csv");

        cout << "Attendance marked for all students." << endl;
    }
    catch (const std::exception &ex)
    {
        cerr << "Exception caught: " << ex.what() << endl;
    }

    string choice;

    cout << "/n Do you want to continue with the session (yes/no) : ";
    cin >> choice;

    // Input validation for choice
    while (true)
    {
        // Convert choice to lowercase for case-insensitive comparison
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "yes")
        {
            adminModules(); // Call the function with ()
            break;
        }
        else if (choice == "no")
        {
            cout << "See you again" << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Please enter 'yes' or 'no': ";
            cin >> choice;
        }
    }
}