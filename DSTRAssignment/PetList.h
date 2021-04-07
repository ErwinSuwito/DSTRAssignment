#pragma once
#include "Pet.h"
using namespace std;

class PetList
{
private:
	int size = 0;
	void mergeList(Pet* list1, Pet* list2);
	void splitList(Pet* start, Pet* list1, Pet* list2);
	void mergeSort(Pet* start);

public:
	int getSize();
	bool AddPet(string, string, string, double);
	bool DeletePet(string);
	void Search(string);
	void Print();
	void FilterByColor(string);
	void SortByColor();
};