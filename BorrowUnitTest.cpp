#include "BorrowUnitTest.h"

#include <iostream>

// compile this .cpp file with the command
// g++ -Wall BorrowUnitTest.cpp Borrow.cpp Transaction.cpp Member.cpp
// AcademicText.cpp NonFictionBook.cpp Book.cpp -o BorrowUnitTest

int main() {
  BorrowUnitTest borrowUnitTest;
  borrowUnitTest.runTests();

  return 0;
}