#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
default_random_engine rand_gen;
void produce_random_numbers(unsigned int lower, unsigned int upper)
{


        /*cout << "Enter a seed value or an empty line: ";
        string seed_value = "";
        cin.get();
        getline(cin, seed_value);
        cout<<endl;
        if( seed_value == "" ) {
            // If the user did not give a seed value, use computer time as the seed value.
            rand_gen.seed( time(NULL) );
        } else {
            // If the user gave a seed value, use it.
            rand_gen.seed( stoi(seed_value) );
        }
        while(1){
            string x="";
            std::uniform_int_distribution<int> distribution(lower, upper);
            cout<< "Your drawn random number is " <<distribution(rand_gen)<<endl;
            cout<< "Press enter to continue or q to quit: ";
            getline(cin, x);
            if(x=="q") break;
            else{
                cout<<endl;
                distribution(rand_gen);
            }
        }*/
        std::uniform_int_distribution<int> distribution(lower, upper);
        string line_feed="";
        while(line_feed!="q"){
            cout<< "Your drawn random number is " <<distribution(rand_gen)<<endl;
            cout<< "Press enter to continue or q to quit: ";
            getline(cin, line_feed);
            cout<<endl;
        }

}

int main()
{
    unsigned int lower_bound, upper_bound;
    cout << "Enter a lower bound: ";
    cin >> lower_bound;
    cout << "Enter an upper bound: ";
    cin >> upper_bound;

    if(lower_bound >= upper_bound)
    {
        cout << "The upper bound must be strictly greater than the lower bound" << endl;
        return EXIT_FAILURE;
    }

    cout << "Enter a seed value or an empty line: ";
    string line_feed = "";
    cin.get();
    getline(cin, line_feed);
    cout<<endl;

    if( line_feed == "" ) {
        // If the user did not give a seed value, use computer time as the seed value.
        rand_gen.seed( time(NULL) );
    } else {
        // If the user gave a seed value, use it.
        rand_gen.seed( stoi(line_feed) );
    }

    std::uniform_int_distribution<int> distribution(lower_bound, upper_bound);

    cout<< "Your drawn random number is " <<distribution(rand_gen)<<endl;
    cout<< "Press enter to continue or q to quit: ";
    getline(cin, line_feed);
    cout<<endl;

    if(line_feed!="q"){
        produce_random_numbers(lower_bound, upper_bound);
    }
    return EXIT_SUCCESS;

}
