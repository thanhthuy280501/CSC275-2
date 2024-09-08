class Student {
  public:
    void input();	// Read a student record in using cin.
    void output();	// Print out the student record, slightly formatted.
  private:
    string lname;	// Last name
    string fname;	// First name
    string ID;		// ID, presumably 8-digit but no error checking
    float gpa;		// GPA
};

//***************************************************
// Simply input all the values of a student record
//***************************************************
void Student::input() {
  cout << "Last name:  ";
  cin >> lname;
  cout << "First name:  ";
  cin >> fname;
  cout << "ID:  ";
  cin >> ID;
  cout << "GPA:  ";
  cin >> gpa;
}

//***************************************************
// Simply output the student record, formatted.
//***************************************************
void Student::output() {
  cout << fname << " " << lname << ", ID " << ID;
  cout << " has a gpa of " << gpa << endl;
};
