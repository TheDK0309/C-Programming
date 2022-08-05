/* Education_centre
 *
 * Desc:
 *  This program will read data from a input file which content data based on
 *  form: <ID>;<Department>;<Time in service>;<Boss>.
 *  At first stage, program will check if the input file is correct or not. If yes,
 *  all data will be analyzed and stored to data structure.
 *  This program has following options to search for information:
 *      + addNewEmployee - Adds a new Employee to the datastructure.
 *      + printEmployees - Print id, department and time of service of the Employee from the data structure
 *      + addRelation - Adds new boss-subordinate relation using Pointers
 *      + printBoss - Print the employee's boss's id if there is any, return error if not or employee's id not found
 *      + printSubordinates Print subordinates of the employee if there are any, return error if not or employee's id not found
 *      + print department - Print the employee's colleagues(colleagues,subordinates, bosses) in the same department and hierachy with the employee if there are any
 *      return error if not or the employee's id not found
 *      + printColleagues - Print the colleagues of an employee under the same boss if there are any, return error if not or employee's id not found
 *      + printLongestTimeInLineManagement - print the longest time of service employee under a boss's line management, if the boss is the longest or the employee
 *      does not have colleagues, return that employee/boss's time, return error if employee's id not found
 *
 * Program author ( Fill with your own info )
 * Name: Le Do
 * Student number: 050366862
 * UserID: mmledo ( Necessary due to gitlab folder naming. )
 * E-Mail: le.do@tuni.fi
 *
 * */
#include "company.hh"
Company::Company(){

}
Company::~Company(){

}
void Company::addNewEmployee(const std::string& id, const std::string& dep, const double& time,
                    std::ostream &output){
    Employee* E=new Employee; //create new Employee's struct object

    if(Employee_Data.find(id)!=Employee_Data.end()){  //return error if the employee's id already in the map
        output<< "Error. Employee already added."<<std::endl;
    }
    else{  //if not, initialize its id, department, time of service and do not have any relations yet, to the map.
        E->id_=id;
        E->department_=dep;
        E->time_in_service_=time;
        E->boss_=nullptr;
        E->subordinates_.empty();
        Employee_Data[id]=E;
    }
}

void Company::printEmployees(std::ostream &output) const{
    for(auto i=Employee_Data.begin();i!=Employee_Data.end();i++){  //print the employee's data from the stored map
        output << i->first << ", " << i->second->department_ << ", "<<i->second->time_in_service_<<std::endl;
    }
}

void Company::addRelation(const std::string& subordinate,
                 const std::string& boss,
                 std::ostream& output){
        if(Employee_Data.find(subordinate)==Employee_Data.end()){  //if the id of subordinate can not be found in the stored map
            output << "Error. " << subordinate << " not found."<< std::endl;
        }
        else if(Employee_Data.find(subordinate)==Employee_Data.end()){ //if the id of boss can not be found in the stored map
            output << "Error. " << boss << " not found."<< std::endl;
        }
        else{
            Employee * e_boss=getPointer(boss);  //creat new object of the boss

            Employee * e_employee=getPointer(subordinate); //creat new object of the subordinate

            if(boss!="" && e_employee) {  //if boss provided is not null, link the employee's boss pointer to the boss's object
                e_employee->boss_= e_boss;
            }
            if(subordinate!="" && e_boss){ //if subordinate provided is not null, link the boss's subordinate pointer to the subordinate's object by pushing surbodinate's objects to the boss's surbodinate vector
                e_boss->subordinates_.push_back(e_employee);
            }
        }
}

void Company::printBoss(const std::string& id,
               std::ostream& output) const{
    if(Employee_Data.find(id)==Employee_Data.end()){ //if the id cannot be found in the map, return error
        output << "Error. " << id << " not found."<< std::endl;
    }
    else{
        Employee * e_employee=getPointer(id); //crete the object of the employee
        if(e_employee->boss_==nullptr) output << id <<" has no bosses." <<std::endl; //if the employee's boss pointer is null, it has no bosses
        else{
            output <<id<<" has 1 bosses: "<<std::endl;
            output<< e_employee->boss_->id_ << std::endl; //if not, print the boss's id
       }
    }
}

void Company::printSubordinates(const std::string& id,
                       std::ostream& output) const{
    if(Employee_Data.find(id)==Employee_Data.end()){ //if the id cannot be found in the map, return error
        output << "Error. " << id << " not found."<< std::endl;
    }
    else{
        Employee * e_boss=getPointer(id); //creat object of the boss
        if(e_boss){
            if(e_boss->subordinates_.size()==0) output<< id <<" has no subordinates." <<std::endl; //if the subordinate's vector is empty, the boss does not have any subordinates
            else{
                output <<id<<" has "<< e_boss->subordinates_.size() <<" subordinates: "<<std::endl;

                std::set<std::string> set_subordinate; //set used to store the subordinate's id and sort them alphabetically
                for(unsigned int i=0;i<e_boss->subordinates_.size();i++){
                    set_subordinate.insert(e_boss->subordinates_[i]->id_);
                }

                for(auto i:set_subordinate){
                    output<<i<<std::endl;
                }
            }
        }
    }
}

void Company::printColleagues(const std::string& id,
                     std::ostream& output) const{
    int n=0;
    std::string boss; //string stores id of the employee's boss
    Employee * e_boss{nullptr}; //object of the boss
    Employee * e_employee=getPointer(id); //object of the provided id
    if(Employee_Data.find(id)==Employee_Data.end()){ //if the id cannot be found in the map
        output << "Error. " << id << " not found."<< std::endl;
    }
    else{
        if(e_employee && e_employee->boss_==nullptr){ //if the id does not have a boss, it also does not have colleagues.
            output << id << " has no colleagues." <<std::endl;
        }
        if(e_employee && e_employee->boss_){ //if the id has a boss, initialize the boss's object
            boss=e_employee->boss_->id_;
            e_boss = e_employee->boss_;
        }

        if(e_boss){ //if the boss exist
            for(unsigned int i=0;i<e_boss->subordinates_.size();i++){
                if(e_boss->subordinates_[i]->id_==id) continue; //ignore the subordinate equal to the provided id
                else n++; //else the number of colleagues increase
            }
            if(n==0) output << id << " has no colleagues." <<std::endl; //if number of colleagues is 0
            else{
                output <<id<<" has "<< n <<" colleagues: "<<std::endl;
                for(unsigned int i=0;i<e_boss->subordinates_.size();i++){
                    if( e_boss->subordinates_[i]->id_==id) continue;
                    else output<<e_boss->subordinates_[i]->id_ <<std::endl; //print the id's colleagues apart from itself
                }
            }
        }
    }
}

void Company::printDepartment(const std::string& id,
                     std::ostream& output) const{

    std::string department;  //department of the id
    std::string boss; //biggest boss of the id with the same department and in same hierachy
    Employee *e_employee=getPointer(id); //object of the id
    if(Employee_Data.find(id)==Employee_Data.end()){ // if the id cannot be found in the map, return error
        output << "Error. " << id << " not found."<< std::endl;
    }
    else{
        department=e_employee->department_;  //initialize the department

        if(e_employee && e_employee->boss_==nullptr) {  //if id does not have a boss, it also does not have colleagues
            output << id << " has no department colleagues." <<std::endl;
        }
        else{
            Employee * e_boss=getPointer(id);
            while(e_boss->boss_ ){ //if the id's boss pointer is not null, it will become the boss
                e_boss=e_boss->boss_;
            }
            boss=e_boss->id_;// continue until it reached the highest boss

            std::vector <std::string> department_partner;  //vector stores the id's department colleagues
            if(boss!=id && e_boss->department_==department) department_partner.push_back(boss); //if the biggest boss is in the same department, push it to the vector
            recursive_department(boss,department,department_partner);  //invoke the ultility function to add the hierachy to the vector, from the biggest boss to bottom
            for(unsigned int i=0;i<department_partner.size();i++){  //delete the id provided inside the vector if there are any
                if(department_partner[i]==id) {
                    department_partner.erase(department_partner.begin()+i);
                }
            }
            std::set<std::string> set_department(department_partner.begin(), department_partner.end()); //put the vector inside the set for sorting alphabetically

            if(department_partner.size()==0) output << id << " has no department colleagues." <<std::endl; //if the size of the vector is 0; id does not have any department colleagues
            else{ //if not , print the content inside the set

                output <<id<<" has "<<department_partner.size()<<" department colleagues: "<<std::endl;
                for(auto i:set_department){
                     output<<i <<std::endl;
                }
            }
        }
    }
}
void Company::recursive_department(const std::string& id,const std::string& department,std::vector<std::string> &department_partner) const{
    Employee * e_boss= getPointer(id); //creat the id's object
    if(e_boss->subordinates_.size()!=0){ //if the id's subordinate is not empty
        for(unsigned int i=0;i<e_boss->subordinates_.size();i++){
            if(e_boss->subordinates_[i]->department_==department){ //if the subordinate's department is the same as the id's
                department_partner.push_back(e_boss->subordinates_[i]->id_); //push its id to the vector
                recursive_department(e_boss->subordinates_[i]->id_,department,department_partner); //recursive for the subordinate's subordinates if it has any
            }
        }
    }
}
void Company::printLongestTimeInLineManagement(const std::string& id,
                                      std::ostream& output) const{
    if(Employee_Data.find(id)==Employee_Data.end()) output << "Error. " <<id << " not found."<<std::endl;
    else {
        Employee * e_boss=getPointer(id); //creat object of id
        int max; //max time of service variable
        std::string max_subordinate;  //person with highest time of service
        if(e_boss->subordinates_.size()==0){ //if id is a boss and it does not have subordinates , then it is the highest time of service in its line management
            max=e_boss->time_in_service_;
            max_subordinate=id;
            output<< "With the time of " << max << ", " << max_subordinate << " is the longest-served employee in their line management."<<std::endl;
        }
        else{
            max=e_boss->subordinates_[0]->time_in_service_;  //set the max time of service to the 1st subordinate
            max_subordinate=e_boss->subordinates_[0]->id_; //set the max time of service 's id to the 1st subordinate
            if(max<e_boss->time_in_service_) { //if the boss has highest time of service, change max and max_subordinate to the boss's info
                max=e_boss->time_in_service_;
                max_subordinate=id;
            }

            for(unsigned int i=0;i<e_boss->subordinates_.size();i++){
                if(max<e_boss->subordinates_[i]->time_in_service_) {  //if there are any subordinates having higher time of service, change max and max_surbodinate to that subordinate's info
                    max=e_boss->subordinates_[i]->time_in_service_;
                    max_subordinate=e_boss->subordinates_[i]->id_;
                }
            }
            if(max_subordinate==id) output<< "With the time of " << max << ", " << max_subordinate << " is the longest-served employee in their line management."<<std::endl;
            else output<< "With the time of " << max << ", " << max_subordinate << " is the longest-served employee in "<< id << "'s line management."<<std::endl;
        }
    }
}

void Company::printShortestTimeInLineManagement(const std::string& id,
                                       std::ostream& output) const{
    if(Employee_Data.find(id)==Employee_Data.end()) output << "Error. " <<id << " not found."<<std::endl;
    else{
        Employee * e_boss=getPointer(id);
        int min;
        std::string min_subordinate;
        if(e_boss->subordinates_.size()==0){
            min=e_boss->time_in_service_;
            min_subordinate=id;
            output<< "With the time of " << min << ", " << min_subordinate << " is the shortest-served employee in their line management."<<std::endl;
        }
        else{
            min=e_boss->subordinates_[0]->time_in_service_;
            min_subordinate=e_boss->subordinates_[0]->id_;
            if(min>e_boss->time_in_service_) {
                min=e_boss->time_in_service_;
                min_subordinate=id;
            }

            for(unsigned int i=0;i<e_boss->subordinates_.size();i++){
                if(min>e_boss->subordinates_[i]->time_in_service_) {
                    min=e_boss->subordinates_[i]->time_in_service_;
                    min_subordinate=e_boss->subordinates_[i]->id_;
                }
            }
            if(min_subordinate==id) output<< "With the time of " << min << ", " << min_subordinate << " is the shortest-served employee in their line management."<<std::endl;
            else output<< "With the time of " << min << ", " << min_subordinate << " is the shortest-served employee in "<< id << "'s line management."<<std::endl;
        }
    }
}


void Company::printBossesN(const std::string& id, const int n,
                  std::ostream& output) const{
    if(Employee_Data.find(id)==Employee_Data.end()) output << "Error. " <<id << " not found."<<std::endl;
    if(output) {
        output<< n<< std::endl;
    }
}

void Company::printSubordinatesN(const std::string& id, const int n,
                        std::ostream& output) const{
    if(Employee_Data.find(id)==Employee_Data.end()) output << "Error. " <<id << " not found."<<std::endl;
    if(output) {
        output<< n<< std::endl;
    }
}
Employee* Company::getPointer(const std::string& id) const {
    if(Employee_Data.find(id)!=Employee_Data.end()){
        return Employee_Data.at(id);
    }
    return nullptr;
}
