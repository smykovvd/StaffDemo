#pragma once
#include "Project.h"
#include "Interfaces.h"
#include "Employee.h"
#include <iostream>
#include <vector>

class ProjectManager : public Employee, public Heading, public ProjectBudget {
protected:
	std::vector<Project*> projects = {nullptr};
	int paymentForWorker = 0;
public:
	ProjectManager(int id, std::string name, Positions position,
		float workTime, std::vector<Project*> project,int len =1);
	void setPaymentForWorker(int payment);
	virtual int calcBudgetPart() override;
	int calcHeads() override;
	void calc() override;
	virtual void printInfo() override;
};

class SeniorManager : public ProjectManager {
public:
	SeniorManager(int id, std::string name, Positions position,
		float workTime, std::vector<Project*> project, int len);
	int calcBudgetPart() override;
	void printInfo() override;

};