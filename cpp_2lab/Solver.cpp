#define _CRT_SECURE_NO_WARNINGS

#include "Constants.h"
#include "Solver.h"

const vector<vector<double>> Solver::sendAnswers()
{
	return roots;
}

void Solver::readCoefs()
{
	ifstream fin("tasks.txt");
	for (int i = 0; i < COUNT; i++)
	{
		vector<double> buff;
		for (int j = 0; j < 3; j++)
		{
			double temp;
			fin >> temp;
			buff.push_back(temp);
			
		}
		coefs.push_back(buff);
	}
}

void Solver::findDiscriminant()
{
	for (int i = 0; i < COUNT; i++)
	{
		discriminants.push_back(coefs[i][1] * coefs[i][1] - 4 * coefs[i][0] * coefs[i][2]);
	}
}

 void Solver::findRoots()
{
	for (int i = 0; i < COUNT; i++)
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

