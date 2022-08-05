#include "cards.hh"
#include <iostream>

using namespace std;
// TODO: Implement the methods here
Cards::Cards() :top_(nullptr),bottom_(nullptr) {
}
Cards::~Cards() {
    while ( top_ != nullptr ) {
       Card_data* item_to_be_released = top_;
       top_ = top_->next;

       delete item_to_be_released;
    }
}

void Cards::add(int id){
    /*Card_data* new_item = new Card_data{id, nullptr};

    if ( top_ == nullptr ) {
        bottom_ = new_item;
        top_ = new_item;

    } else {
       bottom_->next = new_item;
       bottom_ = new_item;
    }*/
    Card_data* new_node = new Card_data();

    new_node->data = id;
    new_node->next = top_;
    top_ = new_node;
}

void Cards::print_from_top_to_bottom(std::ostream& s){
    Card_data* item_to_be_printed = top_;
    int n = 1;

    while ( item_to_be_printed != nullptr ) {
       s << n << " : " << item_to_be_printed->data << endl;
       ++n;
       item_to_be_printed = item_to_be_printed->next;
    }
}

bool Cards::remove(int& id){
    if(top_==nullptr){
        return false;
    }
    /*Card_data* item_to_be_removed = top_;

    id = item_to_be_removed->data;

    if ( top_ == bottom_ ) {
       top_ = nullptr;
       bottom_ = nullptr;
    } else {
       top_ = top_->next;
    }

    delete item_to_be_removed;*/
    if (top_ == NULL)
            return NULL;

        // Move the head pointer to the next node
        Card_data* temp = top_;
        id=temp->data;
        top_ = top_->next;

        delete temp;

    return true;

}

bool Cards::bottom_to_top(){
    // Initialize second last
    Card_data *secbottom=new Card_data;
    bottom_=top_;
    if(top_==nullptr || top_->next==nullptr){
        return false;
    }
    /*After this loop secLast contains
        address of second last node and
        last contains address of last node in Linked List */
    while(bottom_->next!=nullptr){
        secbottom=bottom_;
        bottom_=bottom_->next;
    }
    /* Set the next of second last as NULL */
    secbottom->next=nullptr;
    /* Set next of last as head node */
    bottom_->next=top_;
    /* Change the head pointer
        to point to last node now */
    top_=bottom_;
    return true;
}

bool Cards::top_to_bottom(){
    /* Initialize first and last pointers */
    struct Card_data* first = top_;
    struct Card_data* last = top_;
    if(top_==nullptr || top_->next==nullptr){
        return false;
    }
    /*After this loop last contains address
        of last node in Linked List */
    while (last->next != nullptr) {
            last = last->next;
        }
        /* Change the head pointer to point
           to second node now */
        top_ = first->next;
        /* Set the next of first as NULL */
        first->next = nullptr;
        /* Set the next of last as first */
        last->next = first;
    return true;
}
void Cards::recursive_print(Card_data* top, std::ostream& s){

    if(top==NULL) return;
    //int n = 1;
    recursive_print(top->next, s);
    s<<top->data<<endl;
}

void Cards::print_from_bottom_to_top(std::ostream& s){
     recursive_print(top_,s);
}
