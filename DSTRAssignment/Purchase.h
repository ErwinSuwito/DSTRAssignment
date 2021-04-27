#pragma once
#include <iostream>
#include <ctime>
#include "Pet.h"
using namespace std;

class Purchase
{
public:
	int purchaseId;
	string custName, custPhNo, custEmail;
	double totalAmount = 0;
	string purchaseTimeStamp;
	Purchase* next = NULL;
	Pet* pets = NULL;
};

