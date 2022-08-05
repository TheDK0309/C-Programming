#include "book.hh"
#include "date.hh"
#include <string>
#include <iostream>
using namespace std;
Book::Book(const string name,const string author)
{
    this->name_=name;
    this->author_=author;
    this->is_loan_=false;
    this->is_available_=true;
}
void Book::print(){
    if(is_available_==true) {
        cout<< name_<< " : "<< author_<<endl;
        cout<<  "- available"<< endl;
    }
    else {
        cout<< name_<< " : "<< author_<<endl;
        cout<< "- loaned: ";
        this->loan_start_.print();
        cout<< "- to be returned: ";
        this->loan_end_.print();
    }
}
void Book::loan(Date& d){
    this->is_available_=false;
    if(this->is_loan_==false){

        this->loan_start_ = d;

        /*this->loan_start_.print();
        this->loan_start_.advance(28);
        this->loan_end_=this->loan_start_;
        cout<< "- to be returned: ";
        this->loan_end_.print();*/
        this->loan_end_=d;
        this->loan_end_.advance(28);

        this->is_loan_=true;
    }
    else if(this->is_loan_==true) cout <<"Already loaned: cannot be loaned"<<endl;

}
void Book::renew(){

    this->loan_end_.advance(28);
    if(is_loan_==false) cout<< "Not loaned: cannot be renewed" <<endl;


}
void Book::give_back(){
    is_loan_=false;
    is_available_=true;
}
