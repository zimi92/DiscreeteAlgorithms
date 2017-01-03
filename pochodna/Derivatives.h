#pragma once
#include <iostream>
#include <vector>
class Derivatives
{
std::vector <double> function[2];
std::vector <double> derivative;
//std::vector <double> derivativeDouble;
//std::vector <double> trueDerivative;
//std::vector <double> fifthPointDerivative;
int m_amountOfSamples;
double m_h;
double m_startPoint;
public:

	Derivatives(int amountOfSamples, double h, double startPoint);
	~Derivatives();
private:

};

