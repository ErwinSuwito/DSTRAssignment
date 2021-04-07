#pragma once
#include <iostream>
#include <ctime>
#include "Pet.h"
using namespace std;

class Purchase
{
public:
	string purchaseId, custName, custPhNo, custEmail;
	double totalAmount;
	char* purchaseTimeStamp;
	Purchase* next;
	Pet* pets;
};

