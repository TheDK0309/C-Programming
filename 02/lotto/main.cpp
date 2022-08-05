#include <iostream>

using namespace std;
long long int factorial(int n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
/*long long int lottery(int x,int y){
    if(x<0 || y<0) cout<< "The number of balls must be a positive number."<<endl;
    else if(x<y) cout<<"The maximum number of drawn balls is the total amount of balls."<<endl;
    else{
        return factorial(x)/(factorial(x-y)*factorial(y));
    }
}*/
int main()
{
    int x,y;
    cout<< "Enter the total number of lottery balls: ";
    cin>>x;
    cout<<"Enter the number of drawn balls: ";
    cin>>y;
    if(x<0 || y<0) cout<< "The number of balls must be a positive number."<<endl;
    else if(x<y) cout<<"The maximum number of drawn balls is the total amount of balls."<<endl;
    else{
        //cout<< factorial(x)<<endl;
        cout<<"The probability of guessing all "<<y<<" balls correctly is 1/"<<(unsigned long long int)((factorial(x))/(factorial(x-y)*factorial(y)))<<endl;
        //cout<<(unsigned long long int)((factorial(x))/(factorial(x-y)*factorial(y)))<<endl;
    }
}
