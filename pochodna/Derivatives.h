#pragma once
#include <iostream>
#include <vector>
class Derivatives
{
public:
	Derivatives(int amountOfSamples = 104, double h = 0.01, double startPoint = 0);
	~Derivatives();
	int runAlg();
private:
	void setFunction();
	void calculateDerivative();
	void reportResults();
	std::vector <double> function[2];
	std::vector <double> derivative;
	//std::vector <double> derivativeDouble;
	//std::vector <double> trueDerivative;
	//std::vector <double> fifthPointDerivative;
	int m_amountOfSamples;
	double m_h;
	double m_startPoint;

};

