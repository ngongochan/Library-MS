// represents the non-fiction books that are normally unavailable to borrow from
// the library. The user can request access and be added to the waitlist.

#ifndef ACADEMICTEXT_H
#define ACADEMICTEXT_H

#include <iostream>
#include <string>

#include "NonFictionBook.h"

class AcademicText : public NonFictionBook {
 private:
  std::string academicInstitute;
  int volume;

 public:
  AcademicText();
  AcademicText(std::string title, std::string author, int yearOfPublication,
               long int isbn, std::string genre, std::string synopsis,
               std::string institute, int volume);

  void requestAccess(Member* member);
  void set_academicInstitute(std::string institute);
  std::string get_academicInstitute();
  void set_volume(int volume);
  int get_volume();
  void displayInfo();
  ~AcademicText();
};

#endif