#include "Algorithm.h"



Algorithm::Algorithm()
{
}


Algorithm::~Algorithm()
{
}

int Algorithm::chooseAlgorithm(int choice) {
	switch (choice)
	{
	case 1:
		derivatives.runAlg();
		break;
	default:
		break;
	}
	return 0;
}