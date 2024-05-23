#ifndef BORROWUNITTEST_H
#define BORROWUNITTEST_H

#include <ctime>
#include <iostream>

#include "AcademicText.h"
#include "Borrow.h"
#include "Member.h"
#include "Transaction.h"

// book functions tested: get_title(), get_author(), get_yearOfPublication(),
// get_genre(), get_ISBN(), get_synopsys(), get_isAvailable(), displayInfo()
// member functions tested: get_name(), get_email(), get_DOB(),
// get_homeAddress() remaining: print() - segmentation fault,
// set_dateBorrowed(), get_date(), get_book(), set_book(), get_member(),
// set_member()

class BorrowUnitTest {
 public:
  void runTests() {
    infoTest();
    bookAvailabilityTest();
    std::cout << "\n";
    editInfoTest();
  }

 private:
  // member1->add_borrow(borrow1); // this declaration has no storage class or
  // type specifierC/C++(77)

  void infoTest() {
    Member* member1 =
        new Member("Member 1", "20/03/2003", "abcde@gmail.com", "Adelaide, SA");
    Book* book1 = new AcademicText(
        "Introduction to Algorithms",
        "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford "
        "Stein",
        2009, 9780262033848, "Computer Science",
        "This seminal text offers a comprehensive introduction to the design "
        "and analysis of algorithms, covering a range of techniques and "
        "applications in computer science and beyond.",
        "The MIT Press", 3);

    Borrow* borrow1 = new Borrow(book1, member1);

    // test member's info
    if (member1->get_name() != "Member 1" &&
        member1->get_DOB() != "20/03/2003" &&
        member1->get_email() != "abcde@gmail.com" &&
        member1->get_homeAddress() != "Adelaide, SA") {
      std::cout << "Test for member's information storing failed!" << std::endl;
    }

    // test book's info
    // book1 pointer is of base class Book that doesn't know about the
    // get_academicInstitute() function and get_volume() those functions cant be
    // tested using the base class pointer
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

    book1->displayInfo();

    // std::cout << "\n\n";

    // borrow1->print(); // can print everything except the book's info

    delete borrow1;
  }

  void bookAvailabilityTest() {
    Member* member1 =
        new Member("Member 1", "20/03/2003", "abcde@gmail.com", "Adelaide, SA");
    Book* book1 = new AcademicText(
        "Introduction to Algorithms",
        "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford "
        "Stein",
        2009, 9780262033848, "Computer Science",
        "This seminal text offers a comprehensive introduction to the design "
        "and analysis of algorithms, covering a range of techniques and "
        "applications in computer science and beyond.",
        "The MIT Press", 3);
    Borrow* borrow1 = new Borrow(book1, member1);

    if (book1->get_isAvailable() != false) {
      std::cout << "Test 1 for book's availability failed!" << std::endl;
    }

    book1->set_isAvailable(true);
    if (book1->get_isAvailable() != true) {
      std::cout << "Test 2 for book's availability failed!" << std::endl;
    }

    delete borrow1;
  }

  // why doesn't this line of code work
  // borrow1->print(); // segmentation fault

  // edit info using setters
  void editInfoTest() {
    Member* member1 =
        new Member("Member 1", "20/03/2003", "abcde@gmail.com", "Adelaide, SA");
    Book* book1 = new AcademicText(
        "Introduction to Algorithms",
        "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford "
        "Stein",
        2009, 9780262033848, "Computer Science",
        "This seminal text offers a comprehensive introduction to the design "
        "and analysis of algorithms, covering a range of techniques and "
        "applications in computer science and beyond.",
        "The MIT Press", 3);
    Borrow* borrow1 = new Borrow(book1, member1);

    member1->set_name("Member 2");
    member1->set_DOB("20/02/2002");
    member1->set_email("fghij@yahoo.com");
    member1->set_homeAddress("Sydney, NSW");

    book1->set_title("Engineering Mechanics: Dynamics");
    book1->set_author("J. L. Meriam, L. G. Kraige");
    book1->set_yearOFPublication(2016);
    book1->set_genre("Engineering");
    book1->set_synopsis(
        "This engineering mechanics textbook focuses on the study of dynamics, "
        "covering topics such as kinematics, kinetics, particle dynamics, "
        "rigid-body dynamics, and mechanical vibrations.");
    book1->set_ISBN(9781118885840);

    if (member1->get_name() != "Member 2" &&
        member1->get_DOB() != "20/02/2002" &&
        member1->get_email() != "fghij@yahoo.com" &&
        member1->get_homeAddress() != "Sydney, NSW") {
      std::cout << "Test for member's information editing failed!" << std::endl;
    }

    if (book1->get_title() != "Engineering Mechanics: Dynamics" &&
        book1->get_author() != "J. L. Meriam, L. G. Kraige" &&
        book1->get_yearOfPublication() != 2016 &&
        book1->get_ISBN() != 9781118885840 &&
        book1->get_genre() != "Engineering" &&
        book1->get_synopsis() !=
            "This engineering mechanics textbook focuses on the study of "
            "dynamics, covering topics such as kinematics, kinetics, particle "
            "dynamics, rigid-body dynamics, and mechanical vibrations.") {
      std::cout << "Test for book's information editing failed!" << std::endl;
    }

    book1->displayInfo();

    delete borrow1;
  }
};

#endif