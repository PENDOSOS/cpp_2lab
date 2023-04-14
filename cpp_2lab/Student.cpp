#define _CRT_SECURE_NO_WARNINGS

#include "Constants.h"
#include "Student.h"

const vector<double> Student::solveEquation(FILE* fin)
{
	const vector<double> coefs = readCoefs(fin);
	const double discriminant = findDiscriminant(coefs);
	if (discriminant >= 0)
	{
		vector<double> roots;
		roots = findRoots(coefs[0], coefs[1], coefs[2], discriminant);
		return roots;
	}
	else
	{
		return {};
	}
}

const vector<double> Student::readCoefs(FILE* fin)
{
	vector<double> coefs;
	double buff;

	for (int i = 0; i < 3; i++)
	{
		fscanf(fin, "%lf", &buff);
		coefs.push_back(buff);
	}

	return coefs;
}

const double Student::findDiscriminant(const vector<double>& coefs)
{
	return coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
}

const vector<double> Student::findRoots(const double& a, const double& b, const double& c, const double& discriminant)
{
	vector<double> roots;
	if (discriminant == 0)
	{
		roots.push_back(b * b / (2 * a));
		return roots;
	}
	else if (a == 0)
	{
		roots.push_back(-c / b);
		return roots;
	}
	else
	{
		roots.push_back((-b - sqrt(discriminant)) / (2 * a));
		roots.push_back((-b + sqrt(discriminant)) / (2 * a));
		return roots;
	}
}

void Student::writeRoots(const vector<double>& roots)
{
	ofstream fout("output.txt");
	for (int i = 0; i < roots.size(); i++)
	{
		cout << roots[i] << " ";
	}
	cout << endl;
	fout.close();
}