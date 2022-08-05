#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
const std::string HELP_TEXT = "S = store id1 i2\nP = print id\n"
                              "C = count id\nD = depth id\n";

class Employee{
    public:
        std::string name;
        int depth;
        std::vector<Employee *> subnetwork;
        Employee(){}
        Employee(std::string name,int depth){
            this->name=name;
            this->depth=depth;
        }
        void insert2(Employee * sub){
            subnetwork.push_back(sub);
        }
};
std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}
void cmd_P(Employee *e,int basedepth){
    for(int i=0;i<e->depth-basedepth;i++)
        std::cout<< "..";
    std::cout<< e->name<<std::endl;
    for(auto sub:e->subnetwork){
        cmd_P(sub,basedepth);
    }

}
int cmd_C(Employee *e){
    int count=0;
    for(auto sub:e->subnetwork){
        count+=1+cmd_C(sub);
    }
    return count;
}

int main()
{
    // TODO: Implement the datastructure here

    std::map<std::string,Employee *> EmployeeMap;
    while(true){
        std::string line;
        std::cout << "> ";
        getline(std::cin, line);
        std::vector<std::string> parts = split(line, ' ', true);

        std::string command = parts.at(0);

        if(command == "S" or command == "s"){
            if(parts.size() != 3){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id1 = parts.at(1);
            std::string id2 = parts.at(2);

            // TODO: Implement the command here!
            Employee *e =nullptr;
            if(EmployeeMap.find(id1)!=EmployeeMap.end()){
                e=EmployeeMap[id1];
            }
            else{
                Employee *new_e= new Employee(id1,1);
                EmployeeMap[id1]=new_e;
                e=new_e;
            }
            Employee *sub_e=new Employee(id2,e->depth+1);
            EmployeeMap[id2]=sub_e;
            e->insert2(sub_e);
        } else if(command == "P" or command == "p"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            if(EmployeeMap.find(id)!=EmployeeMap.end()){
                Employee *e=EmployeeMap[id];
                cmd_P(e,e->depth);
            }
        } else if(command == "C" or command == "c"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!
            if(EmployeeMap.find(id)!=EmployeeMap.end()){
                Employee *e=EmployeeMap[id];
                std::cout<<cmd_C(e)<<std::endl;
            }
        } else if(command == "D" or command == "d"){
            if(parts.size() != 2){
                std::cout << "Erroneous parameters!" << std::endl << HELP_TEXT;
                continue;
            }
            std::string id = parts.at(1);

            // TODO: Implement the command here!

        } else if(command == "Q" or command == "q"){
           return EXIT_SUCCESS;
        } else {
            std::cout << "Erroneous command!" << std::endl << HELP_TEXT;
        }
    }
}
