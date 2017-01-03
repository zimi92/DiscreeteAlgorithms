#include <iostream>
#include <vector>

int main() {
	std::vector <double> function[2];
	std::vector <double> derivative;
	std::vector <double> derivativeDouble;
	std::vector <double> trueDerivative;
	std::vector <double> fifthPointDerivative;
	int amountOfSample =	40;
	double skip =			0.01;
	double beggining =		0;
	for (int i = 0; i < amountOfSample; i++) {
		function[0].push_back		(beggining);
		function[1].push_back		(3*beggining*beggining * beggining + beggining*beggining + 4*beggining);
		trueDerivative.push_back	(9*beggining*beggining + 2*beggining + 4);
		beggining += skip;
	}
	derivative.push_back(0);
	for (int i = 2; i < amountOfSample-2; i++) {
		derivative.push_back			((function[1][i] - function[1][i - 1]) / skip);
		derivativeDouble.push_back		((function[1][i+1] - function[1][i - 1]) / (2*skip));
		fifthPointDerivative.push_back	((function[1][i - 2] - (8 * function[1][i - 1]) + (8 * function[1][i + 1]) - function[1][i + 2]) / (12 * skip));
	}
	double devError		= 0;
	double doubleError	= 0;
	double fifthError	= 0;
	for (int i = 0; i < amountOfSample-4; i++) {
		devError +=		((trueDerivative[i] - derivative[i]) > 0) ? (trueDerivative[i] - derivative[i]) : (derivative[i] - trueDerivative[i]);
		doubleError +=	((trueDerivative[i] - derivativeDouble[i]) > 0) ? (trueDerivative[i] - derivativeDouble[i]) : (derivativeDouble[i] - trueDerivative[i]);
		fifthError +=	((trueDerivative[i] - fifthPointDerivative[i]) > 0) ? (trueDerivative[i] - fifthPointDerivative[i]) : (fifthPointDerivative[i] - trueDerivative[i]);

		std::cout << function[0][i]				<< ",";
		std::cout << function[1][i]				<< ",";
		std::cout << trueDerivative[i]			<< ",";
		std::cout << derivativeDouble[i]		<< ",";
		std::cout << derivative[i]				<< ",";
		std::cout << fifthPointDerivative[i]	<< std::endl;
	}
	std::cout << "sigle Forward derivative error: "	 << devError << std::endl;
	std::cout << "double derivative error: "		 << doubleError << std::endl;
	std::cout << "fifth point derivative error: "	 << fifthError << std::endl;

	getchar();
	return 0;
}