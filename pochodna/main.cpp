#include <iostream>
#include <vector>
#include "Derivatives.h"
int main() {
	Derivatives der(110, 0.01, 0);
	der.setFunction();
	der.calculateDerivative();
	der.reportResults();
	getchar();
	getchar();


	return 0;
}