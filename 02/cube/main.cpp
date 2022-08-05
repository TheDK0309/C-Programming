#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cout<<"Enter a number: ";
    cin >> num;

    if(pow(num,3)>pow(2,32)){
        cout<< "Error! The cube of " << num <<" is not " << num*num*num<< endl;
    }
    else{
        cout <<"The cube of " <<num<< " is "<< pow(num,3) <<endl;
    }
}
