#pragma once
#include "Derivatives.h"
class Algorithm
{
public:
	int chooseAlgorithm(int choice);
	Algorithm();
	~Algorithm();
private:
	Derivatives derivatives;
};

