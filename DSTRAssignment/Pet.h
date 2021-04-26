#pragma once
#include <iostream>
using namespace std;

class Pet
{
public:
	string petId, petBreed, petColor;
	double price;
	Pet* next;
	Pet* prev;
};

