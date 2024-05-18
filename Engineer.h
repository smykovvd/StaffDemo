#pragma once
#include "Personal.h"
#include "Interfaces.h"
#include "Project.h"
#include <vector>

class Engineer : public Personal, public ProjectBudget {
protected:
	Project* project;
public:
	Engineer(int id, std::string name, Positions position,
		float worktime, int salary, Project* project);
	Project* getProject();
	int calcBudgetPart() override;
	virtual void calc() override;
};

class Tester : public Engineer {
 protected:
	 int countOfBags = 0;
	 int costOfBag = 0;
 public:
	 Tester(int id, std::string name, Positions position,
		 float worktime, int salary, Project* project);
	 void setCountOfBags(int bags);
	 void setCostOfBag(int cost);
	 int calcProAdditions() override;
	 void calc() override;
	 void printInfo() override;
};

class Programmer : public Engineer {
protected:
	bool beforeSchedule = false;
	int bonusIfEarlier = 0;
public:
	Programmer(int id, std::string name, Positions position,
		float worktime, int salary, Project* project);
	void setBeforeScgedule(bool ok);
	void setBonusIfEarlier(int bonus);
	int calcProAdditions() override;
	virtual void calc() override;
	virtual void printInfo() override;
};

class TeamLeader : public Programmer, public Heading {
protected:
	std::vector<Engineer*> workers;
	int paymentForWorker = 0;
public:
	TeamLeader(int id, std::string name, Positions position,
		float worktime, int salary, Project* project);
	void pushEmployee(Engineer* emp);
	void setPaymentForWorker(int payment);
	int calcHeads() override;
	void calc() override;
	void printInfo() override;
};