// Represents a book in the library, and has attributes such as Title, Author,
// Year of Publication, and ISBN.

#include "Book.h"

#include <iostream>
#include <string>

#include "Member.h"

Book::Book(){};  // defualt constructor does nothing as this is an abstract
                 // class

// setters

void Book::set_author(std::string author) { this->author = author; }

void Book::set_genre(std::string genre) { this->genre = genre; }

void Book::set_ISBN(long int isbn) { ISBN = isbn; }

void Book::set_title(std::string title) { this->title = title; }

void Book::set_yearOFPublication(int year) { yearOFPublication = year; }

void Book::set_synopsis(std::string synopsis) { this->synopsis = synopsis; }

// getters

std::string Book::get_author() { return author; }

std::string Book::get_genre() { return genre; }

std::string Book::get_title() { return title; }

int Book::get_yearOfPublication() { return yearOFPublication; }

long int Book::get_ISBN() {
  // std::cout << "Getting isbn. \n"; // debug
  return ISBN;
}

std::string Book::get_synopsis() { return synopsis; }