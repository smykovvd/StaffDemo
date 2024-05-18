#include "Manager.h"

ProjectManager::ProjectManager(int id, std::string name, Positions position,
	float workTime, std::vector<Project*>project, int len):
	 Employee(id,name,position, workTime){
	projects.resize(len);
	int i = 0;
	while ( i<this->projects.size()){
		this->projects[i] = project[i];
		i++;
	}
}

void ProjectManager::setPaymentForWorker(int payment){
	this->paymentForWorker = payment;
}

int ProjectManager::calcBudgetPart(){
	int sum = 0;
	for (Project* a : this->projects)
		sum += a->getBudget()/(a->getCountOfWorkers()+1);
	return sum;
}

int ProjectManager::calcHeads(){
	int sum = 0;
	for (Project* a : projects)
		sum += (a->getCountOfWorkers()-1);
	return sum * this->paymentForWorker;
}

void ProjectManager::calc(){
	this->payment = calcBudgetPart() + calcHeads() + calcBudgetPart();
}

void ProjectManager::printInfo(){
	std::cout << "\n-------";
	std::cout << "\n  ID - " << this->id;
	std::cout << "\n    NAME - " << this->name;
	std::cout << "\n    POSITION - " << printPosition[this->position];
	std::cout << "\n    NAME OF PROJECT - " << this->projects[0]->getName();
	std::cout << "\n    COUNT OF WORKERS - " << this->projects[0]->getCountOfWorkers();
	std::cout << "\n    PAYMENT - " << this->payment;
	std::cout << "\n-------";
	std::cout << std::endl;
}

SeniorManager::SeniorManager(int id, std::string name, Positions position, 
	float workTime, std::vector<Project*> project, int len):
	ProjectManager(id, name, position, workTime, project, len){}

int SeniorManager::calcBudgetPart() {
	int sum = 0;
	for (Project* a : projects)
		sum += (a->getCountOfWorkers());
	return sum * this->paymentForWorker;

}

void SeniorManager::printInfo(){
	int sum = 0;
	for (Project* a : this->projects)
		sum += a->getCountOfWorkers();
	std::cout << "\n-------";
	std::cout << "\n  ID - " << this->id;
	std::cout << "\n    NAME - " << this->name;
	std::cout << "\n    POSITION - " << printPosition[this->position];
	std::cout << "\n    COUNT OF PROJECTS - " << this->projects.size();
	std::cout << "\n    NAMES OF PROJECTS - ";
	for (Project* a : this->projects)
		std::cout << a->getName() << " ";
	std::cout << "\n    COUNT OF WORKERS - " << sum;
	std::cout << "\n    PAYMENT - " << this->payment;
	std::cout << "\n-------";
	std::cout << std::endl;
}
