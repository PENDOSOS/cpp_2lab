#pragma once

#include "Constants.h"

class Solver
{
public:
	vector<vector<double>> coefs;

	vector<vector<double>> roots;

	vector<double> discriminants;

	const vector<vector<double>> sendAnswers();

	void readCoefs();

	void findDiscriminant();

	virtual void findRoots();
};