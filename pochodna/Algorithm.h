#pragma once
#include "Derivatives.h"
enum class AlgorithmName
{
	derivative,

};

class AlgorithmChoices
{
public:
	int chooseAlgorithm(AlgorithmName choice);
	AlgorithmChoices();
	~AlgorithmChoices();
private:
	Derivatives derivatives;
};

