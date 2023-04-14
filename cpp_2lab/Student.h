#pragma once

#include "Constants.h"

class Student
{
public:
	const vector<double> solveEquation(FILE* fin);
	
private:
	const vector<double> readCoefs(FILE* fin);

	const double findDiscriminant(const vector<double>& coefs);

	const vector<double> findRoots(const double& a, const double& b, const double& c, const double& discriminant);

	void writeRoots(const vector<double>& roots);
};