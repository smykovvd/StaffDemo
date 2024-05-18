#include "Factory.h"
#include <string>
#include <vector>

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	FactoryStaff st;
	st.makeStaff();
	std::cout << st.staff.size() << "\n";
	for (Project* pr : st.projects)
		std::cout << pr->getName() << " " << pr->getCountOfWorkers() << " " << pr->getBudget() << "\n";
	std::cout << "\n";

	for (Employee* emp : st.staff)
		emp->calc();

	for (Employee* emp : st.staff)
		emp->printInfo();

	for (Employee* emp : st.staff) {
		if (emp->getPosition() == driver) {
			Driver* D = dynamic_cast<Driver*>(emp);
			D->setNightHours(rand()%100);
		}
		if (emp->getPosition() == programmer) {
			Programmer* P = dynamic_cast<Programmer*>(emp);
			P->setBeforeScgedule(rand() % 2);
			P->setBonusIfEarlier(rand());
		}
		if (emp->getPosition() == tester) {
			Tester* T = dynamic_cast<Tester*>(emp);
			T->setCostOfBag(rand()%1000);
			T->setCountOfBags(rand()%100);
		}
		if (emp->getPosition() == teamLeader) {
			TeamLeader* TL = dynamic_cast<TeamLeader*>(emp);
			for (Employee* empl : st.staff) {
				bool ok = rand() % 2;
				if (empl->getPosition() == programmer && ok)
					TL->pushEmployee(dynamic_cast<Programmer*>(empl));
				if (empl->getPosition() == tester && ok)
					TL->pushEmployee(dynamic_cast<Tester*>(empl));
			}
			TL->setPaymentForWorker(rand());
		}
		if (emp->getPosition() == projectManager) {
			ProjectManager*  PM= dynamic_cast<ProjectManager*>(emp);
			PM->setPaymentForWorker(rand());
		}
		if (emp->getPosition() == seniorManager) {
			SeniorManager* SM = dynamic_cast<SeniorManager*>(emp);
			SM->setPaymentForWorker(rand()%10000);
		}
	}
	std::cout << "\n\n\nAFTER SETTING OTHER RANDOM FEATURES \n\n\n";

	for (Employee* emp : st.staff)
		emp->calc();

	for (Employee* emp : st.staff)
		emp->printInfo();

	return 0;
}