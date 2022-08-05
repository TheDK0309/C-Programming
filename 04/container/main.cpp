#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        ints.push_back(new_integer);
        // TODO: Implement your solution here
    }
}
bool same_values(std::vector<int> x){
    set<int> s(x.begin(), x.end());
    if(s.size()>1){
        return false;
    }
    return true;
}
bool is_ordered_non_strict_ascending(std::vector<int> x){
    /*for(unsigned int i=0;i<x.size();i++){
        if(x[i]<x[i+1]) return true;
        return false;

    }*/
    if(is_sorted(x.begin(),x.end())) return true;
    else return false;
}

bool is_arithmetic_series(std::vector<int> x){
    int d = x[1] - x[0];
    for (unsigned int i = 2; i < x.size(); i++) {
            if (x[i] - x[i - 1] != d){
                return false;
            }
     }
     return true;

}
bool is_geometric_series(std::vector<int> x){

    if(x[0]==0) {
        return false;

    }
    int ratio = x[1] / x[0];

    for (unsigned int i = 2; i < x.size(); i++) {
        if(x[i-1]==0) {
            return false;

        }
        if (x[i] / x[i - 1] != ratio){
             return false;
        }

     }
     return true;
}

// TODO: Implement your solution here


int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
