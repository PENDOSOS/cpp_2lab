#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Constants.h"
#include "Teacher.h"
#include "Solver.h"

class GoodStudent : public Solver
{
};

class NormalStudent : public Solver
{
public:
	void findRoots() override
	{
		srand(time(0));
		for (int i = 0; i < COUNT; i++)
		{
			int successPercent = 1 + rand() % 100;
			if ((successPercent >= 1 && successPercent <= 20) || (successPercent <= 100 && successPercent >= 90))
			{
				double a = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
				double b = (double)rand() / (double)RAND_MAX * (SUPREMUM - INFIMUM) + INFIMUM;
				roots.push_back({ a, b });
			}
			else
			{
				vector<double> buff;
				if (discriminants[i] > 0)
				{
					if (discriminants[i] == 0)
					{
						buff.push_back(coefs[i][1] * coefs[i][1] / (2 * coefs[i][0]));
					}
					else if (coefs[i][0] == 0)
					{
						buff.push_back(-coefs[i][2] / coefs[i][1]);
					}
					else
					{
						buff.push_back((-coefs[i][1] - sqrt(discriminants[i])) / (2 * coefs[i][0]));
						buff.push_back((-coefs[i][1] + sqrt(discriminants[i])) / (2 * coefs[i][0]));
					}
				}
				else
					buff = {};
				roots.push_back(buff);
			}
		}
	}
};

class BadStudent : public Solver
{
public:
	void findRoots() override
	{
		for (int i = 0; i < COUNT; i++)
		{
			roots.push_back({ 0 });
		}
	}
};

int main()
{
	BadStudent Petya;
	GoodStudent Masha;
	NormalStudent Vanya;

	Teacher Jonathan;

	Jonathan.generateTasks();

	Masha.readCoefs();
	Masha.findDiscriminant();
	Masha.findRoots();

	Vanya.readCoefs();
	Vanya.findDiscriminant();
	Vanya.findRoots();

	Petya.readCoefs();
	Petya.findDiscriminant();
	Petya.findRoots();

	Jonathan.check(Petya.sendAnswers(), "Petya");
	Jonathan.check(Masha.sendAnswers(), "Masha");
	Jonathan.check(Vanya.sendAnswers(), "Vanya");

	Jonathan.printTable();

	return 0;
}