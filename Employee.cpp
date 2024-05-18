#include "Employee.h"

Employee::Employee(int id, std::string name, Positions position, float workTime){
	this->id = id;
	this->name = name;
	this->position = position;
	this->workTime = workTime;
}

void Employee::setWorkTime(float workTime){
	this->workTime = workTime;
}

Positions Employee::getPosition(){
	return this->position;
}
