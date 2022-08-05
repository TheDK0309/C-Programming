#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <date.hh>
using namespace std;

class Book
{
public:
    Book(const string name,const string author);
    void loan(Date& d);
    void print();
    void renew();
    void give_back();

private:
    string name_;
    string author_;
    bool is_available_;
    bool is_loan_;
    Date loan_start_;
    Date loan_end_;
};

#endif // BOOK_H
