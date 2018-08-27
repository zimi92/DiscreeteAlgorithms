#include "Algorithm.h"

AlgorithmChoices::AlgorithmChoices()
{
}


AlgorithmChoices::~AlgorithmChoices()
{
}

int AlgorithmChoices::chooseAlgorithm(AlgorithmName choice) {
	switch (choice)
	{
	case AlgorithmName::derivative:
		derivatives.runAlg();
		break;
	default:
		break;
	}
	return 0;
}