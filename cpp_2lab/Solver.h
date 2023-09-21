#pragma once

#include "Constants.h"

class Solver
{
public:
	vector<vector<double>> coefs;

	vector<vector<double>> roots;

	vector<double> discriminants;

	vector<vector<double>> const sendAnswers();

	void readCoefs();

	void findDiscriminant();

	virtual void findRoots() = 0;

	Solver() {	}

	virtual ~Solver() {	}
};