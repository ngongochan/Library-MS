#ifndef LIBRARY_H
#define LIBRARY_H

#include <memory>
#include <vector>

#include "Book.h"
#include "Member.h"
#include "Transaction.h"

// forward declaration
class Member;
class Book;
class Transaction;

class Library {
 private:
  std::vector<Member*> members;
  std::vector<Book*> Fbooks;
  std::vector<Book*> NFbooks;
  std::vector<Transaction*> transactions;

 public:
  Library();

  void addFBook(Book* book);
  void addNFBook(Book* book);
  void addMember(Member* member);
  void addTransaction(Transaction* transaction);
  void get_books();
  void get_members();
  void get_transactions();
  // get Fbook NFBookw
  std::vector<Book*> get_Fbooks();
  std::vector<Book*> get_NFbooks();

  Member* checkMember(const std::string email, int ID);
  Book* checkBook(long int isbn);
  ~Library();
};

#endif