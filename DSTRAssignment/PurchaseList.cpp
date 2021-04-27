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

bool PurchaseList::AddPurchase(string custName, string custEmail, string custPhNo)
{
	try
	{
		// Initializes a new Purchase object
		Purchase* purchase = new Purchase();

		auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

#pragma warning(suppress : 4996)
		(*purchase).purchaseTimeStamp = ctime(&timenow);

		// Increase the amount of items
		size++;
		id++;

		(*purchase).custEmail = custEmail;
		(*purchase).custName = custName;
		(*purchase).custPhNo = custPhNo;
		(*purchase).purchaseId = id;


		if (purchaseHead == NULL)
		{
			(*purchase).next = NULL;
		}
		else
		{
			(*purchase).next = purchaseHead;
		}
		
		purchaseHead = purchase;

		return true;
	}
	catch (exception e)
	{
		cerr << endl << e.what() << endl;
		return false;
	}
}

void PurchaseList::Print()
{
	cout << endl << "====================================";
	cout << endl << "Displaying all purchases";
	cout << endl << "====================================";
	Purchase* ptr = purchaseHead;

	if (ptr == NULL)
	{
		cout << endl << "No purchases made";
		return;
	}

	while (ptr != NULL)
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
	Purchase* ptr = purchaseHead;
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

	Purchase* current = purchaseHead;
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
		Pet* newPet = new Pet();
		newPet->petBreed = pet->petBreed;
		newPet->petColor = pet->petColor;
		newPet->price = pet->price;
		newPet->petId = pet->petId;
		newPet->next = purchase->pets;
		purchase->pets = newPet;

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
