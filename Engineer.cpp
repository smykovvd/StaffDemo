#include "Engineer.h"

Engineer::Engineer(int id, std::string name, Positions position, 
	float worktime, int salary, Project* project): 
	 Personal(id,name, position,worktime, salary){
	this->project = project;
}

Project* Engineer::getProject(){
	return this->project;
}

int Engineer::calcBudgetPart(){
	return  this->project->getBudget()/(this->project->getCountOfWorkers()+1);
}

void Engineer::calc(){
	this->payment = calcBase() + calcBudgetPart();
}

Tester::Tester(int id, std::string name, Positions position,
	float worktime, int salary, Project* project):
	 Engineer(id,name, position, worktime, salary, project){}

void Tester::setCountOfBags(int bags){
	this->countOfBags = bags;
}

void Tester::setCostOfBag(int cost){
	this->costOfBag = cost;
}

int Tester::calcProAdditions(){
	return this->countOfBags * this->costOfBag;
}

void Tester::calc(){
	this->payment = calcBase() + calcBudgetPart() + calcProAdditions();
}

void Tester::printInfo(){
	std::cout << "\n-------";
	std::cout << "\n  ID - " << this->id;
	std::cout << "\n    NAME - " << this->name;
	std::cout << "\n    POSITION - " << printPosition[this->position];
	std::cout << "\n    NAME OF PROJECT - " << this->project->getName();
	std::cout << "\n    SALARY - " << this->salary;
	std::cout << "\n    COUNT OF BAGS - " << this->countOfBags;
	std::cout << "\n    PAYMENT - " << this->payment;
	std::cout << "\n-------";
	std::cout << std::endl;
}

Programmer::Programmer(int id, std::string name, Positions position,
	float worktime, int salary, Project* project):
	 Engineer(id, name, position, worktime, salary, project) {}

void Programmer::setBeforeScgedule(bool ok) {
	this->beforeSchedule = ok;
}

void Programmer::setBonusIfEarlier(int bonus){
	this->bonusIfEarlier = bonus;
}

int Programmer::calcProAdditions(){
	return this->beforeSchedule * this->bonusIfEarlier;
}

void Programmer::calc(){
	this->payment = calcBase() + calcBudgetPart() + calcProAdditions();
}

void Programmer::printInfo(){
	std::cout << "\n-------";
	std::cout << "\n  ID - " << this->id;
	std::cout << "\n    NAME - " << this->name;
	std::cout << "\n    POSITION - " << printPosition[this->position];
	std::cout << "\n    NAME OF PROJECT - " << this->project->getName();
	std::cout << "\n    SALARY - " << this->salary;
	std::cout << "\n    BONUS FOR EFFECTIVE WORK - " << this->bonusIfEarlier;
	std::cout << "\n    PAYMENT - " << this->payment;
	std::cout << "\n-------";
	std::cout << std::endl;
}

TeamLeader::TeamLeader(int id, std::string name, Positions position,
	float worktime, int salary, Project* project) :
	Programmer(id, name, position, worktime, salary, project) {}

void TeamLeader::pushEmployee(Engineer* emp){
	if (emp->getProject() == this->project && emp!=this)
		this->workers.push_back(emp);
}

void TeamLeader::setPaymentForWorker(int payment){
	this->paymentForWorker = payment;
}

int TeamLeader::calcHeads(){
	return this->workers.size() * this->paymentForWorker;
}

void TeamLeader::calc(){
	this->payment = calcBase() + calcBudgetPart() + calcHeads();
}

void TeamLeader::printInfo(){
	std::cout << "\n-------";
	std::cout << "\n  ID - " << this->id;
	std::cout << "\n    NAME - " << this->name;
	std::cout << "\n    POSITION - " << printPosition[this->position];
	std::cout << "\n    NAME OF PROJECT - " << this->project->getName();
	std::cout << "\n    SALARY - " << this->salary;
	std::cout << "\n    COUNT OF WOKKERS IN A TEAM - " << this->workers.size();
	std::cout << "\n    PAYMENT - " << this->payment;
	std::cout << "\n-------";
	std::cout << std::endl;
}






