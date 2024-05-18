#pragma once
#include "Project.h"

Project::Project(std::string name, int budget, int len) {
	this->name = name;
	this->budget = budget;
	staff.resize(len);
}

int Project::getBudget() {
	return this->budget;
}

std::string Project::getName() {
	return this->name;
}

int Project::getCountOfWorkers() {
	return this->countOfWorkers;
}

void Project::pushEmployee(Employee* emp){
	if (this->countOfWorkers == this->staff.size())
		staff.push_back(nullptr);
	this->staff[this->countOfWorkers++] = emp;
}
