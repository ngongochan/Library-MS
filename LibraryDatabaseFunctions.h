#ifndef LIBRARYDATABASEFUNCTIONS_H
#define LIBRARYDATABASEFUNCTIONS_H

#include <bits/stdc++.h>

#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "AcademicText.h"
#include "Book.h"
#include "Borrow.h"
#include "Donate.h"
#include "FictionBook.h"
#include "Library.h"
#include "Member.h"
#include "NonFictionBook.h"
#include "RestrictedBook.h"

// function to create book objects from a file (happens automatically, not user
// initiated)
void createLibraryBooks(Library* library) {
  std::ifstream bookFile;

  // fiction books first

  bookFile.open("FictionBooks.txt");  // open file
  if (bookFile.fail()) {
    std::cout << "Failed to open file. " << std::endl;  // test if opened
    return;
  }

  std::string line;
  // int k = 0;

  while (getline(bookFile, line)) {  // while NOT at end of file

    std::string title, author, genre, year, isbn, synopsis;

    getline(bookFile, title, ';');
    getline(bookFile, author, ';');
    getline(bookFile, year, ';');
    getline(bookFile, isbn, ';');
    getline(bookFile, genre, ';');  // read to ; character
    getline(bookFile, synopsis, ';');

    // std::cout << title << "\n" << author << "\n" << year << "\n" << isbn <<
    // "\n" << genre << "\n" << synopsis << std::endl; //test
    try {
      int year1 = std::stoi(year);        // convert to int
      long int isbn1 = std::stoul(isbn);  // convert to long int

      // create book object
      Book* b = new FictionBook(title, author, year1, isbn1, genre, synopsis);

      // add to library
      library->addFBook(b);
      // std::cout << "F Book added to library successfully! \n";
      // library->get_Fbooks()[k]->displayInfo();
      // k++;

    }

    catch (const std::invalid_argument& e) {
      // std::cerr << "Invalid argument: " << e.what() << " in " << title <<
      // std::endl;
    } catch (...) {
      // Catch any other exceptions that might occur
      // std::cerr << "An unknown error occurred." << " in " << title <<
      // std::endl;
    }
  }

  bookFile.close();

  // nonfiction books next

  bookFile.open("NonFictionBooks.txt");  // open file
  if (bookFile.fail()) {
    std::cout << "Failed to open file. " << std::endl;  // test if opened
    return;
  }

  while (getline(bookFile, line)) {  // while NOT at end of file

    std::string title, author, genre, year, isbn, synopsis;

    getline(bookFile, title, ';');
    getline(bookFile, author, ';');
    getline(bookFile, year, ';');
    getline(bookFile, isbn, ';');
    getline(bookFile, genre, ';');  // read to ; character
    getline(bookFile, synopsis, ';');

    // std::cout << title << "\n" << author << "\n" << year << "\n" << isbn <<
    // "\n" << genre << "\n" << synopsis << std::endl; //test

    try {
      int year1 = std::stoi(year);        // convert to int
      long int isbn1 = std::stoul(isbn);  // convert to long int

      // create book object
      Book* b =
          new NonFictionBook(title, author, year1, isbn1, genre, synopsis);

      // add to library
      library->addNFBook(b);
      // std::cout << "NF Book added to library successfully! \n";
    }

    catch (const std::invalid_argument& e) {
      // std::cerr << "Invalid argument: " << e.what() << " in " << title <<
      // std::endl;
    } catch (...) {
      // Catch any other exceptions that might occur
      // std::cerr << "An unknown error occurred." << " in " << title <<
      // std::endl;
    }
  }

  bookFile.close();

  // restricted books

  bookFile.open("RestrictedBooks.txt");  // open file
  if (bookFile.fail()) {
    std::cout << "Failed to open file. " << std::endl;  // test if opened
    return;
  }

  while (getline(bookFile, line)) {  // while NOT at end of file

    std::string title, author, genre, year, isbn, synopsis;

    getline(bookFile, title, ';');
    getline(bookFile, author, ';');
    getline(bookFile, year, ';');
    getline(bookFile, isbn, ';');
    getline(bookFile, genre, ';');  // read to ; character
    getline(bookFile, synopsis, ';');

    // std::cout << title << "\n" << author << "\n" << year << "\n" << isbn <<
    // "\n" << genre << "\n" << synopsis << std::endl; //test

    try {
      int year1 = std::stoi(year);        // convert to int
      long int isbn1 = std::stoul(isbn);  // convert to long int

      // create book object
      Book* b =
          new RestrictedBook(title, author, year1, isbn1, genre, synopsis);

      // add to library
      library->addFBook(b);
      // std::cout << "RF Book added to library FBooks successfully! \n";
    }

    catch (const std::invalid_argument& e) {
      // std::cerr << "Invalid argument: " << e.what() << " in " << title <<
      // std::endl;
    } catch (...) {
      // Catch any other exceptions that might occur
      // std::cerr << "An unknown error occurred." << " in " << title <<
      // std::endl;
    }
  }

  bookFile.close();

  // academic texts

  bookFile.open("AcademicTexts.txt");  // open file
  if (bookFile.fail()) {
    std::cout << "Failed to open file. " << std::endl;  // test if opened
    return;
  }

  while (getline(bookFile, line)) {  // while NOT at end of file

    std::string title, author, genre, year, isbn, institute, volume, synopsis;

    getline(bookFile, title, ';');
    getline(bookFile, author, ';');
    getline(bookFile, year, ';');
    getline(bookFile, isbn, ';');
    getline(bookFile, genre, ';');
    getline(bookFile, synopsis, ';');
    getline(bookFile, institute, ';');
    getline(bookFile, volume, ';');

    // std::cout << title << "\n" << author << "\n" << institute << "\n" << year
    // << "\n"<< volume << "\n" << synopsis << "\n" << isbn << "\n" << genre <<
    // std::endl; //test

    try {
      int year1 = std::stoi(year);        // convert to int
      long int isbn1 = std::stoul(isbn);  // convert to long int
      int volume1 = std::stoi(volume);

      // create book object
      Book* b = new AcademicText(title, author, year1, isbn1, genre, synopsis,
                                 institute, volume1);

      // add to library
      library->addNFBook(b);
      // std::cout << "AT NF Book added to library NFBooks successfully! \n";

    } catch (const std::invalid_argument& e) {
      // std::cerr << "Invalid argument: " << e.what() << " in " << title <<
      // std::endl;
    } catch (...) {
      // Catch any other exceptions that might occur
      // std::cerr << "An unknown error occurred." << " in " << title <<
      // std::endl;
    }
  }

  bookFile.close();
}

// function to search for multiple books and print info (user types SEARCH)
void search(Library* library) {
  // function is called when user types SEARCH
  //  does user want to search for fiction or nonfiction books?
  std::cout << "Type F to search for fiction books, or NF to search for "
               "nonfiction books and academic texts: "
            << std::endl;
  // take in user input
  std::string input;
  int n = 0;
  // while loop to ensure valid input
  while (n == 0) {
    std::cin >> input;
    std::cin.ignore(256, '\n');
    std::string search_term;
    // verify correct input
    if (input == "F") {
      n = 1;  // correct input
      std::cout << "You can search for books by entering either a title, "
                   "author, year of publication, ISBN, or genre!\n"
                << "Take note of the ISBN of any book you wish to borrow. \n"
                << "Type X to exit the search program. \n\n";
      while (n == 1) {
        std::cout << "Please enter your search term, or X to exit the search "
                     "function: \n";
        getline(std::cin, search_term);
        std::cout << "\n";
        // std::cout << search_term << std::endl;
        // std::cin >> search_term;
        // std::cout << search_term;
        if (search_term == "X") {
          search_term = "";
          std::cout << "Returning to Main Library Database. \n";
          return;  // exit program for user input of X
        }
        // fiction books in library is library->FBooks[i]
        // access atrributes as such library->FBooks[i]->get_title()

        bool one_book_found = false;
        bool book_found = false;

        for (long unsigned int i = 0; i < (library->get_Fbooks()).size();
             i++) {  // goes to end of vector of books

          book_found = false;
          // check titles. if there's a match, display info // if
          // library->FBooks[i]->title == input && n = 1 // if yes, change n
          // value
          if ((library->get_Fbooks()[i]->get_title() == search_term) &&
              (book_found == false)) {
            (library->get_Fbooks()[i])->displayInfo();
            std::cout << "\n";
            one_book_found = true;
            book_found = true;
          }
          // check author. if there's a match, display info
          if ((library->get_Fbooks()[i]->get_author() == search_term) &&
              (book_found == false)) {
            library->get_Fbooks()[i]->displayInfo();
            std::cout << "\n";
            one_book_found = true;
            book_found = true;
          }
          // check year. if there's a match, display info
          try {
            if ((library->get_Fbooks()[i]->get_yearOfPublication() ==
                 std::stoi(search_term)) &&
                (book_found == false)) {
              library->get_Fbooks()[i]->displayInfo();
              std::cout << "\n";
              one_book_found = true;
              book_found = true;
            }
            // check isbn. if there's a match, display info
            if ((library->get_Fbooks()[i]->get_ISBN() ==
                 std::stol(search_term)) &&
                (book_found == false)) {
              library->get_Fbooks()[i]->displayInfo();
              std::cout << "\n";
              one_book_found = true;
              book_found = true;
            }
          } catch (const std::invalid_argument& e) {
          } catch (...) {
          }

          // check genre. if there's a match, display info
          if ((library->get_Fbooks()[i]->get_genre() == search_term) &&
              (book_found == false)) {
            library->get_Fbooks()[i]->displayInfo();
            std::cout << "\n";
            one_book_found = true;
            book_found = true;
          }
        }

        if (one_book_found == false) {
          std::cout << "No book matching that search term was found. \n";
        }
      }
    }

    if (input == "NF") {
      n = 1;  // correct input
      std::cout << "You can search for books by entering either a title, "
                   "author, year of publication, ISBN, or genre!\n"
                << "Take note of the ISBN of any book you wish to borrow. \n"
                << "Type X to exit the search program. \n\n";
      while (n == 1) {
        std::cout << "Please enter your search term: \n";
        getline(std::cin, search_term);
        // std::cout << search_term << std::endl;
        //  std::cin >> search_term;
        //  std::cout << search_term;
        if (search_term == "X") {
          search_term = "";
          std::cout << "Returning to Main Library Database. \n";
          return;  // exit program for user input of X
        }
        // fiction books in library is library->FBooks[i]
        // access atrributes as such library->FBooks[i]->get_title()

        bool one_book_found = false;
        bool book_found = false;

        for (long unsigned int i = 0; i < (library->get_NFbooks()).size();
             i++) {  // goes to end of vector of books

          book_found = false;
          // check titles. if there's a match, display info // if
          // library->FBooks[i]->title == input && n = 1 // if yes, change n
          // value
          if ((library->get_NFbooks()[i]->get_title() == search_term) &&
              (book_found == false)) {
            (library->get_NFbooks()[i])->displayInfo();
            std::cout << "\n";
            one_book_found = true;
            book_found = true;
          }
          // check author. if there's a match, display info
          if ((library->get_NFbooks()[i]->get_author() == search_term) &&
              (book_found == false)) {
            library->get_NFbooks()[i]->displayInfo();
            std::cout << "\n";
            one_book_found = true;
            book_found = true;
          }
          // check year. if there's a match, display info
          try {
            if ((library->get_NFbooks()[i]->get_yearOfPublication() ==
                 std::stoi(search_term)) &&
                (book_found == false)) {
              library->get_NFbooks()[i]->displayInfo();
              std::cout << "\n";
              one_book_found = true;
              book_found = true;
            }
            // check isbn. if there's a match, display info
            if ((library->get_NFbooks()[i]->get_ISBN() ==
                 std::stol(search_term)) &&
                (book_found == false)) {
              library->get_NFbooks()[i]->displayInfo();
              std::cout << "\n";
              one_book_found = true;
              book_found = true;
            }
          } catch (const std::invalid_argument& e) {
          } catch (...) {
          }

          // check genre. if there's a match, display info
          if ((library->get_NFbooks()[i]->get_genre() == search_term) &&
              (book_found == false)) {
            library->get_NFbooks()[i]->displayInfo();
            std::cout << "\n";
            one_book_found = true;
            book_found = true;
          }
        }

        if (one_book_found == false) {
          std::cout << "No book matching that search term was found. \n";
        }
      }

    }

    else {
      std::cout
          << "Input not recognised. Please ensure you enter either F (for "
             "fiction) or NF (for nonfiction) to search for books. \n";
      std::cout << "Please try again: \n";
    }
  }
}

// function to allow user to become a member (user types MEMBER)
void member1(Library* library) {
  // prompt user to input info to become member
  std::cout << "\n";
  std::cout << "To become a member, some personal information is required. \n";
  std::string name, DOB, email, home;
  std::cout << "Please enter your full name: ";  // can we prevent people from
                                                 // enetering numbers/symbols?
  getline(std::cin, name);
  std::cout << "Please enter your date of birth: ";
  getline(std::cin, DOB);
  std::cout << "Please enter your email: ";
  getline(std::cin, email);
  std::cout << "Finally, please enter your home address: ";
  getline(std::cin, home);
  // create member object
  Member* m = new Member(name, DOB, email, home);
  // add member* to Library
  library->addMember(m);
  // "Your member ID is .... " "You will need this to borrow books"
  std::cout << "\nCongratulations on becoming a member of the library! Your "
               "unique member ID is: "
            << m->get_ID() << "\n";
  std::cout << "In future, you will be required to provide your email and "
               "member ID to log into your account.\n\n";
}

// function that allows user to borrow books (user types BORROW)
void borrow(Library* library) {
  while (true) {
    // Get user email and ID
    std::string email;
    std::string id1;
    std::cout << "Please enter your member email: ";
    std::cin >> email;

    std::cout << "Please enter your member ID: ";
    std::cin >> id1;
    int id;
    try {
      id = std::stoi(id1);
    } catch (...) {
      std::cout << "Invalid form of ID. Please enter a numerical value with "
                   "less than 9 digits. \n";
      std::cin >> id;
    }

    Member* member = library->checkMember(email, id);
    if (member == nullptr) {
      std::cout
          << "No member found with that email and ID. You either mistyped your "
             "information or you haven't become a member of the library yet.\n";
      std::string input;
      while (true) {
        std::cout << "Type A to enter your information again or type X to "
                     "become a member: ";
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');  // Clear input buffer
        if (input == "A") {
          break;  // Restart outer loop
        } else if (input == "X") {
          member1(library);  // Call member function to register new member
          return;            // Exit borrow function after member registration
        } else {
          std::cout << "Input not recognized, please try again.\n";
        }
      }
    } else {
      // Member found, proceed to book borrowing
      int n = 1;
      while (n == 1) {
        std::string num;
        std::cout << "Please enter the ISBN of the book you wish to borrow: ";
        std::cin >> num;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n');  // Clear input buffer

        long int isbn;
        try {
          isbn = std::stol(num);
        } catch (const std::invalid_argument&) {
          std::cout << "Invalid ISBN format. Please try again.\n";
          continue;  // Prompt for ISBN again
        }

        Book* book = library->checkBook(isbn);
        if (book == nullptr) {
          std::cout << "No book with that ISBN exists in this library.\n";
          std::string input;
          while (true) {
            std::cout
                << "Type A to re-enter the ISBN or X to search for a book: ";
            std::cin >> input;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                            '\n');  // Clear input buffer
            if (input == "A") {
              break;  // Restart ISBN input loop
            } else if (input == "X") {
              search(library);  // Call search function
              return;           // Exit borrow function after search
            } else {
              std::cout << "Input not recognized, please try again.\n";
            }
          }
        } else {
          // Book found, confirm borrowing
          std::string input;
          int k = 1;
          while (k == 1) {
            std::cout << "\nDo you wish to borrow: " << book->get_title()
                      << " by " << book->get_author() << "?\n";
            std::cout << "Type Y to borrow, N to type a different ISBN, or X "
                         "to exit borrow program: ";
            std::cin >> input;
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
            // '\n'); // Clear input buffer

            if (input == "Y") {
              // std::cout << "Debug: Entered 'Y' condition.\n"; // Debugging
              // output: enters y condition successfully

              bool isAvailable = book->get_isAvailable();
              bool canBorrow = member->get_canBorrow();

              if (isAvailable && canBorrow) {
                Borrow* b1 = new Borrow(book, member);
                member->add_borrow(b1);
                Transaction* b2 = new Borrow(book, member);

                library->addTransaction(b2);
                book->set_isAvailable(false);
                std::cout << "\nBook has been borrowed! You can keep this book "
                             "for 30 days: after this time has elapsed the "
                             "book is considered overdue.\n";
              } else if (!(member->get_canBorrow())) {
                // std::cout << "Entered cond.2. \n"; // debugging
                std::cout
                    << "You cannot borrow books due to an outstanding overdue "
                       "book. Please return the overdue book first.\n";
                return;  // Exit borrow function
              } else {
                // std::cout << "Entered cond.3. \n"; //debugging
                std::cout
                    << "Book is currently unavailable to borrow. Do you wish "
                       "to be added to the waitlist for this book?\n";
                while (true) {
                  std::cout << "Please type YES or NO: ";
                  std::cin >> input;
                  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                  '\n');  // Clear input buffer
                  if (input == "YES") {
                    book->addToWaitlist(member);
                    std::cout << "You have been added to the waitlist. There "
                                 "are currently "
                              << book->get_waitlist().size()
                              << " other members waiting for this book.\n";
                    break;
                  } else if (input == "NO") {
                    std::cout << "You will not be added to the waitlist. Thank "
                                 "you.\n";
                    break;
                  } else {
                    std::cout << "Input not recognized. Please try again.\n";
                  }
                }
              }

              // std::cout << "moved past if/else conditions.\n"; //debugging

              while (true) {
                std::cout << "Do you wish to borrow a different book? Type Y "
                             "for yes, N for no: ";
                std::cin >> input;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');  // Clear input buffer
                if (input == "Y") {
                  k = 0;
                  n = 1;
                  break;  // Restart ISBN input loop
                } else if (input == "N") {
                  std::cout << "Exiting borrow program now.\n\n";
                  return;  // Exit borrow function
                } else {
                  std::cout << "Input not recognized, please try again.\n";
                }
              }

            } else if (input == "N") {
              break;  // Restart ISBN input loop
            } else if (input == "X") {
              std::cout << "Exiting borrow program now.\n";
              return;  // Exit borrow function
            } else {
              std::cout << "Input not recognized, please try again.\n";
            }
          }
        }
      }
    }
  }
}

// function allowing user to return books (user types RETURN)
void returnb(Library* library) {
  // Function to handle the book return process for a library member

  std::string email;
  int id;

  while (true) {
    // Prompt for member email and ID
    std::cout << "\nPlease enter your member email: ";
    std::cin >> email;
    std::cout << "Please enter your member ID: ";
    std::cin >> id;

    // Check if the member exists
    Member* member = library->checkMember(email, id);
    if (member == nullptr) {
      std::cout
          << "\nNo member found with that email and ID. You either mistyped "
             "your "
          << "information or you haven't become a member of the library yet.\n";

      while (true) {
        std::cout << "Type A to enter your information again or type X to "
                     "become a member: ";
        std::string input;
        std::cin >> input;

        if (input == "A") {
          break;  // Retry the outer loop
        } else if (input == "X") {
          member1(library);  // Call function to become a member
          return;
        } else {
          std::cout << "Input not recognized, please try again.\n";
        }
      }
    } else {
      bool cond1 = true;
      while (cond1) {
        // Prompt for the ISBN of the book to return
        std::cout << "\nPlease enter the ISBN of the book you wish to return: ";
        long int isbn;
        std::cin >> isbn;

        // Check if the book exists in the member's borrow history
        bool found = false;
        int index = -1;
        std::vector<Borrow*> borrowHistory = member->get_borrowHistory();

        for (size_t i = 0; i < borrowHistory.size(); ++i) {
          if (borrowHistory[i]->get_book()->get_ISBN() == isbn) {
            found = true;
            index = i;
            break;
          }
        }

        if (!found) {
          std::cout << "\nNo book with that ISBN exists in this member's "
                       "borrowing history.\n";
          while (true) {
            std::cout
                << "Type A to re-enter the ISBN or X to exit return program: ";
            std::string input;
            std::cin >> input;

            if (input == "A") {
              break;  // Retry the ISBN input loop
            } else if (input == "X") {
              std::cout << "\nExiting return program. \n";
              return;
            } else {
              std::cout << "Input not recognized, please try again.\n";
            }
          }
        } else {
          // Confirm book return
          Book* book = borrowHistory[index]->get_book();
          bool cond2 = true;
          while (cond2) {
            std::cout << "\nDo you wish to return: " << book->get_title()
                      << " by " << book->get_author() << "?\n";
            std::cout << "Type Y to return or X to exit return program: ";
            std::string input;
            std::cin >> input;

            if (input == "Y") {
              borrowHistory[index]->set_isReturned(true);
              book->set_isAvailable(true);
              std::cout << "\nBook has been returned! Thank you.\n";

              while (true) {
                std::cout << "\nDo you wish to return another book? Enter Y "
                             "for yes, N for no: ";
                std::string input2;
                std::cin >> input2;

                if (input2 == "Y") {
                  cond2 = false;
                  cond1 = true;
                  break;  // Retry the ISBN input loop
                } else if (input2 == "N") {
                  std::cout << "\nExiting return program now.\n";
                  return;
                } else {
                  std::cout << "Input not recognized, please try again.\n";
                }
              }
            } else if (input == "X") {
              std::cout << "Exiting return program now.\n";
              return;
            } else {
              std::cout << "Input not recognized, please try again.\n";
            }
          }
        }
      }
    }
  }
}

// function allowing user to access borrow history, get file (user types
// HISTORY)
void history(Library* library) {
  // check user is member by email and id
  // use command member->print_borrowHistory()

  // user inputs member email and id, verify they are a member
  std::string email;
  int id;
  int n = 0;
  while (n == 0) {
    std::cout << "Please enter your member email: ";
    std::cin >> email;
    std::cout << "Please enter your member ID: ";
    std::cin >> id;
    // check library for user with email and ID using checkMember(email, id).
    // returns pointer to Member if found, zero otherwise
    Member* member = library->checkMember(email, id);
    if (member == nullptr) {
      std::cout
          << "No member found with that email and ID. You either mistyped your "
             "information or you haven't become a member of the library yet.";
      // Type A to try again or X to exit borrow program and become member: "
      std::string input;
      int k = 0;
      while (k == 0) {
        std::cout << "Type A to enter your information again or type X to "
                     "become a member: ";
        std::cin >> input;
        if (input == "A") {
          k = 1;  // correct input
                  // in while loop, n = 0 still
        }
        if (input == "X") {
          k = 1;             // correct input
          member1(library);  // call member function
        } else {
          std::cout << "Input not recognised, please try again. \n";
        }
      }
    }

    else {
      n = 1;  // correct input
      // std::cout << "Debug: Member found with email: " << email << " and ID: "
      // << id << "\n";
      try {
        member->print_borrowHistory();
      } catch (const std::exception& e) {
        std::cerr << "Exception occurred while printing borrow history: "
                  << e.what() << '\n';
      }
      std::cout << "Borrow history file has been generated. \n\n";
      return;
    }
  }
}

// function allowing user to 'donate' a book (user types DONATE)
void donate(Library* library) {
  // get book info, create book object
  int n = 0;
  while (n == 0) {
    std::cout << "Please indicate if the book to be donated is fiction or "
                 "nonfiction. Type F for fiction, NF for nonfiction: \n";
    std::string ficNonFic;
    std::cin >> ficNonFic;

    if (ficNonFic == "F") {
      n = 1;  // correct input
      std::cout << "Please enter the following information about the book as "
                   "detailed below: \n";
      std::string title;
      std::string author;
      int year;
      long int isbn;
      std::string genre;
      std::string synopsis = "No synopsis is available for this book.";
      std::cout << "Title: ";
      std::cin.ignore(256, '\n');
      std::getline(std::cin, title);
      std::cout << "Author: ";
      std::cin.ignore(256, '\n');
      std::getline(std::cin, author);
      std::cout << "Year published: ";
      std::cin >> year;
      std::cout << "ISBN of book: ";
      std::cin >> isbn;
      std::cin.ignore(256, '\n');
      std::cout << "Book's genre: ";
      std::getline(std::cin, genre);
      Book* b = new FictionBook(title, author, year, isbn, genre,
                                synopsis);  // create book
      library->addFBook(b);                 // added to library

      int condition;
      int w = 0;
      while (w == 0) {
        std::cout << "The condition of the book, on a scale from 1 (poor "
                     "condition) to 5 (brand new): ";
        std::cin >> condition;
        if ((condition < 1) || (condition > 5)) {
          std::cout << condition
                    << " is not an accepted value for the condition of a book. "
                       "Please enter a number from 1 to 5: ";
        } else {
          w = 1;  // correct input
          // create donate object
          Transaction* donated =
              new Donate(b, condition);  // create donation transaction
          library->addTransaction(
              donated);  // added to library transaction history
          std::cout << "Thanks for donating! Exiting donate program now. \n\n";
          return;
        }
      }
    }

    if (ficNonFic == "NF") {
      n = 1;  // correct input
      std::cout << "Please enter the following information about the book as "
                   "detailed below: \n";
      std::string title;
      std::string author;
      int year;
      long int isbn;
      std::string genre;
      std::string synopsis = "No synopsis is available for this book.";
      std::cout << "Title: ";
      std::cin >> title;
      std::cout << "Author: ";
      std::cin >> author;
      std::cout << "Year published: ";
      std::cin >> year;
      std::cout << "ISBN of book: ";
      std::cin >> isbn;
      std::cout << "Book's genre: ";
      std::cin >> genre;
      Book* b = new NonFictionBook(title, author, year, isbn, genre,
                                   synopsis);  // create book
      library->addNFBook(b);                   // added to library

      int condition;
      int w = 0;
      while (w == 0) {
        std::cout << "The condition of the book, on a scale from 1 (poor "
                     "condition) to 5 (brand new): ";
        std::cin >> condition;
        if ((condition < 1) || (condition > 5)) {
          std::cout << condition
                    << " is not an accepted value for the condition of a book. "
                       "Please enter a number from 1 to 5: ";
        } else {
          w = 1;  // correct input
          // create donate object
          Transaction* donated =
              new Donate(b, condition);  // create donation transaction
          library->addTransaction(
              donated);  // added to library transaction history
          std::cout << "Thanks for donating! Exiting donate program now. \n\n";
          return;
        }
      }
    }

    else {
      std::cout << "Input not recognised, please try again. \n";
      // in while loop still
    }
  }

  // get book condition, create donate object
  // add book to library
  // add donate transaction to library
}

#endif