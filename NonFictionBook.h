// represents a nonfiction book in the library, with attributes such as
// Availability, which determines if the book can be borrowed, and a Wait List
// of the members wanting to borrow the book.

#ifndef NONFICTIONBOOK_H
#define NONFICTIONBOOK_H

#include <string>
#include <vector>

#include "Book.h"
#include "Member.h"

class NonFictionBook : public Book {
 private:
  bool isAvailable;
  std::vector<Member*> waitlist;  // vector of pointers to member objects

 public:
  NonFictionBook();
  NonFictionBook(std::string title, std::string author, int yearOfPublication,
                 long int isbn, std::string genre, std::string synopsis);
  // void borrow(Member* member);
  void addToWaitlist(Member* member);
  bool get_isAvailable();
  void set_isAvailable(bool b);
  std::vector<Member*> get_waitlist();
  virtual void displayInfo();
  ~NonFictionBook();
};

#endif