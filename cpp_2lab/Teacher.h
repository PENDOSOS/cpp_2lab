#pragma once

#include "Constants.h"

class Teacher
{
public:
	void check(const vector<vector<double>>& answers, const string& name);

	void printTable();

	void generateTasks();
private:
	struct Table
	{
		string name;

		int right_answers = 0;
	};
	
	vector<Table> table;

	bool checkRoot(FILE* fin, const vector<double>& roots);
};