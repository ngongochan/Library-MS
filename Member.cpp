#include "Member.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "Book.h"
#include "Borrow.h"

Member::Member(std::string name, std::string DOB, std::string email,
               std::string homeAddress)
    : name(name),
      DOB(DOB),
      email(email),
      homeAddress(homeAddress),
      canBorrow(true) {
  std::vector<Borrow*> borrowHistory;  // initalise this vector

  srand(static_cast<unsigned int>(time(nullptr))); //?
  ID = rand() % 9000000 + 1000000;
}

Member::~Member() {}

void Member::print_borrowHistory() {
  std::ofstream outFile("borrow_history.txt");

  if (outFile.is_open()) {
    for (size_t i = 0; i < borrowHistory.size(); ++i) {
      Borrow* borrow = borrowHistory[i];
      if (!borrow) continue;  // Skip if borrow is a nullptr

      std::time_t date = borrow->get_date();
      Book* book = borrow->get_book();
      if (!book) continue;  // Skip if book is a nullptr

      outFile << "Book title: " << book->get_title() << "\n"
              << "Author: " << book->get_author() << "\n"
              << "Year of Publication: " << book->get_yearOfPublication()
              << "\n"
              << "ISBN: " << book->get_ISBN() << "\n"
              << "Date Borrowed: " << std::ctime(&date) << std::endl;

      if (borrow->get_isOverdue()) {
        outFile << "This book is overdue. Please return it ASAP.\n"
                << std::endl;
      } else if (borrow->get_isReturned()) {
        outFile << "This book has been returned. Thank you.\n" << std::endl;
      } else {
        outFile << "This book is currently on loan. Please return promptly.\n"
                << std::endl;
      }
    }

    outFile.close();
  } else {
    std::cerr << "Unable to open file, please try again" << std::endl;
  }
}

void Member::add_borrow(Borrow* borrow) {  // error
  borrowHistory.push_back(borrow);
  // std::cout << "Borrow transaction added to Member's borrow history. \n"; //
  // debugging
}

std::vector<Borrow*> Member::get_borrowHistory() {  // error
  // std::cout << "Getting member's borrow history. \n";
  if (borrowHistory.empty()) {
    std::cout << "No borrow history available." << std::endl;
  }
  return borrowHistory;
}

void Member::set_name(std::string name) { this->name = name; }

std::string Member::get_name() {  // error
  return name;
}

void Member::set_DOB(std::string dob) { this->DOB = dob; }

std::string Member::get_DOB() {  // error
  return DOB;
}

void Member::set_email(std::string email) { this->email = email; }

std::string Member::get_email() {  // error
  return email;
}

void Member::set_homeAddress(std::string homeAddress) {
  this->homeAddress = homeAddress;
}

std::string Member::get_homeAddress() {  // error
  return homeAddress;
}

int Member::get_ID() {  // error
  return ID;
}

bool Member::get_canBorrow() {  // error
  // check through members borrow history, calling isOverdue for each borrow
  // object.
  for (long unsigned int i = 0; i < borrowHistory.size(); i++) {
    borrowHistory[i]->get_isOverdue();  // if any are overdue, isOverdue will
                                        // update member canBorrow to false
  }

  return canBorrow;
}

void Member::set_canBorrow(bool canBorrow) { this->canBorrow = canBorrow; }