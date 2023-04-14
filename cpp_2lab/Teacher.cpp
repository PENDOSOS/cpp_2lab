#define _CRT_SECURE_NO_WARNINGS

#include "Constants.h"
#include "Teacher.h"

//using namespace std;

struct Teacher::Table;

void Teacher::check(const vector<vector<double>>& answers, const string& name)
{
	Table student;
	student.name = name;
	FILE* fin;
	fin = fopen("tasks.txt", "r");
	for (int i = 0; i < COUNT; i++)
	{
		if (answers[i].size() == 2)
		{
			if (checkRoot(fin, answers[i]))
			{
				student.right_answers += 1;
			}
		}
		else if (answers[i].size() == 1)
		{
			if (checkRoot(fin, answers[i]))
				student.right_answers += 1;
		}
		else if (answers[i].size() == 0)
		{
			double a, b, c, discriminant;
			fscanf(fin, "%lf", &a);
			fscanf(fin, "%lf", &b);
			fscanf(fin, "%lf", &c);
			discriminant = b * b - 4 * a * c;
			if (discriminant < 0)
				student.right_answers += 1;
		}
	}
	fclose(fin);
	table.push_back(student);
}

void Teacher::printTable()
{
	cout << "----------RESULTS----------" << endl;
	for (int i = 0; i < table.size(); i++)
		cout << table[i].name << " solved " << table[i].right_answers << " of " << COUNT << endl;
}

void Teacher::generateTasks()
{
	double a;
	double b;
	double c;
	srand(time(0));
	int count_of_zeros = 1 + rand() % 10;
	ofstream fout("tasks.txt");
	for (int i = 0; i < COUNT; i++)
	{
		if (i <= count_of_zeros & i >= 0)
		{
			b = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
			fout << 0 << " " << b << " " << 0 << endl;
		}
		else
		{
			a = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
			b = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
			c = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
			fout << a << " " << b << " " << c << endl;
		}
	}
}

bool Teacher::checkRoot(FILE* fin, const vector<double>& roots)
{
	double a, b, c;
	fscanf(fin, "%lf", &a);
	fscanf(fin, "%lf", &b);
	fscanf(fin, "%lf", &c);
	double left_1 = a * roots[0] * roots[0] + b * roots[0] + c;
	if (roots.size() == 2)
	{
		double left_2 = a * roots[1] * roots[1] + b * roots[1] + c;
		return ((left_1 <= EPSILON) && (left_1 >= -EPSILON) && (left_2 <= EPSILON) && (left_2 >= -EPSILON));
	}
	else
		return (a * roots[0] * roots[0] + b * roots[0] + c == 0);
}