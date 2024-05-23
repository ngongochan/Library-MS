#ifndef DONATEUNITTEST_H
#define DONATEUNITTEST_H

#include <ctime>
#include <iostream>

#include "Donate.h"
#include "Member.h"
#include "RestrictedBook.h"
#include "Transaction.h"

class DonateUnitTest {
 public:
  void runTests() {
    infoTest();
    std::cout << "\n";
  }

 private:
  void infoTest() {
    Book* book1 = new RestrictedBook(
        "Introduction to Algorithms",
        "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford "
        "Stein",
        2009, 9780262033848, "Computer Science",
        "This seminal text offers a comprehensive introduction to the design "
        "and analysis of algorithms, covering a range of techniques and "
        "applications in computer science and beyond.");
    Donate* donate1 = new Donate(book1, 5);

    if (book1->get_title() != "Introduction to Algorithms" &&
        book1->get_author() !=
            "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, "
            "Clifford Stein" &&
        book1->get_yearOfPublication() != 2009 &&
        book1->get_ISBN() != 9780262033848 &&
        book1->get_genre() != "Computer Science" &&
        book1->get_synopsis() !=
            "This seminal text offers a comprehensive introduction to the "
            "design and analysis of algorithms, covering a range of techniques "
            "and applications in computer science and beyond.") {
      std::cout << "Test for book's information storing failed!" << std::endl;
    }

    // book1->displayInfo();

    // donate1->print();

    delete donate1;
  }
};
#endif