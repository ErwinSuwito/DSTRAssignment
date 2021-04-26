#include "PetList.h"

Pet* PetList::mergeList(Pet* list1, Pet* list2)
{
	Pet* newHead = NULL;
	if (list1 == NULL)
	{
		return list2;
	}

	if (list2 == NULL)
	{
		return list1;
	}

	if (list1->price <= list2->price)
	{
		newHead = list1;
		newHead->next = mergeList(list1->next, list2);
		newHead->prev = NULL;
	}
	else
	{
		newHead = list2;
		newHead->next = mergeList(list1, list2->next);
		newHead->prev = NULL;
	}

	return newHead;
}

void PetList::splitList(Pet* start, Pet** list1, Pet** list2)
{
	Pet* slow = start;
	Pet* fast = start->next;

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

void PetList::mergeSort(Pet** start)
{
	Pet* head = *start;
	Pet* list1, * list2;

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

int PetList::getSize()
{
	return size;
}

bool PetList::AddPet(string _petBreed, string _petColor, double _price)
{
	try
	{
		Pet* pet = new Pet();
		size++;
		id++;

		(*pet).petColor = _petColor;
		(*pet).petBreed = _petBreed;
		(*pet).petId = id;
		(*pet).price = _price;

		if (petHead == NULL)
		{
			(*pet).next = NULL;
			(*pet).prev = NULL;
			petHead = pet;
		}
		else
		{
			(*pet).next = petHead;
			petHead->prev = pet;
			petHead = pet;
		}

		return true;
	}
	catch (exception e)
	{
		cerr << endl << e.what() << endl;
		return false;
	}
}

bool PetList::DeletePet(string)
{
	return false;
}

void PetList::Search(string petId)
{
	Pet* ptr = petHead;

	if (ptr == NULL)
	{
		cout << endl << "No pets found";
		return;
	}

	while (ptr != NULL)
	{
		if (ptr->petId == petId)
		{
			cout << endl << "====================================";
			cout << endl << "ID: " << ptr->petId;
			cout << endl << "Breed: " << ptr->petBreed;
			cout << endl << "Color: " << ptr->petColor;
			cout << endl << "Price: " << ptr->price;
			cout << endl << "====================================";
		}
		ptr = ptr->next;
	}
}

void PetList::Print()
{
	Pet* ptr = petHead;

	cout << endl << "====================================";
	cout << endl << "Displaying all pets";
	cout << endl << "====================================";

	if (ptr == NULL)
	{
		cout << endl << "No pets found";
		return;
	}

	while (ptr != NULL)
	{
		cout << endl << "====================================";
		cout << endl << "ID: " << ptr->petId;
		cout << endl << "Breed: " << ptr->petBreed;
		cout << endl << "Color: " << ptr->petColor;
		cout << endl << "Price: " << ptr->price;
		cout << endl << "====================================";
		ptr = ptr->next;
	}
}

void PetList::FilterByColor(string color)
{
	cout << endl << "====================================";
	cout << endl << "Displaying filtered pets";
	cout << endl << "====================================";

	PetList::Search(color);
}

void PetList::SortByPrice()
{
	Pet* ptr = petHead;
	mergeSort(&ptr);
	this->Print();
}
