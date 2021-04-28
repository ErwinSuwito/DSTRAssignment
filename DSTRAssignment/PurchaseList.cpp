#include "PurchaseList.h"

#pragma region Merge Sort Code

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

#pragma endregion

int PurchaseList::getSize()
{
	return size;
}

Purchase* PurchaseList::AddPurchase(string custName, string custEmail, string custPhNo)
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

		return purchase;
	}
	catch (exception e)
	{
		cerr << endl << e.what() << endl;
		return NULL;
	}
}

void PurchaseList::Print()
{
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

void PurchaseList::ViewDetail(Purchase* purchase)
{

	cout << endl << "====================================";
	cout << endl << "Purchase Detail";
	cout << endl << "====================================";

	cout << endl << "Purchase ID: " << purchase->purchaseId;
	cout << endl << "Customer Name: " << purchase->custName;
	cout << endl << "Customer Phone Number: " << purchase->custPhNo;
	cout << endl << "Customer Email: " << purchase->custEmail;
	cout << endl << "Transaction Date: " << purchase->purchaseTimeStamp;
	cout << endl << "Transaction Amount: " << purchase->totalAmount;

	cout << endl << "====================================";
	cout << endl << "Pet Details";
	cout << endl << "====================================";


	Pet* pet = purchase->pets;

	while (pet != NULL)
	{
		cout << endl << "Breed: " << pet->petBreed;
		cout << endl << "Color: " << pet->petColor;
		cout << endl << "Price: " << pet->price;
		cout << endl << "====================================";

		pet = pet->next;
	}
}

Purchase* PurchaseList::getItemBasedOnId(int index)
{
	Purchase* current = purchaseHead;
	while (current != NULL)
	{
		if (current->purchaseId == index)
		{
			return current;
		}

		current = current->next;
	}

	return NULL;
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
		double totalPrice = purchase->totalAmount + newPet->price;
		purchase->totalAmount += totalPrice;

		return true;
	}
	catch (exception e)
	{
		cerr << e.what();
		return false;
	}
}
