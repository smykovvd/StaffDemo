#pragma once
#include "Project.h"
#include "Engineer.h"
#include "Manager.h"
#include <fstream>
#include <vector>

class FactoryStaff {
public:
	std::vector<Project* > projects;
	std::vector<Employee* > staff;
	void makeProject();
	void makeStaff();
};

