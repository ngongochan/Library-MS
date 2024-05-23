#ifndef TRANSACTION_H
#define TRANSACTION_H

class Book;    // Forward declaration
class Member;  // Forward declaration

// #include "Book.h"
#include <ctime>
// #include "Member.h"

class Transaction {
 protected:
  Book* book;
  Member* member;

 public:
  // print(): pure virtual to be overridden by derived classes

  Transaction();

  virtual void print() = 0;

  // set_book(book)
  void set_book(Book* book);

  // get_book()
  Book* get_book();

  virtual Member* get_member() = 0;

  virtual std::time_t get_date() = 0;
};

#endif