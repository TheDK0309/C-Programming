#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>
using namespace std;

class Account
{
public:
    // Constructor
    Account(const std::string& owner, bool has_credit = false);

    // More methods
    // Constructor

    // More methods
    void print();
    void set_credit_limit(int x);
    void save_money(int x);
    void take_money(int x);
    void transfer_to(Account& a1,int x);
private:
    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.
    void generate_iban();

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;
    string iban_;
    string owner_;
    int balance_;
    bool has_credit_;
    int credit_balance_;
    // More attributes/methods
};

#endif // ACCOUNT_HH
