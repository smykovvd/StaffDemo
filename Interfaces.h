#pragma once

class WorkBaseTime {
public:
	virtual int calcBase() = 0;

	virtual int calcBonus() {
		return 0;
	}
};

class ProjectBudget {
 public:
	 virtual int calcBudgetPart() = 0;

	 virtual int calcProAdditions() {
		 return 0;
	 }
};

class Heading {
 public:
	 virtual int calcHeads() = 0;
};