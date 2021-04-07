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

Purchase* PurchaseList::AddPurchase(string custName, string custEmail, string custPhNo)
{
	try
	{
		// Initializes a new Purchase object
		Purchase purchase = Purchase();

		// Get local date and time
		time_t now = time(NULL);
		char date[26];
		ctime_s(date, sizeof date, &now);
		purchase.purchaseTimeStamp = date;

		// Increase the amount of items
		size++;

		return &purchase;
	}
	catch (exception e)
	{
		cerr << endl << e.what() << endl;
		return nullptr;
	}
}

void PurchaseList::Print()
{
	cout << "Displaying all purchases";
	Purchase* ptr = pHead;

	if (ptr == nullptr)
	{
		cout << endl << "====================================";
		cout << endl << "No purchases made";
		cout << endl << "====================================";
		return;
	}

	while (ptr != nullptr)
	{
		cout << endl << "====================================";
		cout << endl << "Purchase ID: " << ptr->purchaseId;
		cout << endl << "Customer Name: " << ptr->custName;
		cout << endl << "Customer Phone Number: " << ptr->custPhNo;
		cout << endl << "Customer Email: " << ptr->custEmail;
		cout << endl << "Transaction Date: " << ptr->purchaseTimeStamp;
		cout << endl << "Transaction Amount: " << ptr->totalAmount;
		cout << endl << "====================================";
		ptr = ptr->next;
	}
}

void PurchaseList::Print(Purchase* ptr)
{
	cout << endl << "Displaying all purchases";

	if (ptr == nullptr)
	{
		cout << endl << "====================================";
		cout << endl << "No purchases made";
		cout << endl << "====================================";
		return;
	}

	while (ptr != nullptr)
	{
		cout << endl << "====================================";
		cout << endl << "Purchase ID: " << ptr->purchaseId;
		cout << endl << "Customer Name: " << ptr->custName;
		cout << endl << "Customer Phone Number: " << ptr->custPhNo;
		cout << endl << "Customer Email: " << ptr->custEmail;
		cout << endl << "Transaction Date: " << ptr->purchaseTimeStamp;
		cout << endl << "Transaction Amount: " << ptr->totalAmount;
		cout << endl << "====================================";
		ptr = ptr->next;
	}
}

void PurchaseList::SortByTotal()
{
	Purchase* ptr = pHead;
	mergeSort(&ptr);
	this->Print(ptr);
}

void PurchaseList::ViewDetail(int i)
{
	Purchase* ptr = getItemAt(i);

	cout << endl << "Printing requsted purchase information";

	cout << endl << "Purchase ID: " << ptr->purchaseId;
	cout << endl << "Customer Name: " << ptr->custName;
	cout << endl << "Customer Phone Number: " << ptr->custPhNo;
	cout << endl << "Customer Email: " << ptr->custEmail;
	cout << endl << "Transaction Date: " << ptr->purchaseTimeStamp;
	cout << endl << "Transaction Amount: " << ptr->totalAmount;

	//TO-DO: Print purchased pet details.
}

Purchase* PurchaseList::getItemAt(int index)
{
	if (index < 0 || index >= getSize())
	{
		throw "Index out of bounds.";
	}

	Purchase* current = pHead;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current;
}

bool PurchaseList::AddPet(Purchase* purchase, Pet* pet)
{
	try
	{
		// Adds the selected pet to the purchase
		if (purchase->pets == nullptr)
		{
			// It is a new purchase, set the prev and next to NULL
			purchase->pets = pet;
			pet->prev = NULL;
			pet->next = NULL;

			return true;
		}
		else
		{
			// Not the first pet to be added, modify the next and prev pointers
			pet->prev = NULL;

			Pet* current = purchase->pets;
			current->prev = pet;
			pet->next = current;
			purchase->pets = pet;
		}

		// Updates the totalAmount of the purchase
		purchase->totalAmount += pet->price;

		return true;
	}
	catch (exception e)
	{
		cerr << e.what();
		return false;
	}
}
