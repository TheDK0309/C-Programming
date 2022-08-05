#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
// TODO: Implement split function here
// Do not change main function
std::vector< std::string > split(std::string st,char separator,bool check=false){
    std::vector<std::string> splittedStrings;
    if(check==false){
        std::stringstream ss(st);
        std::string item;
        const int x=st.size()-1;
        while (std::getline(ss, item, separator))
        {
           splittedStrings.push_back(item);
           splittedStrings.erase(std::remove(splittedStrings.begin(), splittedStrings.end(),"\t"), splittedStrings.end());

        }
        //return splittedStrings;
        if(st[x]==separator) splittedStrings.push_back("\t ");
    }

    if(check==true){
        std::string word = "";
        // to count the number of split strings
        //int num = 0;
        // adding delimiter character at the end
        // of 'str'
        st = st + separator;
        // length of 'str'
        int l = st.size();
        // traversing 'str' from left to right
        //std::vector<std::string> substr_list;
        for (int i = 0; i < l; i++) {
        // if str[i] is not equal to the delimiter
        // character then accumulate it to 'word'
        if (st[i] != separator)
            word = word + st[i];
        else {
            // if 'word' is not an empty string,
            // then add this 'word' to the array
            // 'substr_list[]'
            if ((int)word.size() != 0)
                splittedStrings.push_back(word);
                // reset 'word'
                word = "";
            }
         }
         // return the splitted strings
         //return substr_list;
    }
    return splittedStrings;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
