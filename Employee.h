#pragma once
#include <string>

enum Positions {
	cleaner,
	driver,
	programmer,
	tester,
	teamLeader,
	projectManager,
	seniorManager
};

class Employee {
 protected:
	 int id;
	 std::string name;
	 Positions position;
	 float workTime;
	 float payment = 0;
	 std::string printPosition[7] = {"cleaner", "driver", "programmer",
	 "tester",  "teamLeader", "projectManager", "seniorManager"};
 public:
	 Employee(int id, std::string name, Positions position,float workTime);
	 void setWorkTime(float workTime);
	 Positions getPosition();
	 virtual void calc() = 0;
	 virtual void printInfo() = 0;
};