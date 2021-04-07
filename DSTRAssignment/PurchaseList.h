#pragma once
#include "Pet.h"
#include "Purchase.h"
using namespace std;

class PurchaseList
{
private:
	int size = 0;
	Purchase* mergeList(Purchase* list1, Purchase* list2);
	void splitList(Purchase* start, Purchase** list1, Purchase** list2);
	void mergeSort(Purchase** start);

public:
	Purchase* pHead;
	int getSize();
	Purchase* AddPurchase(string, string, string);
	void Print();
	void Print(Purchase*);
	void SortByTotal();
	void ViewDetail(int i);
	Purchase* getItemAt(int);
	bool AddPet(Purchase*, Pet*);
};

