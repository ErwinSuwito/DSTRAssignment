#pragma once
#include <iostream>
#include "Pet.h"
using namespace std;

class Purchase
{
	string purchaseId, custName, custPhNo, custEmail;
	Purchase* next;
	Pet* purchases;
};

