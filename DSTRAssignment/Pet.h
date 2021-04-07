#pragma once
#include <iostream>
using namespace std;

class Pet
{
public:
	string assetCode, petType, species, coatColor;
	double price;
	Pet* next;
	Pet* prev;
};

