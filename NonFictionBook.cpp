// represents a nonfiction book in the library, with attributes such as
// Availability, which determines if the book can be borrowed, and a Wait List
// of the members wanting to borrow the book.

#include "NonFictionBook.h"

#include <iostream>
#include <vector>

#include "Book.h"
#include "Borrow.h"
#include "Member.h"

NonFictionBook::NonFictionBook() {}

NonFictionBook::NonFictionBook(std::string title, std::string author,
                               int yearOfPublication, long int isbn,
                               std::string genre, std::string synopsis) {
  set_title(title);
  set_author(author);
  set_yearOFPublication(yearOfPublication);
  set_ISBN(isbn);
  set_genre(genre);
  set_synopsis(synopsis);
  isAvailable = true;  // defualts to available
  std::vector<Member*> waitlist;
}

void NonFictionBook::addToWaitlist(
    Member* member) {  // takes address of member (&member)
  // add member object to waitlist
  waitlist.push_back(member);
}

bool NonFictionBook::get_isAvailable() { return isAvailable; }

void NonFictionBook::set_isAvailable(bool b) { isAvailable = b; }

void NonFictionBook::displayInfo() {
  // print book title, author, year of publication, isbn, genre, and
  // availability Title by Author, published Year
  //      Genre/s:
  //      ISBN:
  // Book is currently AVAILABLE/UNAVAILABLE to borrow.

  std::cout << get_title() << " by " << get_author() << ", published "
            << get_yearOfPublication() << std::endl;
  std::cout << "      " << "Genre/s: " << get_genre() << std::endl;
  std::cout << "      " << "ISBN: " << get_ISBN() << std::endl;
  std::cout << "Synopsis: " << get_synopsis() << std::endl;

  if (isAvailable == true) {
    std::cout << "Book is currently AVAILABLE to borrow." << std::endl;
  } else {
    std::cout << "Book is currently UNAVAILABLE to borrow." << std::endl;
  }
}

std::vector<Member*> NonFictionBook::get_waitlist() { return waitlist; }

NonFictionBook::~NonFictionBook() { waitlist.clear(); }