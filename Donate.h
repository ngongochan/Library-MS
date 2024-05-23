#ifndef DONATE_H
#define DONATE_H

#include <ctime>

#include "Transaction.h"

class Book;

class Donate : public Transaction {
 private:
  std::time_t dateDonated;
  int condition;

 public:
  Donate();
  Donate(Book* book, int condition);

  void print();

  void set_dateDonated(time_t dateDonated);
  std::time_t get_date();

  void set_condition(int);
  int get_condition();

  Member* get_member();
};

#endif