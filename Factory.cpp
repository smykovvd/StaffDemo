#include "Factory.h"
void FactoryStaff::makeProject() {
	std::fstream sp("bd/projects.txt");
	std::string name;
	int budget, len;

	while (sp >> name) {
		sp >> budget >> len;
		Project* pr = new Project(name, budget, len);
		projects.push_back(pr);
	}
}
void FactoryStaff::makeStaff() {
	makeProject();
	int id, workTime;
	std::string firstname, fathername, surname, name, pos;
	std::fstream ss("bd/staff.txt");
	while (ss >> id) {
		ss >> firstname >> fathername >> surname >> pos >> workTime;
		name = firstname + " " + fathername + " " + surname;

		if (pos == "cleaner") {
			int salary;
			ss >> salary;
			Cleaner* emp = new Cleaner(id, name, cleaner, workTime, salary);
			staff.push_back(emp);
			continue;
		}
		if (pos == "driver") {
			int salary;
			ss >> salary;
			Driver* emp = new Driver(id, name, driver, workTime, salary);
			staff.push_back(emp);
			continue;
		}
		if (pos == "tester") {
			int salary;
			std::string proj;
			ss >> salary >> proj;
			Project* project = nullptr;
			for (Project* a : projects)
				if (a->getName() == proj) {
					project = a;
					break;
				}
			Tester* emp = new Tester(id, name, tester, workTime, salary, project);
			project->pushEmployee(emp);
			staff.push_back(emp);
			continue;
		}
		if (pos == "programmer") {
			int salary;
			std::string proj;
			ss >> salary >> proj;
			Project* project = nullptr;
			for (Project* a : projects)
				if (a->getName() == proj) {
					project = a;
					break;
				}
			Programmer* emp = new Programmer(id, name, programmer, workTime, salary, project);
			project->pushEmployee(emp);
			staff.push_back(emp);
			continue;
		}
		if (pos == "teamLeader") {
			int salary;
			std::string proj;
			ss >> salary >> proj;
			Project* project = nullptr;
			for (Project* a : projects)
				if (a->getName() == proj) {
					project = a;
					break;
				}
			TeamLeader* emp = new TeamLeader(id, name, teamLeader, workTime, salary, project);
			project->pushEmployee(emp);
			staff.push_back(emp);
			continue;
		}
		if (pos == "projectManager") {
			std::string proj;
			ss >> proj;
			Project* project = nullptr;
			for (Project* a : projects)
				if (a->getName() == proj) {
					project = a;
					break;
				}
			ProjectManager* emp = new ProjectManager(id, name, projectManager, workTime, { project });
			project->pushEmployee(emp);
			staff.push_back(emp);
			continue;
		}
		if (pos == "seniorManager") {
			int len;
			ss >> len;
			std::vector<Project*> proj;
			for (int i = 0; i < len; i++) {
				std::string pro;
				ss >> pro;
				Project* project = nullptr;
				for (Project* a : projects)
					if (a->getName() == pro) {
						project = a;
						break;
					}
				if (project != nullptr)
					proj.push_back(project);
			}
			SeniorManager* emp = new SeniorManager(id, name, seniorManager, workTime, proj, len);
			staff.push_back(emp);
			continue;
		}

	}
}