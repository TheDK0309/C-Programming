#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    string key="";
    string::size_type temp = 0;

    cout << "Enter the encryption key: ";
    getline(cin,key);
    temp = key.length();

    set <char> s1(begin(key), end(key));

    if(temp<26 || temp>26) {
        cout<<"Error! The encryption key must contain 26 characters."<<endl;
        return EXIT_FAILURE;
    }
    for(unsigned int i=0;i<key.length();i++){
        if(isupper(key[i])){
            cout<< "Error! The encryption key must contain only lower case characters."<<endl;
            return EXIT_FAILURE;
         }
    }

    /*for (auto i : s1){
        cout << i << " ";

    }*/

    if(s1.size()<26){
        cout<<"Error! The encryption key must contain all alphabets a-z."<<endl;
        return EXIT_FAILURE;
    }

    string text="";
    cout <<"Enter the text to be encrypted: ";
    getline(cin,text);


    for(unsigned int j=0;j<text.length();j++){
            if(text[j]=='a') text[j]=key[0];
            else if(text[j]=='b') text[j]=key[1];
            else if(text[j]=='c') text[j]=key[2];
            else if(text[j]=='d') text[j]=key[3];
            else if(text[j]=='e') text[j]=key[4];
            else if(text[j]=='f') text[j]=key[5];
            else if(text[j]=='g') text[j]=key[6];
            else if(text[j]=='h') text[j]=key[7];
            else if(text[j]=='i') text[j]=key[8];
            else if(text[j]=='j') text[j]=key[9];
            else if(text[j]=='k') text[j]=key[10];
            else if(text[j]=='l') text[j]=key[11];
            else if(text[j]=='m') text[j]=key[12];
            else if(text[j]=='n') text[j]=key[13];
            else if(text[j]=='o') text[j]=key[14];
            else if(text[j]=='p') text[j]=key[15];
            else if(text[j]=='q') text[j]=key[16];
            else if(text[j]=='r') text[j]=key[17];
            else if(text[j]=='s') text[j]=key[18];
            else if(text[j]=='t') text[j]=key[19];
            else if(text[j]=='u') text[j]=key[20];
            else if(text[j]=='v') text[j]=key[21];
            else if(text[j]=='w') text[j]=key[22];
            else if(text[j]=='x') text[j]=key[23];
            else if(text[j]=='y') text[j]=key[24];
            else if(text[j]=='z') text[j]=key[25];

    }
    cout<<"Encrypted text: "<<text<<endl;
}
