#include "account.hh"
#include <iostream>
using namespace std;
Account::Account(const std::string& owner, bool has_credit):
    owner_(owner),
    has_credit_(has_credit)
{

    generate_iban();
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
void Account::print()
{
    cout<< owner_<<" : "<< iban_ << " : " << balance_ << " euros"<<endl;
}
void Account::set_credit_limit(int x){
    if(this->has_credit_==false){
        cout<< "Cannot set credit limit: the account has no credit card"<<endl;
    }
    else{
        this->credit_balance_=x;

    }
}
void Account::save_money(int x){
    this->balance_=x;
}
void Account::take_money(int x){

    if(this->has_credit_==true){
        if(this->balance_+credit_balance_-x<=0){

            cout<< "Cannot take money: credit limit overflow"<<endl;

        }
        this->balance_-=x;
        cout<< x<<" euros taken: "<< "new balance of " << this->iban_<< " is "<<this->balance_<<" euros"<<endl;
    }
    else{
        this->balance_-=x;
        if(this->balance_<0) {
            cout<< "Cannot take money: balance underflow"<<endl;
            this->balance_+=x;
        }
        else{
            cout<< x<<" euros taken: "<< "new balance of " << this->iban_<< " is "<<this->balance_<<" euros"<<endl;
        }

    }
}
void Account::transfer_to(Account &a1, int x){
    //int new_balance=0;
    if(this->has_credit_==true){

        if(this->balance_+credit_balance_-x<=0){

            cout<< "Cannot take money: credit limit overflow"<<endl;
            cout<< "Transfer from "<< this->iban_<<" failed"<<endl;
        }
        else{
            this->balance_-=x;
            a1.balance_+=x;
            cout<< x<<" euros taken: "<< "new balance of " << this->iban_<< " is "<<this->balance_<<" euros"<<endl;
        }
    }
    else{
        if(this->balance_-x<0) {
            //this->balance_+=x;
            cout<< "Cannot take money: balance underflow"<<endl;
            cout<< "Transfer from "<< this->iban_<<" failed"<<endl;
        }
        else{
            this->balance_-=x;
            a1.balance_+=x;
            cout<< x<<" euros taken: "<< "new balance of " << this->iban_<< " is "<<this->balance_<<" euros"<<endl;
        }
    }
}
