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
	Pet* petHead = NULL;
	Pet* getItemBasedOnId(int i);
	int getSize();
	bool AddPet(string, string, double);
	void UpdatePet(Pet*, string, string, double);
	void DeletePet(int);
	void Search(int);
	void Print();
	void FilterByColor(string);
	void SortByPrice();
	void RevertPurchaseFlag();
};