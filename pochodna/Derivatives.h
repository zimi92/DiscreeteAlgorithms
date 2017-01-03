#pragma once
#include <iostream>
#include <vector>
class Derivatives
{
public:
	Derivatives(int amountOfSamples, double h, double startPoint);
	~Derivatives();
	void setFunction();
	void calculateDerivative();
	void reportResults();
private:
	std::vector <double> function[2];
	std::vector <double> derivative;
	//std::vector <double> derivativeDouble;
	//std::vector <double> trueDerivative;
	//std::vector <double> fifthPointDerivative;
	int m_amountOfSamples;
	double m_h;
	double m_startPoint;

};

