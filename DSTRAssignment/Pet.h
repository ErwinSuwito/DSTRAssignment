#pragma once
#include <iostream>
using namespace std;

class Pet
{
public:
	int petId;
	string petBreed, petColor;
	double price;
	bool isSelected;
	Pet* next;
	Pet* prev;
};

