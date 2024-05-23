#include <fstream>
#include <iostream>
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
#include "Transaction.h"

class UnitTest {
 public:
  void runTests() {
    testRequestAccess();
    testGetBooks();
    testBorrowFunctionality();
    testDonateFunctionality();
    testFictionBookFunctionality();
    testNonFictionBookFunctionality();
    testRestrictedBookFunctionality();
    testLibraryFunctionality();
    testMemberFunctionality();
    testTransactionFunctionality();
  }

 private:
  void testRequestAccess() {
    std::cout << "request access test: " << std::endl;
    AcademicText book("An Introduction to Sociolinguistics", "Ronald Wardhaugh",
                      2015, 9781118732292, "Linguistics",
                      "This book introduces the field of sociolinguistics.",
                      "Wiley-Blackwell", 6);
    Member member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    book.requestAccess(&member);
    if (book.get_waitlist().size() != 1) {
      std::cout << "requesting access test failed" << std::endl;
    } else {
      std::cout << "requesting access test passed" << std::endl;
    }
  }

  void testGetBooks() {
    std::cout << "getting book test: " << std::endl;
    Library library;
    Book* fictionBook = new FictionBook(
        "The Great Gatsby", "F. Scott Fitzgerald", 2002, 9798351145013,
        "Classic",
        "Jay Gatsby, a mysterious millionaire, throws lavish parties in hopes "
        "of winning back his lost love, Daisy Buchanan.");
    Book* nonFictionBook = new NonFictionBook(
        "Educated", "Tara Westover", 2018, 9780399590504, "Memoir",
        "Tara Westover recounts her journey from growing up in a strict and "
        "isolated Idaho family to pursuing education against all odds");
    library.addFBook(fictionBook);
    library.addNFBook(nonFictionBook);
    library.get_books();

    std::string expectedContent =
        "fiction books and restricted books:\n\n"
        "title: The Great Gatsby\n"
        "author: F. Scott Fitzgerald\n"
        "year of Publication: 2002\n"
        "ISBN: 9798351145013\n"
        "genre: Classic\n\n"
        "non-fiction books and academic texts:\n\n"
        "title: Educated\n"
        "author: Tara Westover\n"
        "year of Publication: 2018\n"
        "ISBN: 9780399590504\n"
        "genre: Memoir\n\n";

    std::ifstream inFile("book.txt");
    std::string actualContent((std::istreambuf_iterator<char>(inFile)),
                              std::istreambuf_iterator<char>());
    if (expectedContent != actualContent) {
      std::cout << "getting book test failed" << std::endl;
    } else {
      std::cout << "getting book test passed" << std::endl;
    }
    std::remove("book.txt");
    delete fictionBook;
    delete nonFictionBook;
  }

  void testBorrowFunctionality() {
    std::cout << "borrow test: " << std::endl;
    Book* book = new FictionBook(
        "Guns, Germs, and Steel", "Jared Diamond", 1997, 9780393317558,
        "History",
        "Diamond examines the factors that contributed to the unequal "
        "distribution of wealth and power among societies");
    Member* member =
        new Member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    Borrow borrow(book, member);
    std::time_t fakeBorrowDate =
        std::time(0) - (5 * 60);  // 5 mins testing period
    borrow.set_dateBorrowed(fakeBorrowDate);
    if (!borrow.get_isOverdue()) {
      std::cout << "borrow test passed" << std::endl;
    } else {
      std::cout << "borrow test failed" << std::endl;
    }

    borrow.set_isReturned(true);
    if (borrow.get_isOverdue()) {
      std::cout << "borrow return failed" << std::endl;
    } else {
      std::cout << "borrow return passed" << std::endl;
    }
    delete book;
    delete member;
  }

  void testDonateFunctionality() {
    std::cout << "donation test: " << std::endl;
    Book* book = new NonFictionBook("random donation book", "gray", 2024,
                                    4775353224, "fantasy", "random summary");
    Donate donate(book, 8);
    std::time_t fakeDonationDate =
        std::time(0) - (1 * 60);  // 1 min testing period
    donate.set_dateDonated(fakeDonationDate);
    if (donate.get_date() != fakeDonationDate) {
      std::cout << "donation test failed" << std::endl;
    } else {
      std::cout << "donation test passed" << std::endl;
    }

    if (donate.get_condition() != 8) {
      std::cout << "donation condition test failed" << std::endl;
    } else {
      std::cout << "donation condition test passed" << std::endl;
    }
    delete book;
  }

  void testFictionBookFunctionality() {
    std::cout << "fiction book test: " << std::endl;
    FictionBook book(
        "The Da Vinci Code", "Dan Brown", 2003, 0307277674, "Mystery",
        "Harvard symbologist Robert Langdon and cryptologist Sophie Neveu "
        "uncover a conspiracy involving religious symbolism");
    Member member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    if (!book.get_isAvailable()) {
      std::cout << "fiction book availability failed" << std::endl;
    } else {
      std::cout << "fiction book availability passed" << std::endl;
    }
    book.addToWaitlist(&member);

    if (book.get_waitlist().size() != 1 ||
        book.get_waitlist().at(0) != &member) {
      std::cout << "fiction book waitlist test failed" << std::endl;
    } else {
      std::cout << "fiction book waitlist test passed" << std::endl;
    }
    std::cout << "displaying info:" << std::endl;
    book.displayInfo();
    book.set_isAvailable(false);
    if (book.get_isAvailable()) {
      std::cout << "fiction book availability test failed" << std::endl;
    } else {
      std::cout << "fiction book availability test passed" << std::endl;
    }
  }

  void testNonFictionBookFunctionality() {
    std::cout << "non-fiction book test: " << std::endl;
    NonFictionBook book(
        "Bad Blood", "John Carreyrou", 2018, 9781524731656, "Business",
        "Business;Carreyrou exposes the rise and fall of Theranos, a "
        "healthcare technology company founded by Elizabeth Holmes");
    Member member1("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    Member member2("Brad", "1987-12-12", "brad@gmail.com", "18 Desmond");
    std::cout << "adding members to the waitlist: " << std::endl;
    book.addToWaitlist(&member1);
    book.addToWaitlist(&member2);
    if (book.get_waitlist().size() != 2) {
      std::cout << "adding to waitlist test failed" << std::endl;
    } else {
      std::cout << "adding to waitlist test passed" << std::endl;
    }
    std::cout << "displaying info: " << std::endl;
    book.displayInfo();

    if (!book.get_isAvailable()) {
      std::cout << "availability test failed" << std::endl;
    } else {
      std::cout << "availability test passed" << std::endl;
    }
  }

  void testRestrictedBookFunctionality() {
    std::cout << "restricted book test: " << std::endl;
    RestrictedBook book("The Tale of Genji", "Murasaki Shikibu", 1100,
                        9780142437148, "Classic",
                        "Regarded as one of the world's first novels, this "
                        "epic masterpiece follows the life and loves of Prince "
                        "Genji in the imperial court of Heian Japan");
    Member member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    std::cout << "requesting access to restricted books: " << std::endl;
    book.requestAccess(&member);
    if (book.get_waitlist().size() != 1) {
      std::cout << "request failed" << std::endl;
    } else {
      std::cout << "request passed" << std::endl;
    }
    std::cout << "display info: " << std::endl;
    book.displayInfo();
  }

  void testLibraryFunctionality() {
    std::cout << "library testing: " << std::endl;
    Library library;
    Book* fictionBook =
        new FictionBook("The Handmaid’s Tale", "Margaret Atwood", 1985,
                        9780385490818, "Dystopian",
                        "In the totalitarian society of Gilead, Offred is a "
                        "handmaid forced into reproductive servitude");
    Book* nonFictionBook = new NonFictionBook(
        "Evicted", "Matthew Desmond", 2016, 9780553447453, "Sociology",
        "Desmond examines the impact of eviction on low-income families in "
        "America, shedding light on the cycle of poverty, housing instability, "
        "and systemic inequality");
    library.addFBook(fictionBook);
    library.addNFBook(nonFictionBook);
    Member* member1 =
        new Member("Alice", "2002-10-10", "alice@gmail.com", "123 Sesame");
    Member* member2 =
        new Member("Sam", "199-02-09", "bob@gmail.com", "44 Sussex");
    library.addMember(member1);
    library.addMember(member2);
    Borrow borrow(fictionBook, member1);
    library.addTransaction(&borrow);
    Donate donate(nonFictionBook, 9);
    library.addTransaction(&donate);
    if (library.checkMember("alice@gmail.com", member1->get_ID()) != member1) {
      std::cout << "member check failed" << std::endl;
    } else {
      std::cout << "member check passed" << std::endl;
    }

    if (library.checkBook(9780385490818) != fictionBook) {
      std::cout << "check book failed" << std::endl;
    } else {
      std::cout << "check book passed" << std::endl;
    }
    library.get_transactions();
    std::ifstream transFile("transactions.txt");
    std::string transContent((std::istreambuf_iterator<char>(transFile)),
                             std::istreambuf_iterator<char>());
    if (transContent.empty()) {
      std::cout << "download transactions test failed" << std::endl;
    } else {
      std::cout << "download transactions test passed" << std::endl;
    }
    std::remove("transactions.txt");
    library.get_members();
    std::ifstream memFile("members.txt");
    std::string memContent((std::istreambuf_iterator<char>(memFile)),
                           std::istreambuf_iterator<char>());
    if (memContent.empty()) {
      std::cout << "download members list failed" << std::endl;
    } else {
      std::cout << "download members list passed" << std::endl;
    }
    std::remove("members.txt");
    delete fictionBook;
    delete nonFictionBook;
    delete member1;
    delete member2;
  }

  void testMemberFunctionality() {
    std::cout << "member test: " << std::endl;
    Member member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    if (member.get_name() == "Tom" && member.get_email() == "tom@gmail.com" &&
        member.get_ID() != 0) {
      std::cout << "member created" << std::endl;
    } else {
      std::cout << "failed to create member" << std::endl;
    }
  }

  void testTransactionFunctionality() {
    std::cout << "transaction test: " << std::endl;
    Book* book = new FictionBook(
        "The Man Who Mistook His Wife for a Hat and Other Clinical Tales",
        "Oliver Sacks", 1985, 9780684853949, "Psychology",
        "Sacks shares a collection of fascinating case studies from his career "
        "as a neurologist, exploring the mysteries of the human brain and the "
        "complexities of perception, memory, and consciousness");
    Member* member =
        new Member("Tom", "1996-11-3", "tom@gmail.com", "445 Glandore");
    Borrow borrow(book, member);
    borrow.set_dateBorrowed(std::time(0) - (5 * 60));  // 5 mins testing period
    if (!borrow.get_isOverdue()) {
      std::cout << "overdue test failed" << std::endl;
    } else {
      std::cout << "overdue test passed" << std::endl;
    }
    delete book;
    delete member;
  }
};