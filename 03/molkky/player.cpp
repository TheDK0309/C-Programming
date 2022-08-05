#include "player.hh"
#include <string>
#include <iostream>
using namespace std;
Player::Player(string name)
{
    this->name_=name;
}
string Player::get_name(){
    return this->name_;
}
int Player::get_points(){
    return this->score_;
}
void Player::add_points(int x){
    this->score_+=x ;
    if(this->score_ >50) cout<< this->name_ <<" gets penalty points!"<<endl;
    while (this->score_>50) {
        this->score_=this->score_-(this->score_-50)-25;
        //cout<< this->name_ <<" gets penalty points!"<<endl;
    }
}
bool Player::has_won(){
    if(this->score_==50) return true;

    else return false;

}
