#pragma once
#include "Employee.h"
#include <string>
#include <vector>


class Project {
protected:
	std::string name;
	int budget;
	std::vector<Employee*> staff;
	int countOfWorkers = 0;
public:
	Project(std::string name, int budget, int len);

	int getBudget();

	std::string getName();

	int getCountOfWorkers();

	void pushEmployee(Employee * emp);
};