#include "DonateUnitTest.h"

#include <iostream>

// compile this .cpp file with the command
// g++ -Wall DonateUnitTest.cpp Donate.cpp Transaction.cpp Member.cpp
// RestrictedBook.cpp FictionBook.cpp Book.cpp -o DonateUnitTest

int main() {
  DonateUnitTest donateUnitTest;
  donateUnitTest.runTests();

  return 0;
}