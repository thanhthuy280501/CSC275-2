#include <iostream>
using namespace std;

#include "student.cpp"

//*******************************************************************
// Program:	in-class exercise #2
// Author:	Thuy Nguyen
// Class: CSC 275
// Date:	09/06/24 and 09/08/24
// This program creates instances of class Student and demonstrates
// the use of various features of the class
//*******************************************************************

class Student {
public:
    // Default constructor
    Student() : lname("Doe"), fname("John"), ID("00000000"), gpa(0.0) {}

    // Constructor with parameters
    Student(const string &ln, const string &fn, const string &id, float g) 
        : lname(ln), fname(fn), ID(id), gpa(g) {}

    // Accessor functions
    string getLastName() const { return lname; }
    string getFirstName() const { return fname; }
    string getID() const { return ID; }
    float getGPA() const { return gpa; }

    // Mutator functions
    void setLastName(const string &LN) { lname = LN; }
    void setFirstName(const string &FN) { fname = FN; }
    void setID(const string &Id) { ID = Id; }
    void setGPA(float GPA) { gpa = GPA; }

    // Inline mutator function
    void setFullName(const string &LN, const string &FN) {
        lname = LN;
        fname = FN;
    }

    // Non-inline mutator function
    void setStudentInfo(const string &LN, const string &FN, const string &Id, float GPA) {
        lname = LN;
        fname = FN;
        ID = Id;
        gpa = GPA;
    }

    void input(); // Read a student record in using cin.
    void output(); // Print out the student record, slightly formatted.

private:
    string lname; // Last name
    string fname; // First name
    string ID; // ID, presumably 8-digit but no error checking
    float gpa; // GPA
};

// Implementation of input and output functions
void Student::input() {
    cout << "Last name: ";
    cin >> lname;
    cout << "First name: ";
    cin >> fname;
    cout << "ID: ";
    cin >> ID;
    cout << "GPA: ";
    cin >> gpa;
}

void Student::output() {
    cout << fname << " " << lname << ", ID " << ID;
    cout << " has a GPA of " << gpa << endl;
}

int main( ){
  Student s1; // (1) Default constructor
    s1.output();

    Student s2("Smith", "Alice", "12345678", 3.5); // (2) Constructor with parameters
    s2.output();

    // (4) Mutator functions example
    s1.setLastName("Doe");
    s1.setFirstName("Jane");
    s1.setID("87654321");
    s1.setGPA(3.0);

    s1.output();

    // (5) Inline mutator function example
    s1.setFullName("Johnson", "Robert");
    s1.output();

    // (6) Non-inline mutator function example
    s1.setStudentInfo("Brown", "Emily", "23456789", 3.7);
    s1.output();

    return 0;
}
 
