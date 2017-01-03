#include "Derivatives.h"



Derivatives::Derivatives(int amountOfSamples, double h, double startPoint) : m_amountOfSamples(amountOfSamples), m_h(h), m_startPoint(startPoint) {
	double xDim = 0;
	for (int i = 0; i < amountOfSamples; i++) {
		function[0].push_back(xDim += h);
		function[1].push_back(0);
		derivative.push_back(0);
	}
}


Derivatives::~Derivatives()
{
}
