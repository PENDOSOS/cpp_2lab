#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Constants.h"
#include "Teacher.h"
#include "Student.h"

class goodStudent : public Student
{
public:
	const vector<vector<double>> solveAndSend()
	{
		vector<vector<double>> roots;
		FILE* fin;
		fin = fopen("tasks.txt", "r");
		for (int i = 0; i < COUNT; i++)
			roots.push_back(solveEquation(fin));
		fclose(fin);
		return roots;
	}
};

class normalStudent : public Student
{
public:
	const vector<vector<double>> solveAndSend()
	{
		srand(time(0));
		vector<vector<double>> roots;
		FILE* fin;
		fin = fopen("tasks.txt", "r");
		for (int i = 0; i < COUNT; i++)
		{
			int successPercent = 1 + rand() % 100;
			if ((successPercent >= 1 && successPercent <= 20) || (successPercent <= 100 && successPercent >= 90))
			{
				double buff;
				for (int j = 0; j < 3; j++)
				{
					fscanf(fin, "%lf", &buff);
				}
				double a = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
				double b = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
				roots.push_back({ a, b });
			}
			else
				roots.push_back(solveEquation(fin));
		}
		fclose(fin);
		return roots;
	}
};

class badStudent
{
public:
	const vector<vector<double>> solveAndSend()
	{
		vector<vector<double>> roots;
		for (int i = 0; i < COUNT; i++)
		{
			roots.push_back({ 0 });
		}
		return roots;
	}
};

int main()
{
	badStudent Petya;
	goodStudent Masha;
	normalStudent Vanya;

	Teacher Jonathan;

	Jonathan.generateTasks();

	Jonathan.check(Petya.solveAndSend(), "Petya");
	Jonathan.check(Masha.solveAndSend(), "Masha");
	Jonathan.check(Vanya.solveAndSend(), "Vanya");

	Jonathan.printTable();

	return 0;
}