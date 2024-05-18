#include "Personal.h"

Personal::Personal(int id, std::string name, Positions position,
    float workTime,int salary):
     Employee(id, name, position, workTime) {
    this->salary = salary;
}

int Personal::calcBase(){
    return this->salary *  this->workTime;
}


Cleaner::Cleaner(int id, std::string name, Positions position,
    float workTime, int salary) :
     Personal(id, name, position, workTime, salary) {}

void Cleaner::calc(){
    this->payment = calcBase();
}

void Cleaner::printInfo() {
    std::cout << "\n-------";
    std::cout << "\n  ID - " << this->id;
    std::cout << "\n    NAME - " << this->name;
    std::cout << "\n    POSITION - " << printPosition[this->position];
    std::cout << "\n    SALARY - " << this->salary;
    std::cout << "\n    PAYMENT - " << this->payment;
    std::cout << "\n-------";
    std::cout << std::endl;

}

Driver::Driver(int id, std::string name, Positions position,
    float workTime, int salary):
     Personal(id, name, position, workTime, salary){}

void Driver::setNightHours(int hours){
    this->nightHours = hours;
}

int Driver::calcBonus(){
    return 2 * this->nightHours * this->salary;
}

void Driver::calc(){
    this->payment = calcBase() + calcBonus();
}

void Driver::printInfo(){
        std::cout << "\n-------";
        std::cout << "\n  ID - " << this->id;
        std::cout << "\n    NAME - " << this->name;
        std::cout << "\n    POSITION - " << printPosition[this->position];
        std::cout << "\n    SALARY - " << this->salary;
        std::cout << "\n    COUNT OF NIGHT HOURS - " << this->nightHours;
        std::cout << "\n    PAYMENT - " << this->payment;
        std::cout << "\n-------";
        std::cout << std::endl;
}

