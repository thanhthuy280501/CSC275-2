#include <iostream>
#include <cstdlib>
using namespace std;

//****************************************************************************
// Program:	Server Simulation - static class members
// Author:	Stephen W. Turner
// Date:	08/31/22
//
// This program demonstrates a static class variable through a kind of
// simulation of "servers". They are very simple: each of them prints a
// string of the letter x, such as "xxxx" or "xxxxxxxxxxx" based on a random
// number passed to them. They also print a "hello" message with their
// individual identity, which is just an integer.
//
// The point of the program is to have a count across all instances
// of the class, so that a global summation can be found.
// Therefore, there is a static class variable called xcount,
// which counts the total number of x's printed across all class instances.
//****************************************************************************
class Server {
  public:

    Server(int i);
    Server();

    //****************************************************
    // Hey, an INLINE function! this one just sets the ID
    // of this class instance.
    //****************************************************
    void setID(int i) { ID = i; }

    //****************************************************
    // 'Cause I'm lazy, this is also an inline function.
    // This is the function that prints a string of
    // letter x, of random length.
    //****************************************************
    void printx(int count) {
      int j;
      for (j = 0; j < count; j++)
        cout << "x";
      xcount += count;
    }

    void hello() const;

    //****************************************************
    // Yet another inline. This one just prints the
    // value of the static class variable.
    //****************************************************
    void printCount() {
      cout << "total number of X printed: " << xcount << endl;
    }

  private:
    int ID;
    static int xcount;
};

//****************************************************
// prints a hello message, along with self ID.
//****************************************************
void Server::hello() const {
  cout << "Hello from server " << ID << endl;
}

//****************************************************
// Here are the constructors.
//****************************************************
Server::Server(int i) : ID(i) { }

Server::Server() : ID(0) { }

//****************************************************
// This is how you initialize a static class variable
//****************************************************
int Server::xcount = 0;

int main() {

  Server a[20];			// Array of 20 servers
  int i, j;			// couple of loop vars
  int tot;			// a total for x strings

  //********************************
  // set ID for each class instance
  //********************************
  for (j = 0; j < 20; j++)
    a[j].setID(j);


  srand(402);		// This sets a random number seed


  //***************************************************
  // For each class instance, generate a random number
  // between 1 and 21. call its printx() function to
  // print "that many" of the letter x.
  //***************************************************
  for (i = 0; i < 20; i++) {
    tot=1+(int) ((float) (21) *rand()/(RAND_MAX+1.0));
    a[i].hello();
    a[i].printx(tot);
    cout << endl;
  }

  //************************************************
  // This just shows that they all behave the same,
  // since xcount is basically a global across
  // class instances
  //************************************************
  a[0].printCount();
  a[2].printCount();
  a[10].printCount();

  return 0;
}
