// Represents the Fictional books which are not normally available to borrow
// from the library. The user can request access and be added to the waitlist.

#ifndef RESTRICTEDBOOK_H
#define RESTRICTEDBOOK_H

#include <string>
#include <vector>

#include "FictionBook.h"
#include "Member.h"

class RestrictedBook : public FictionBook {
 public:
  RestrictedBook();
  RestrictedBook(std::string title, std::string author, int yearOfPublication,
                 long int isbn, std::string genre, std::string synopsis);
  void requestAccess(Member* member);
  void displayInfo();
  ~RestrictedBook();
};

#endif