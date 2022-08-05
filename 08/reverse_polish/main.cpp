#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
using namespace std;
bool isNumber(string s)
{
    for (unsigned i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
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

        if(st[x]==separator) splittedStrings.push_back("\t ");
    }

    if(check==true){
        std::string word = "";

        st = st + separator;

        int l = st.size();

        for (int i = 0; i < l; i++) {

        if (st[i] != separator)
            word = word + st[i];
        else {

            if ((int)word.size() != 0)
                splittedStrings.push_back(word);

                word = "";
            }
         }

    }
    return splittedStrings;
}
int scanNum(char ch){
   int value;
   value = ch;
   return int(value-'0');
}
int isOperator(char ch){
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/')
      return 1;
   return -1;
}
int isOperand(char ch){
   if(ch >= '0' && ch <= '9')
      return 1;
   return -1;
}
int operation(int a, int b, char op){
   int x=0;
   if(op == '+')
      x= b+a;
   else if(op == '-')
      x= b-a;
   else if(op == '*')
      x= b*a;
   else if(op == '/')
      x= b/a;
   return x;
}
int postfixEval(string postfix){
   int a, b;
   stack<int> stk;
   string::iterator it;
   for(it=postfix.begin(); it!=postfix.end(); it++){

      if(isOperator(*it) != -1){
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push(operation(a, b, *it));
      }
      else if(isOperand(*it) > 0){
         stk.push(scanNum(*it));
      }
   }
   return stk.top();
}
int main(){
    string line;
    string post="";
    vector<string> v;
    cout<< "Input an expression in reverse Polish notation (end with #): "<<endl;
    cout<< "EXPR> ";
    do{
        getline(cin,line);
        post+=line;
        if(line.back()=='#') break;

    }while(line!="#");
    v=split(post,' ');
    post.erase(remove(post.begin(), post.end(), ' '), post.end());
    post.erase(remove(post.begin(), post.end(), '#'), post.end());
    v.pop_back();
    /*for(int i=0;i<v.size();i++){
       cout<< v[i] ;
    }
    cout<<endl;*/
    int operators_num=0;
    int operands_num=0;
    for(unsigned int i=0;i<v.size();i++){
       if(v[i] == "+"|| v[i] == "-"|| v[i] == "*"|| v[i] == "/"){
           operators_num++;
       }
       else if(v[i] >= "0" && v[i] <= "9"){
           operands_num++;
       }
       else{
           cout<< "Error: Unknown character" <<endl;
           return EXIT_FAILURE;
       }
       if(v[i]== "/" && v[i-1]=="0"){
           cout<< "Error: Division by zero" <<endl;
           return EXIT_FAILURE;
       }
       if(v[i]== "/" && !isNumber(v[i-1]) && operands_num-operators_num==1){
           cout<< "Error: Division by zero" <<endl;
           return EXIT_FAILURE;
       }
       /*else{
           cout << "Correct: "<<postfixEval(post) << " is the result";
            return EXIT_SUCCESS;
        }*/
        if(!isNumber(v[0])){
            cout<< "Error: Expression must start with a number " <<endl;
            return EXIT_FAILURE;
        }

   }
   /*cout<< operators_num <<endl;
   cout<<operands_num<< endl;*/
   if(operands_num-operators_num!=1){
       if(operands_num-operators_num>1){
           cout<< "Error: Too few operators"<<endl;
           return EXIT_FAILURE;
       }
       if(operands_num-operators_num<=0){
           cout<< "Error: Too few operands"<<endl;
           return EXIT_FAILURE;
       }
   }
   cout << "Correct: "<<postfixEval(post) << " is the result" <<endl;
   return EXIT_SUCCESS;
}
