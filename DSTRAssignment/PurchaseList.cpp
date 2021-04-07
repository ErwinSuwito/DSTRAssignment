#include "PurchaseList.h"

Purchase* PurchaseList::mergeList(Purchase* list1, Purchase* list2)
{
	Purchase* newHead = NULL;
	if (list1 == NULL)
	{
		return list2;
	}
	
	if (list2 == NULL)
	{
		return list1;
	}

	if (list1->totalAmount <= list2->totalAmount)
	{
		newHead = list1;
		newHead->next = mergeList(list1->next, list2);
	}
	else
	{
		newHead = list2;
		newHead->next = mergeList(list1, list2->next);
	}

	return newHead;
}

void PurchaseList::splitList(Purchase* start, Purchase** list1, Purchase** list2)
{
	Purchase* slow = start;
	Purchase* fast = start->next;
	
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*list1 = start;
	*list2 = slow->next;

	slow->next = NULL;
}

void PurchaseList::mergeSort(Purchase** start)
{
	Purchase* head = *start;
	Purchase* list1, * list2;

	if (head == NULL || head->next == NULL)
	{
		return;
	}

	splitList(head, &list1, &list2);

	mergeSort(&list1);
	mergeSort(&list2);

	*start = mergeList(list1, list2);
	return;
}

int PurchaseList::getSize()
{
	return size;
}

bool PurchaseList::AddPurchase(string, string, string)
{
	return false;
}

void PurchaseList::Print()
{
}

void PurchaseList::SortByTotal()
{
}

void PurchaseList::ViewDetail(string)
{
}
