// Represents a book in the library, and has attributes such as Title, Author,
// Year of Publication, and ISBN.

#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

#include "Member.h"

class Member;

class Book {
 private:
  std::string title;
  std::string author;
  int yearOFPublication;
  long int ISBN;
  std::string genre;
  std::string synopsis;

 public:
  Book();
  // virtual
  virtual void displayInfo() = 0;
  // virtual void borrow(Member* member) = 0;
  virtual void addToWaitlist(Member* member) = 0;
  virtual bool get_isAvailable() = 0;
  virtual void set_isAvailable(bool b) = 0;
  virtual std::vector<Member*> get_waitlist() = 0;
  // virtual ~Book() = 0;

  void set_title(std::string title);
  std::string get_title();
  void set_author(std::string author);
  std::string get_author();
  void set_yearOFPublication(int year);
  int get_yearOfPublication();
  void set_ISBN(long int isbn);
  long int get_ISBN();
  void set_genre(std::string genre);
  std::string get_genre();
  void set_synopsis(std::string synopsis);
  std::string get_synopsis();
};

#endif