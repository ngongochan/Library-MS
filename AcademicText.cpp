// represents the non-fiction books that are normally unavailable to borrow from
// the library. The user can request access and be added to the waitlist.

#include "AcademicText.h"

#include <string>
#include <vector>

#include "Member.h"
#include "NonFictionBook.h"

AcademicText::AcademicText(){};

AcademicText::AcademicText(std::string title, std::string author,
                           int yearOfPublication, long int isbn,
                           std::string genre, std::string synopsis,
                           std::string institute, int volume) {
  set_title(title);
  set_author(author);
  set_yearOFPublication(yearOfPublication);
  set_ISBN(isbn);
  set_genre(genre);
  set_synopsis(synopsis);
  set_isAvailable(false);  // unavailable
  set_academicInstitute(institute);
  set_volume(volume);
  std::vector<Member*>
      waitlist;  // can this be done here, or does it have to be via a function
                 // in the parent class? (NonFictionalBook)
}

void AcademicText::requestAccess(Member* member) {
  std::cout << "Book is currently unavailable to borrow. Do you wish to be "
               "added to the waitlist for this book?"
            << std::endl;

  int index = 0;
  std::string input;

  while (index == 0) {
    std::cout << "Please type YES or NO: ";
    std::cin >> input;

    if (input == "YES") {
      addToWaitlist(member);
      std::cout << "You have been added to the waitlist!" << std::endl;
      // how to display where in the waitlist they are?
      // "there are currently x other members waiting for this book"
      // waitlist.size() returns number of elements/members in waitlist
      std::cout << "There are currently " << get_waitlist().size()
                << " other members waiting for this book." << std::endl;
      index = 1;
    }
    if (input == "NO") {
      std::cout << "You will not be added to the waitlist. Thank you."
                << std::endl;
      index = 1;
    } else {
      std::cout << "Input not recognised. Please try again: " << std::endl;
    }
  }
}

void AcademicText::displayInfo() {
  // print book title, author, year of publication, isbn, genre, and
  // availability Title by Author, Academic Institute, published Year
  //      Genre/s:
  //      Volume:
  //      ISBN:
  // Book is currently AVAILABLE/UNAVAILABLE to borrow.

  std::cout << get_title() << " by " << get_author() << ", "
            << get_academicInstitute() << ", published "
            << get_yearOfPublication() << std::endl;
  std::cout << "      " << "Genre/s: " << get_genre() << std::endl;
  std::cout << "      " << "Volume: " << get_volume() << std::endl;
  std::cout << "      " << "ISBN: " << get_ISBN() << std::endl;
  std::cout << "Abstract: " << get_synopsis() << std::endl;
  std::cout << "This academic text is UNAVAILABLE to borrow." << std::endl;
}

void AcademicText::set_academicInstitute(std::string institute) {
  academicInstitute = institute;
}

std::string AcademicText::get_academicInstitute() { return academicInstitute; }

void AcademicText::set_volume(int volume) { this->volume = volume; }

int AcademicText::get_volume() { return volume; }

AcademicText::~AcademicText() { get_waitlist().clear(); }