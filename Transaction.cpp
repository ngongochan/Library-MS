#include "Transaction.h"

#include <iostream>

#include "Book.h"

Transaction::Transaction() {
  book = nullptr;
  member = nullptr;
}

// set_book(book)
void Transaction::set_book(Book* book) { this->book = book; }

// get_book()
Book* Transaction::get_book() {
  // std::cout << "Getting books. \n";
  return book;
}