#include "Derivatives.h"
#define NL "\n"


Derivatives::Derivatives(int amountOfSamples, double h, double startPoint) : m_amountOfSamples(amountOfSamples), m_h(h), m_startPoint(startPoint) {
	double xDim = 0;
	for (int i = 0; i < m_amountOfSamples; i++) {
		function[0].push_back(xDim);
		function[1].push_back(0);
		derivative.push_back(0);
		xDim += m_h;
	}
}


Derivatives::~Derivatives()
{
}

void Derivatives::setFunction() {
	double xDim = 0;
	printf("select function that you want to see a derivative of:" NL);
	printf("1. y = a * x + b"  NL);
	printf("2. y = a * x ^ 2 + b * x + c" NL);
	printf("3. y = a / x" NL);
	printf("4. set Your own values" NL);
	int choice = 0;
	std::cin >> choice;
	switch (choice)
	{
	case 1: {
		int a, b;
		printf("set a and b value" NL);
		std::cin >> a >> b;
		for (int i = 0; i < m_amountOfSamples; i++) {
			function[1][i] = (a * function[0][i] + b);
		}
		break;
	}
	case 2: {
		int a, b, c;
		printf("set a, b and c value" NL);
		std::cin >> a >> b >> c;
		for (int i = 0; i < m_amountOfSamples; i++) {
			function[1][i] = (a * function[0][i] * function[0][i] + b * function[0][i] + c);
		}
		break;
	}
	case 3: {
		int a;
		printf("set a value" NL);
		std::cin >> a;
		for (int i = 0; i < m_amountOfSamples; i++) {
			function[1][i] = (a / function[0][i]);
		}
		break;
	}
	case 4: {
		int numberOfValues = 0;
		printf("set how many samples:" NL);
		std::cin >> numberOfValues;
		m_amountOfSamples = numberOfValues-1;
		double sample = 0;
		for (int i = 0; i < numberOfValues; i++) {
			std::cin >> sample;
			function[1][i] = sample;
		}
	}
		break;
	default:
		break;
	
	}
}

void Derivatives::calculateDerivative(){
	printf("select derivative algorithm You want to use:" NL);
	printf("1. two points estimations O(h)" NL);
	printf("2. three points estimation O(2h)" NL);
	printf("3. five points estimation O(4h)" NL);
	int choice = 0;
	std::cin >> choice;
	switch (choice)
	{
	case 1: {
		for (int i = 1; i < m_amountOfSamples; i++) {
			derivative[i] = ((function[1][i] - function[1][i - 1]) / m_h);
		}
		break;
	}
	case 2: {
		for (int i = 1; i < m_amountOfSamples - 1; i++) {
			derivative[i] = ((function[1][i + 1] - function[1][i - 1]) / (2 * m_h));
		}
		break;
	}
	case 3: {
		for (int i = 2; i < m_amountOfSamples - 2; i++) {
			derivative[i] = ((function[1][i - 2] - (8 * function[1][i - 1]) + (8 * function[1][i + 1]) - function[1][i + 2]) / (12 * m_h));
		}
		break;
	}
	default:
		break;
	}
}

void Derivatives::reportResults() {
	printf("Choose how You want to display the results:" NL);
	printf("1. standard output (console)" NL);
	printf("2. xlsx file named results.xlsx in folder with the program" NL);
	int choice = 0;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		for (int i = 0; i < m_amountOfSamples; i++) {
			printf("%f, %f, %f\n", function[0][i], function[1][i], derivative[i]);
		}
		break;
	default:
		break;
	}
}

int Derivatives::runAlg() {
	setFunction();
	calculateDerivative();
	reportResults();
	return 0;
}