#ifndef BORROW_H
#define BORROW_H

class Member;
class Book;

#include "Transaction.h"
// #include "Member.h"
// #include "Book.h"
#include <ctime>

class Borrow : public Transaction {
 private:
  // Member: pointer to objects of Member class
  Member* member;
  time_t dateBorrowed;
  bool isOverdue;
  bool isReturned;

 public:
  Borrow();

  Borrow(Book* book, Member* member);

  void print();

  void set_member(Member* member);

  Member* get_member();

  void set_dateBorrowed(time_t);

  time_t get_date();

  bool get_isOverdue();

  void set_isReturned(bool);

  bool get_isReturned();

  ~Borrow();
};

#endif