/* Education_centre
 *
 * Desc:
 *  This program will read data from a input file which content data based on
 *  form: <location>;<theme>;<course_name>;<number_of_enrollments>.
 *  At first stage, program will check if the input file is correct or not. If yes,
 *  all data will be analyzed and stored to data structure.
 *  This program has following options to search for information:
 *      + locations - Prints all the known locations in alphabetical order.
 *      + courses <location> <theme> - The command prints all the courses and the number
 *      of enrollments of them in the location and theme in question arranged alphabetically by the course name.
 *      + courses_in_theme <theme> - The command prints all courses under the given
 *      theme in all locations.
 *      + available - The command prints the locations, themes, and names of
 *      all those courses that are free to be enrolled in, i.e. that are not full.
 *      + favorite_theme The command prints the most popular theme.
 *      + quit - The program terminates with the return value EXIT_SUCCESS without printing anything.
 *
 * Program author 1 ( Fill with your own info )
 * Name: Thong Nguyen
 * Student number: 050366558
 * UserID: fmthng ( Necessary due to gitlab folder naming. )
 * E-Mail: thong.nguyen@tuni.fi
 *
 * Program author 2 ( Fill with your own info )
 * Name: Le Do
 * Student number: 050366862
 * UserID: mmledo ( Necessary due to gitlab folder naming. )
 * E-Mail: le.do@tuni.fi
 *
 * */

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;
//check if string is a number, paramenter is a string, return true if the string is digit, otherwise return false
bool isNumber(string s)
{
    for (unsigned i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
struct Course {
    string name;
    string theme;
    string enrollments;
};

//Analyze input command
 vector< string> split(const  string& s, const char delimiter, bool ignore_empty = false){
    vector< string> result;
    string tmp = s;
    int count = 0;
    unsigned a=0;
    while(tmp.find(delimiter) !=  string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());

        if(s.find("\"") != string::npos && count == 2) // Case has space in third paramenter
        {
            for (unsigned i = 0; i < s.length(); i++)
            {
                if(s.substr(i,1) == "\"")
                    a = i+1;
            }
            new_part = s.substr(2+result.at(0).length()+result.at(1).length(),a-2-result.at(0).length()-result.at(1).length());
            new_part=new_part.substr(1,new_part.length()-2);
            tmp = tmp.substr(tmp.find("\"")+1, tmp.size());
        }
        if(!(ignore_empty && new_part.empty()))
        {
            result.push_back(new_part);
        }
        count++;
    }
    if(!(ignore_empty && tmp.empty()))
    {
        if(tmp.find("\"") != string::npos) // Case doesnt content space and has "" in third parameter
        {
            tmp=tmp.substr(1,tmp.length()-2);
        }
        result.push_back(tmp);
    }
    return result;
}
//function that removes redundant value in available command, parameter is a vector of type string
 void remove(std::vector<string> &v)
 {
     std::vector<string>::iterator itr = v.begin();
     std::unordered_set<string> s;

     for (auto curr = v.begin(); curr != v.end(); ++curr) {
         if (s.insert(*curr).second)
             *itr++ = *curr;
     }

     v.erase(itr, v.end());
 }

void print(const  string& item) //print the given string, paramenter is a string
{
     cout << item <<  endl;
}
int main()
{
    int x; //value stores the integer value converted from string from vector_enrollments
    string city;  //course's location
    multimap<string,Course> Course_Info; // multimap of info of course
    set<string> city_set;  //unique value of locations
    vector<string> vector_enrollments; //vector of struct's enrollments
    Course course_object;
    vector <int> vector_enrollments_int;  //vector of struct's enrollments in int type
    vector <string> vector_name; //vector of struct's name
    set<string> set_name; //unique value of name
    vector<string>key_vector; //vector of unique name values, will take from set_name
    map<string,Course> course_in_theme;
    multimap<string,int> mp;  //multimap of name and enrollments
    vector<int> sum; //vector stores sum of name's enrollments number.
    int maxElement;
    //int maxElementIndex;  //max value of sum of number of course's enrollment in vecotr sum and its index;
    vector<string> vector_theme; //vector of struct's theme
    vector<string> vector_city; //vector of location
    string s0=""; //string that stores information in form theme --- enrollments for course command
    string s=""; //string that stores information in form city:name:theme for available command
    vector<string> t1; //vector that stores strings from s0
    vector<string> t; //vector that stores strings from s
    // Get name file and open file
    string INfilename = "course.input";
    cout << "Input file: ";
    getline(cin, INfilename);
    ifstream input_file_object(INfilename);
    bool isempty = false;
    //********************//

    if(input_file_object){
        string line;
        if(input_file_object.peek() == ifstream::traits_type::eof())        // Check empty file
        {
            isempty = true;
        }
        // Patch data into data structure
        while(getline(input_file_object,line)){
            int field = 0;
            for (unsigned len = 0; len < line.length();len++)
            {
                if (line.substr(len,1) == ";")
                    field++;
            }
            if(isempty == false && field != 3)
            {
                cout << "Error: empty field\n" << endl;
                return EXIT_FAILURE;
            }
            stringstream ss(line);
            //read each lines from the files and assigns value to variable, seperated by ';'
            getline(ss,city,';');
            getline(ss,course_object.name,';');
            getline(ss,course_object.theme,';');
            getline(ss,course_object.enrollments);

            city_set.insert(city);  //insert location to unique container for locations command
            Course_Info.insert(pair<string,Course>(city,course_object));   //creat multimap of the informations
            //push data to coresponding vectors
            vector_city.push_back(city);
            vector_theme.push_back(course_object.theme);
            vector_name.push_back(course_object.name);
            vector_enrollments.push_back(course_object.enrollments);
            course_in_theme.insert(pair<string,Course>(course_object.theme,course_object));
            //check if values in enrollments in vector_enrollments are digit or not
            for(unsigned i=0;i<vector_enrollments.size();i++){
                //if values are digit, converts them to int and push to vector_enrollments_int
                if (isNumber(vector_enrollments[i])){
                    x=stoi(vector_enrollments[i]);
                    vector_enrollments_int.push_back(x);
                }
                //if not, "full" become "50", converts them to int and push to vector_enrollments_int
                else {
                    vector_enrollments[i]="50";
                    x=stoi(vector_enrollments[i]);
                    vector_enrollments_int.push_back(x);

                }
            }
            mp.insert(make_pair(course_object.name,x));
            set_name.insert(course_object.name);
            key_vector.assign(set_name.begin(),set_name.end());  //convert set_name to vector key_vector
            for(unsigned int i=0;i<key_vector.size();i++){  //fills sum vector with 0s according to key_vector's size
                sum.push_back(0);
            }
            for(unsigned i=0;i<vector_city.size();i++){  //if course's enrollment numbers are not full
                if(vector_enrollments[i]!="50"){
                    s+= vector_city[i]+" : "+vector_name[i]+" : "+vector_theme[i];  //push the information of free courses to string s in format city:name:theme
                    t.push_back(s);  //push strings s to vector t
                    s=""; //empty the string before resuming the process
                }
            }
            remove(t);   //removes redundant course's info in the vector
            sort(t.begin(), t.end());  //sort the vector in alphabet order
        }
        input_file_object.close();
    }
    else
    {
        cout << "Error: the input file cannot be opened\n" << endl;
        return EXIT_FAILURE;
    }


    for (auto itr = mp.begin(); itr != mp.end(); itr++)  //sum the value of same key(course's name) and push to sum vector
    {
        for (unsigned i=0;i<key_vector.size();i++) {
            if (itr -> first == key_vector[i]) {
                //cout << key_vector[i] << "  " << itr -> second << endl;
                sum[i]+=   itr -> second;
            }
        }
    }
    //*************************************************************************//

    //Command Promtp
    while(true){
             string line;
             cout << "> ";
            getline( cin, line);
            if (line == "") {
                cout << "Error: Unknown command: " << "invalid space " << endl;
                continue;
            }
             vector< string> parts = split(line, ' ', true);

             string command = parts.at(0);

            if(command == "locations"){
                for(set<string>::iterator i=city_set.begin();i!=city_set.end();i++){
                    cout<< *i <<endl;
                } //command locations
            }

            else if(command == "courses"){
                if(parts.size() != 3){
                    cout << "Error: error in command courses" << endl;
                    continue;
                }
                string place = parts.at(1);
                string theme_req = parts.at(2);
                bool match_P = false, match_T = false;
                for(unsigned int i=0;i<vector_city.size();i++){
                    if(vector_city[i]==place && vector_name[i]==theme_req){
                        if(vector_enrollments[i]=="50") s0+=vector_theme[i] +" --- full";
                        else s0+= vector_theme[i] + " --- " + vector_enrollments[i]+ " enrollments";
                        t1.push_back(s0);
                        s0="";
                    }
                    if (vector_city[i]==place) match_P = true;  //if given location match
                    if (vector_name[i]==theme_req) match_T = true;  //if given name match
                }
                remove(t1);
                sort(t1.begin(), t1.end());
                for(unsigned int j=0;j<t1.size();j++){
                    cout<< t1[j] <<endl;
                }
                t1.clear();
                //if not throw error.
                if (match_P == false) cout << "Error: unknown location name" << endl;
                else if (match_T == false) cout << "Error: unknown theme" << endl;
            } //command courses <location> <theme>
            else if(command == "available"){
                for(unsigned j=0;j<t.size();j++){
                    cout<< t[j] <<endl;
                }
            }//command available
            else if(command == "courses_in_theme"){
                if(parts.size() != 2){
                    cout << "Error: unknown theme" << endl;
                    continue;
                }
                string theme_req = parts.at(1);
                vector<string> check; //vector stores course's theme
                for(map<string,Course>::iterator i=course_in_theme.begin();i!=course_in_theme.end();i++){
                   // cout << i->first << ":" << i->second <<endl;
                    if(i->second.name==theme_req){
                        bool allow = true;  // flag allows pushing course's theme to check
                        for (unsigned count=0; count < check.size();count++)
                        {
                            if(i->first == check.at(count)) //if theme is already inside vector check, switch the flag to false
                            {
                                allow = false;
                                break;
                            }
                        }
                        if(allow == true)  //otherwise push the theme into vector check
                        {
                            check.push_back(i->first);
                        }
                    }
                }
                if (check.size() == 0)
                {
                    cout << "Error: unknown theme" << endl;
                }
                else
                {
                    set< string> sortedItems; //set to sort vector check
                    for (unsigned z = 0; z < check.size(); z++)
                    {
                        sortedItems.insert(check.at(z));  //push content of vector check to set
                    }
                    for_each(sortedItems.begin(), sortedItems.end(), &print);
                }
            }
            else if(command == "favorite_theme"){
                if (isempty == true) //check if file is empty
                {
                    cout << "No enrollments" << endl;
                }
                else
                {
                    vector<int> position; //vector stores position of index of max value
                    //maxElementIndex = max_element(sum.begin(),sum.end()) - sum.begin();
                    maxElement = *max_element(sum.begin(), sum.end());
                    for (unsigned a = 0; a < sum.size(); a++)
                    {
                        if (sum.at(a) == maxElement)  //check position of max value and push to position vector
                            position.push_back(a);
                    }
                    cout << maxElement <<" enrollments in themes " <<endl;
                    for (unsigned b = 0; b < position.size(); b++) //if there are multiple courses with the same max value, print their name
                    {
                          cout << "--- " << key_vector[position.at(b)] <<endl;
                    }
                }
             //command favourite
            }
            else if(command == "quit"){
                return EXIT_SUCCESS;
            }
            else {
                 cout << "Error: Unknown command: " << command << endl;
            }
        }

}
