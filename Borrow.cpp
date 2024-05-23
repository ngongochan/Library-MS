#include "Borrow.h"

#include <iostream>

#include "Book.h"
#include "Member.h"
#include "Transaction.h"

Borrow::Borrow() {}

// still working on the timer
Borrow::Borrow(Book* book, Member* member) {
  dateBorrowed = time(0);
  this->member = member;
  book->set_isAvailable(false);
  set_book(book);
  // use while loop with something like while( time(0) - dateBorrowed < 30 days)
  // // whats 30 days in t
  isOverdue = false;
  isReturned = false;
}

// print(): prints details of borrow transaction
// all attributes of member and book are printed
void Borrow::print() {
  std::cout << "Transaction Details\n"
            << "Member:                " << member->get_name() << "\n"
            << "Date of Birth:         " << member->get_DOB() << "\n"
            << "Email Address:         " << member->get_email() << "\n"
            << "Member ID:             " << member->get_ID() << "\n"
            << "Home Address:          " << member->get_homeAddress() << "\n\n"
            <<

      "Date of Borrow:        " << ctime(&dateBorrowed) << "\n\n"
            <<

      "Book borrowed    " << "\n\n"
            <<

      "Title:                 " << book->get_title() << "\n"
            << "Author:                " << book->get_author() << "\n"
            << "Year of Publication:   " << book->get_yearOfPublication()
            << "\n"
            << "ISBN:                  " << book->get_ISBN() << "\n"
            << "Genre:                 " << book->get_genre() << std::endl;
}

// set_member(member)
void Borrow::set_member(Member* member) { this->member = member; }

// get_member(member)
Member* Borrow::get_member() { return member; }

void Borrow::set_dateBorrowed(time_t date) { dateBorrowed = time(0); }

time_t Borrow::get_date() { return dateBorrowed; }

bool Borrow::get_isOverdue() {
  std::time_t currentTime = time(0);
  // 30 days = 2,592,000 seconds
  // std::time_t timeDiff = currentTime - dateBorrowed;
  std::time_t timeRemaining =
      2592000 -
      difftime(currentTime, dateBorrowed);  // 30 days - (time they've had book)
  if (timeRemaining <= 0) {
    isOverdue = true;
    member->set_canBorrow(false);
  }

  return isOverdue;
}

// does this set_isReturned work as a return function?
void Borrow::set_isReturned(bool isReturned) {
  this->isReturned = isReturned;
  // if a book is returned, overdue = false
  if (isReturned == true) {
    isOverdue = false;
  }
}

bool Borrow::get_isReturned() { return isReturned; }

Borrow::~Borrow() { delete[] member; }