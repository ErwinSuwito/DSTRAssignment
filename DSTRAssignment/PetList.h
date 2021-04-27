#pragma once
#include "Pet.h"
using namespace std;

class PetList
{
private:
	int size = 0;
	int id = 0;
	Pet* mergeList(Pet* list1, Pet* list2);
	void splitList(Pet* start, Pet** list1, Pet** list2);
	void mergeSort(Pet** start);

public:
	Pet* petHead;
	Pet* getItemBasedOnId(int i);
	int getSize();
	bool AddPet(string, string, double);
	bool DeletePet(string);
	void Search(int);
	void Print();
	void FilterByColor(string);
	void SortByPrice();
};