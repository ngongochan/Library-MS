#ifndef LIBRARYDATABASEFUNCTIONSTEST_H
#define LIBRARYDATABASEFUNCTIONSTEST_H

#include <cassert>
#include <iostream>
#include <sstream>

#include "LibraryDatabaseFunctions.h"

class LibraryDatabaseFunctionsTest {
 public:
  void runTests() {
    testCreateLibraryBooks();
    testSearch();
    testMember();
    testBorrow();
    testReturn();
    testHistory();
    testDonate();
  }

 private:
  void testCreateLibraryBooks() {
    Library library;
    createLibraryBooks(&library);
    assert(!library.get_Fbooks().empty() && "adding fiction books.");
    assert(!library.get_NFbooks().empty() && "adding non-fiction books.");

    std::cout << "adding book passed" << std::endl;
  }
  void testSearch() {
    Library library;
    createLibraryBooks(&library);
    std::stringstream input("F\nFahrenheit 451\nX\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    search(&library);
    std::cin.rdbuf(orig);
    std::cout << "search test passed" << std::endl;
  }
  void testMember() {
    Library library;
    std::stringstream input("Tom\n1996-11-03\ntom@gmail.com\n445 Glandore\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    member1(&library);
    std::cin.rdbuf(orig);
    library.get_members();
    std::ifstream file("members.txt");
    assert(file.is_open() && "members file should be opened");
    std::string line;
    bool memberFound = false;
    while (std::getline(file, line)) {
      if (line.find("Name: Tom") != std::string::npos &&
          line.find("Email: tom@gmail.com") != std::string::npos) {
        memberFound = true;
        break;
      }
    }
    file.close();
    std::remove("members.txt");
    assert(memberFound && "adding member to the library");
    std::cout << "member added" << std::endl;
  }

  void testBorrow() {
    Library library;
    createLibraryBooks(&library);
    Member* member =
        new Member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    library.addMember(member);
    std::stringstream input;
    input << "tom@gmail.com\n" << member->get_ID() << "\n1451673264\nY\nN\n";
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    borrow(&library);
    std::cin.rdbuf(orig);
    assert(!member->get_borrowHistory().empty() &&
           "borrowed book added to borrow history");
    std::cout << "borrow test passed!" << std::endl;
  }

  void testReturn() {
    Library library;
    createLibraryBooks(&library);
    Member* member =
        new Member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    library.addMember(member);
    Book* book = library.checkBook(1451673264);
    Borrow* borrowTransaction = new Borrow(book, member);
    member->add_borrow(borrowTransaction);
    library.addTransaction(borrowTransaction);
    std::stringstream input;
    input << "tom@gmail.com\n" << member->get_ID() << "\n1451673264\nY\nN\n";
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    returnb(&library);
    std::cin.rdbuf(orig);
    assert(book->get_isAvailable() && "returning books");
    std::cout << "return test passed" << std::endl;
  }

  void testHistory() {
    Library library;
    createLibraryBooks(&library);
    Member* member =
        new Member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    library.addMember(member);
    Book* book = library.checkBook(1451673264);
    Borrow* borrowTransaction = new Borrow(book, member);
    member->add_borrow(borrowTransaction);
    library.addTransaction(borrowTransaction);
    std::stringstream input;
    input << "tom@gmail.com\n" << member->get_ID() << "\n";
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    history(&library);
    std::cin.rdbuf(orig);
    std::ifstream inFile("borrow_history.txt");
    assert(inFile.is_open() && "generating borrow history");
    inFile.close();
    std::remove("borrow_history.txt");

    std::cout << "borrowing history test passed" << std::endl;
  }

  void testDonate() {
    Library library;
    std::stringstream input(
        "F\nrandom donated book title\nrandom donated book "
        "author\n2006\n12342345\nCool stuff\n5\n");
    std::streambuf* orig = std::cin.rdbuf(input.rdbuf());
    donate(&library);
    std::cin.rdbuf(orig);
    bool bookFound = false;
    for (auto& book : library.get_Fbooks()) {
      if (book->get_title() == "random donated book title" &&
          book->get_author() == "random donated book author") {
        bookFound = true;
        break;
      }
    }
    assert(bookFound && "adding donated book to library");
    std::cout << "donation received" << std::endl;
  }
};

#endif