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
