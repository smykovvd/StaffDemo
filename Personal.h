#pragma once
#include <iostream>
#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, public WorkBaseTime {
 protected:
	 int salary;
 public:
	 Personal(int id, std::string name, Positions position, 
		 float workTime, int salary);
	 int calcBase() override;
};

class Cleaner: public Personal {
 public: 
	 Cleaner(int id, std::string name, Positions position,
		 float workTime, int salary);
	 void calc() override;
	 void printInfo() override;
};

class Driver: public Personal{
protected:
	float nightHours = 0;
 public:
	 Driver(int id, std::string name, Positions position,
		 float workTime, int salary);
	 void setNightHours(int hours);
	 int calcBonus() override;
	 void calc() override;
	 void printInfo() override;
 };
