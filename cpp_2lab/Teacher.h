#pragma once

#include "Constants.h"

class Teacher
{
public:
	void check(vector<vector<double>> const& answers, string const& name);

	void printTable();

	void generateTasks();
private:
	struct Table
	{
		string name;

		int right_answers = 0;
	};
	
	vector<Table> table;

	bool checkRoot(FILE* fin, vector<double> const& roots);
};