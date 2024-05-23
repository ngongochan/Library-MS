// main function

#include <iostream>

#include "Library.h"
#include "LibraryDatabaseFunctions.h"

// potenitally define functions below in seperate file i.e.
// LibraryDatabaseFunctions.cpp would make main file cleaner

int main() {
  // create library object
  // Library library;
  Library* library = new Library();
  // calls default constructor ^
  createLibraryBooks(library);

  // introduce library database and its functions to user, including accessible
  // user commands to naviagate data base this program can be used to browse and
  // access revelant information for hundreds of books.
  std::cout << "\n\n\nWelcome to the Library Database! This program can be "
               "used to browse and access relevant information for all the "
               "books in the library. \n";
  // a user can become a member of the library to borrow and return books and
  // keep track of their individual borrowing history
  std::cout
      << "Users can become members of the library and borrow books for their "
         "own use. This also allows them to access their borrow history. \n";
  // if a book is unavailable to borrow, a member can be added to the waitlist
  // for the book.
  std::cout << "This program is operated by the user using a series of "
               "commands. See these commands and their function below: \n\n";
  // "to search for a book, please type ..... "
  std::cout << "SEARCH \n";
  std::cout << "Allows user to search the library for a book by entering a "
               "keyword, such as the title, author, year of publication, ISBN, "
               "or genre of the book.\n\n";
  // "to borrow a book, type ..." "you will have to become a member to borrow a
  // book. to become a member, please .."
  std::cout << "MEMBER \n";
  std::cout << "Allows user to become a member of the library so they can "
               "borrow books.\n\n";
  std::cout << "BORROW \n";
  std::cout << "Allows user to borrow a book by from the library by entering "
               "its ISBN.\n\n";
  // "to access your borrow history and check for any overdue books, please type
  // ...."
  std::cout << "HISTORY \n";
  std::cout << "Allows user to access their own borrowing history to check "
               "their current and previous loans. User can check for overdue "
               "books here. \n\n";
  // "to return a book, please ..."
  std::cout << "RETURN \n";
  std::cout << "Allows user to return a book they've previously borrowed by "
               "entering its ISBN.\n\n";
  // "to exit program, please ..."
  std::cout << "DONATE \n";
  std::cout << "Allows user to donate a book to the library.\n\n";
  std::cout << "EXIT \n";
  std::cout << "Allows user to exit the program.\n\n";

  // i.e. create functions that run according to user input using while loop
  // with index

  std::cout << "\nLet's get started! \n";

  // ask for input
  std::string user_input;
  int n = 0;

  while (n == 0) {
    std::cout << "Enter a command to navigate the Library Database: ";
    std::cin >> user_input;

    // not use a switch statement, use IF
    if (user_input == "SEARCH") {
      search(library);
      // once search program completed, still in while loop to take next command
      continue;
    }

    else if (user_input == "MEMBER") {
      std::cin.ignore(256, '\n');
      member1(library);
      // once member program completed, still in while loop to take next command
      continue;
    }

    else if (user_input == "BORROW") {
      borrow(library);
      // once borrow program completed, still in while loop to take next command
      continue;
    }

    else if (user_input == "HISTORY") {
      history(library);
      // once history program completed, still in while loop to take next
      // command
      continue;
    }

    else if (user_input == "RETURN") {
      returnb(library);
      // once return program completed, still in while loop to take next command
      continue;
    }

    else if (user_input == "DONATE") {
      donate(library);
      continue;
    }

    else if (user_input == "EXIT") {
      std::cout << "Thank you for using the Library Database! \n";
      n = 1;  // exit while loop
      continue;
    }

    else if (user_input == "C") {
      std::cout << "SEARCH \n";
      std::cout << "Allows user to search the library for a book by entering a "
                   "keyword, such as the title, author, year of publication, "
                   "ISBN, or genre of the book.\n";
      std::cout << "\nMEMBER \n";
      std::cout << "Allows user to become a member of the library so they can "
                   "borrow books.\n";
      std::cout << "\nBORROW \n";
      std::cout << "Allows user to borrow a book by from the library by "
                   "entering its ISBN.\n";
      std::cout << "\nHISTORY \n";
      std::cout << "Allows user to access their own borrowing history to check "
                   "their current and previous loans. User can check for "
                   "overdue books here. \n";
      std::cout << "\nRETURN \n";
      std::cout << "Allows user to return a book they've previously borrowed "
                   "by entering its ISBN.\n";
      std::cout << "\nDONATE \n";
      std::cout << "Allows user to donate a book to the library.\n";
      std::cout << "\nEXIT \n";
      std::cout << "Allows user to exit the program.\n\n\n";
      continue;
    }

    else {
      std::cout << "Input not recognised. Please try again. To see the "
                   "commands available to the user, enter C: \n\n";
    }
  }

  // demonstrate abilty to access library's transaction history and member data
  // (not user initaiated, happens once user exits program)

  std::cout << "\nThe Library Database also offers additional functions that "
               "may be available to administrators of the library. \n\n";
  std::cout << "For example, a full list of all the members of the library and "
               "their personal details can be accessed. See members.txt. \n";
  library->get_members();
  std::cout << "Additionally, a full list of all of the books in the library "
               "can also be accessed. See books.txt. \n";
  library->get_books();
  std::cout << "Finally, a list of all the transactions (books "
               "borrowed/donated) can be accessed. See transactions.txt. \n";
  library->get_transactions();

  delete library;
}
