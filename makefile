CXX = g++
CXXFLAGS = -Wall -g

all: main
	@./main

main: Book.o FictionBook.o RestrictedBook.o NonFictionBook.o AcademicText.o Member.o Transaction.o Borrow.o Donate.o Library.o LibraryDatabaseMain.o 
	@ $(CXX) $(CXXFLAGS) Book.o FictionBook.o RestrictedBook.o NonFictionBook.o AcademicText.o Member.o Transaction.o Borrow.o Donate.o Library.o LibraryDatabaseMain.o -o main

##test: Book.o FictionBook.o RestrictedBook.o NonFictionBook.o AcademicText.o Member.o Transaction.o Borrow.o Donate.o Library.o LibraryDatabaseFunctionsTestMain.o 
## @ $(CXX) $(CXXFLAGS) Book.o FictionBook.o RestrictedBook.o NonFictionBook.o AcademicText.o Member.o Transaction.o Borrow.o Donate.o Library.o LibraryDatabaseFunctionsTestMain.o -o test

unittest: Book.o FictionBook.o RestrictedBook.o NonFictionBook.o AcademicText.o Member.o Transaction.o Borrow.o Donate.o Library.o UnitTestMain.o 
	@ $(CXX) $(CXXFLAGS) Book.o FictionBook.o RestrictedBook.o NonFictionBook.o AcademicText.o Member.o Transaction.o Borrow.o Donate.o Library.o UnitTestMain.o -o unittest
	@./unittest

Book.o: Book.cpp Book.h
	@$(CXX) $(CXXFLAGS) -c Book.cpp

FictionBook.o: FictionBook.cpp FictionBook.h Book.h Member.h Borrow.h
	@$(CXX) $(CXXFLAGS) -c FictionBook.cpp

RestrictedBook.o: RestrictedBook.cpp RestrictedBook.h Book.h Member.h Borrow.h
	@$(CXX) $(CXXFLAGS) -c RestrictedBook.cpp

NonFictionBook.o: NonFictionBook.cpp NonFictionBook.h Book.h Member.h Borrow.h
	@$(CXX) $(CXXFLAGS) -c NonFictionBook.cpp

AcademicText.o: AcademicText.cpp AcademicText.h Book.h Member.h Borrow.h
	@$(CXX) $(CXXFLAGS) -c AcademicText.cpp

Member.o: Member.cpp Member.h
	@$(CXX) $(CXXFLAGS) -c Member.cpp

Transaction.o: Transaction.cpp Transaction.h Book.h Member.h
	@$(CXX) $(CXXFLAGS) -c Transaction.cpp

Borrow.o: Borrow.cpp Borrow.h Transaction.h Book.h Member.h
	@$(CXX) $(CXXFLAGS) -c Borrow.cpp

Donate.o: Donate.cpp Donate.h Book.h Member.h
	@$(CXX) $(CXXFLAGS) -c Donate.cpp

Library.o: Library.cpp Library.h Book.h Member.h Transaction.h
	@$(CXX) $(CXXFLAGS) -c Library.cpp

LibraryDatabaseMain.o: LibraryDatabaseMain.cpp LibraryDatabaseFunctions.h Book.h FictionBook.h NonFictionBook.h RestrictedBook.h AcademicText.h Member.h Transaction.h Borrow.h Donate.h Library.h
	@$(CXX) $(CXXFLAGS) -c LibraryDatabaseMain.cpp

LibraryDatabaseFunctionsTestMain.o: LibraryDatabaseFunctionsTestMain.cpp LibraryDatabaseFunctionsTest.h
	@$(CXX) $(CXXFLAGS) -c LibraryDatabaseFunctionsTestMain.cpp

UnitTestMain.o: UnitTestMain.cpp UnitTest.h
	@$(CXX) $(CXXFLAGS) -c UnitTestMain.cpp

.PHONY: clean
clean:
	rm -f *.o main