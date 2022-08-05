#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string input_file="",output_file="";
    cout<< "Input file: " ;
    cin >> input_file ;

    cout<< "Output file: ";
    cin >> output_file;
    ifstream input_file_object(input_file);

    if(input_file_object){
        ofstream output_file_object(output_file);
        int x=1;
        string line;
        while(getline(input_file_object, line)){
            output_file_object << x <<" "<<line<<endl;
            x++;
        }
        input_file_object.close();
        output_file_object.close();
        return EXIT_SUCCESS;
    }
    else{
        cout << "Error! The file "<< input_file << " cannot be opened." <<endl;
        return EXIT_FAILURE;

    }
    //


}
