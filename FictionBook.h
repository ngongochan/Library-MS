// Represents a fictional book in the library, with attributes such as
// Availability, which determines if the book can be borrowed, and a Wait List
// of the members wanting to borrow the book.

#include <string>
#include <vector>

#include "Book.h"
#include "Member.h"

#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

class FictionBook : public Book {
 private:
  bool isAvailable;
  std::vector<Member*> waitlist;  // vector of pointers to member objects

 public:
  FictionBook();
  FictionBook(std::string title, std::string author, int yearOfPublication,
              long int isbn, std::string genre, std::string synopsis);
  // void borrow(Member* member);
  void addToWaitlist(Member* member);
  bool get_isAvailable();
  void set_isAvailable(bool b);
  std::vector<Member*> get_waitlist();
  virtual void displayInfo();
  ~FictionBook();
};

#endif