#include <iostream>
#include <iomanip>
// Write here a function counting the mean value
using namespace std;

int main()
{
    int count=0,x;
    float mean,sum=0.0;
    cout << "From how many integer numbers you want to count the mean value? ";
    cin >> count;
    if(count<=0) cout << "Cannot count mean value from " << count << " numbers"<< endl;
    for(int i=0;i<count;i++){
        cout << "Input " << i+1 << ". number: ";
        cin >> x;
        sum+=x;

    }
    if(count>0){
        mean=sum/count;
        cout << "Mean value of the given numbers is "<< mean<<endl;
    }
    return 0;

}
