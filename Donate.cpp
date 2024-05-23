#include "Donate.h"

#include <ctime>
#include <iostream>

#include "Book.h"
#include "Transaction.h"

Donate::Donate(Book* book, int condition) {
  dateDonated = time(0);
  this->book = book;
  this->condition = condition;
}

Member* Donate::get_member() { return nullptr; }

void Donate::print() {
  std::cout << "Transaction Details\n"
            << "Date of Donation:      " << ctime(&dateDonated) << "\n\n"
            <<

      "Book to be donated     " << "\n\n"
            <<

      "Condition:             " << condition << "\n\n"
            << "Title:                 " << book->get_title() << "\n"
            << "Author:                " << book->get_author() << "\n"
            << "Year of Publication:   " << book->get_yearOfPublication()
            << "\n"
            << "ISBN:                  " << book->get_ISBN() << "\n"
            << "Genre:                 " << book->get_genre() << std::endl;
}

void Donate::set_dateDonated(std::time_t dateDonated) {
  this->dateDonated = dateDonated;
}

std::time_t Donate::get_date() { return dateDonated; }

void Donate::set_condition(int condition) { this->condition = condition; }

int Donate::get_condition() { return condition; }