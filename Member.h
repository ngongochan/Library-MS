// respresents all the members in the library system and its attributes
// How members can sign up through this application

#ifndef MEMBER_H
#define MEMBER_H

#include <memory>
#include <set>
#include <string>
#include <vector>

#include "Borrow.h"

// Forward declaration
class Borrow;
class Book;

class Member {
 private:
  std::string name;
  std::string DOB;
  std::string email;
  int ID;
  // static std::set<int> usedIDs;
  std::string homeAddress;
  std::vector<Borrow*> borrowHistory;
  bool canBorrow;

 public:
  Member();
  ~Member();
  Member(std::string name, std::string DOB, std::string email,
         std::string homeAddress);

  void print_borrowHistory();
  std::vector<Borrow*> get_borrowHistory();  // errors with vector use
  void add_borrow(Borrow* borrow);
  void set_name(std::string name);
  std::string get_name();
  void set_DOB(std::string DOB);
  std::string get_DOB();
  void set_email(std::string email);
  std::string get_email();
  void set_homeAddress(std::string homeAddress);
  std::string get_homeAddress();
  int get_ID();
  bool get_canBorrow();
  void set_canBorrow(bool canBorrow);
};

#endif