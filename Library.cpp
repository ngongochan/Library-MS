// Represents the library class and its functions, storing data about books and
// the members of the library
#include "Library.h"

#include <fstream>
#include <iostream>
#include <vector>

Library::Library() {
  std::vector<Member*> members;
  std::vector<Book*> Fbooks;
  std::vector<Book*> NFbooks;
  std::vector<Transaction*> transactions;  // initalise vectors
}

// Printing options, we have a print option for all the books, then a print
// option for member specific borrow history by matching the ID and email
void Library::get_books() {
  std::ofstream outFile("book.txt");

  outFile << "Fiction books and Restricted Books:\n"
          << std::endl;  // need to test this printing method

  for (long unsigned int i = 0; i < Fbooks.size(); i++) {
    outFile << "Title: " << Fbooks[i]->get_title() << "\n"
            << "Author: " << Fbooks[i]->get_author() << "\n"
            << "Year of Publication: " << Fbooks[i]->get_yearOfPublication()
            << "\n"
            << "ISBN: " << Fbooks[i]->get_ISBN() << "\n"
            << "Genre: " << Fbooks[i]->get_genre() << "\n"
            << std::endl;
  }

  outFile << "Non-Fiction books and Academic texts:\n" << std::endl;

  for (long unsigned int i = 0; i < NFbooks.size(); i++) {
    outFile << "Title: " << NFbooks[i]->get_title() << "\n"
            << "Author: " << NFbooks[i]->get_author() << "\n"
            << "Year of Publication: " << NFbooks[i]->get_yearOfPublication()
            << "\n"
            << "ISBN: " << NFbooks[i]->get_ISBN() << "\n"
            << "Genre: " << NFbooks[i]->get_genre() << "\n"
            << std::endl;
  }

  outFile.close();
}
void Library::get_transactions() {
  std::ofstream outFile("transactions.txt");
  outFile << "Library Transaction Details\n\n" << std::endl;

  // print ALL of the librarys transactions
  for (long unsigned int i = 0; i < transactions.size(); i++) {
    Book* book = transactions[i]->get_book();
    Member* member = nullptr;

    if (transactions[i]->get_member() != nullptr) {  // borrow transaction
      member = transactions[i]->get_member();
    }

    // if borrow
    if (member != nullptr) {
      std::time_t date = transactions[i]->get_date();

      outFile << "Date Borrowed:          " << ctime(&date) <<

          "Book Details:" << "\n"
              <<

          "Title:                 " << book->get_title() << "\n"
              << "Author:                " << book->get_author() << "\n"
              << "Year of Publication:   " << book->get_yearOfPublication()
              << "\n"
              << "ISBN:                  " << book->get_ISBN() << "\n"
              <<

          "Member Details:" << "\n\n"
              <<

          "Member:                " << member->get_name() << "\n"
              << "Email Address:         " << member->get_email() << "\n"
              << "Member ID:             " << member->get_ID() << "\n"
              << std::endl;
    }

    // if donate
    if (member == nullptr) {
      std::time_t date = transactions[i]->get_date();

      outFile <<

          "Date of donation:      " << ctime(&date) << ""
              << "Book details:" << "\n"
              <<

          "Title:                 " << book->get_title() << "\n"
              << "Author:                " << book->get_author() << "\n"
              << "Year of Publication:   " << book->get_yearOfPublication()
              << "\n"
              << "ISBN:                  " << book->get_ISBN() << "\n"
              << std::endl;
    }
  }

  outFile.close();
}
void Library::get_members() {
  std::ofstream outFile("members.txt");

  // print all members and their details

  for (long unsigned int i = 0; i < members.size(); i++) {
    outFile << "Member Details\n"
            << "Member:                " << members[i]->get_name() << "\n"
            << "Email Address:         " << members[i]->get_email() << "\n"
            << "Member ID:             " << members[i]->get_ID()
            << "\n"
               "Date of Birth:         "
            << members[i]->get_DOB()
            << "\n"
               "Home Address:          "
            << members[i]->get_homeAddress() << std::endl;
  }

  outFile.close();
}

// get books
std::vector<Book*> Library::get_Fbooks() { return Fbooks; }

std::vector<Book*> Library::get_NFbooks() { return NFbooks; }

Member* Library::checkMember(std::string email, int ID) {
  for (auto& member : members) {
    if (member->get_email() == email && member->get_ID() == ID) {
      return member;
    }
  }
  return nullptr;
}
Book* Library::checkBook(long int isbn) {
  // for (auto &book : Fbooks) {
  //     if (book->get_ISBN() == isbn) {
  //         return book;
  //     }
  // }
  // for (auto &book : NFbooks) {
  //     if (book->get_ISBN() == isbn) {
  //         return book;
  //     }
  // }

  for (long unsigned int i = 0; i < Fbooks.size(); i++) {
    // std::cout << Fbooks[i]->get_ISBN() << std::endl;

    if (Fbooks[i]->get_ISBN() == isbn) {
      return Fbooks[i];
    }
  }
  for (long unsigned int i = 0; i < NFbooks.size(); i++) {
    // std::cout << NFbooks[i]->get_ISBN() << std::endl;

    if (NFbooks[i]->get_ISBN() == isbn) {
      return NFbooks[i];
    }
  }

  return nullptr;
}

// Adding stuff to the library
void Library::addFBook(Book* book) { Fbooks.push_back(book); }
void Library::addNFBook(Book* book) { NFbooks.push_back(book); }
void Library::addMember(Member* member) { members.push_back(member); }
void Library::addTransaction(Transaction* transaction) {
  transactions.push_back(transaction);
}

Library::~Library() {
  members.clear();
  Fbooks.clear();
  NFbooks.clear();
  transactions.clear();
}