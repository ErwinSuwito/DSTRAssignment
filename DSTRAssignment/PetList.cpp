#include "PetList.h"

// The following code was adapted from
// https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort-algorithm-on-linked-list
Pet* PetList::mergeList(Pet* list1, Pet* list2)
{
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
		list1->next = mergeList(list1->next, list2);
		list1->next->prev = list1;
		list1->prev = NULL;
		return list1;
	}
	else
	{
		list2->next = mergeList(list1, list2->next);
		list2->next->prev = list2;
		list2->prev = NULL;
		return list2;
	}
}

// The following code was adapted from
// https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort-algorithm-on-linked-list
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

	*list2 = slow->next;
	slow->next = NULL;
}

// The following code was adapted from
// https://www.tutorialspoint.com/cplusplus-program-to-implement-merge-sort-algorithm-on-linked-list
void PetList::mergeSort(Pet** start)
{
	if (*start == NULL || (*start)->next == NULL)
	{
		return;
	}

	Pet* a = *start, * b = NULL;
	splitList(*start, &a, &b);

	mergeSort(&a);
	mergeSort(&b);

	*start = mergeList(a, b);
}

Pet* PetList::getItemBasedOnId(int i)
{
	Pet* ptr = petHead;
	while (ptr != NULL)
	{
		if (ptr->petId == i)
		{
			return ptr;
		}
		ptr = ptr->next;
	}

	return NULL;
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

void PetList::UpdatePet(Pet* pet, string _petBreed, string _petColor, double _price)
{
	pet->petBreed = _petBreed;
	pet->petColor = _petColor;
	pet->price = _price;
}

// Code adapted from
// https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/data_structures/doubly_linked_list.cpp
void PetList::DeletePet(int petId)
{
	Pet* pet = this->getItemBasedOnId(petId);

	if (pet == NULL)
	{
		return;
	}

	if (pet->prev == NULL)
	{
		if (pet->next == NULL)
		{
			petHead = NULL;
		}
		else
		{
			petHead = pet->next;
			petHead->prev = NULL;
		}
	}
	else if (pet->next == NULL)
	{
		pet->prev->next = NULL;
	}
	else
	{
		pet->prev->next = pet->next;
		pet->next->prev = pet->prev;
	}
	
	size--;
	delete(pet);
}

void PetList::Search(int petId)
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

	if (ptr == NULL)
	{
		cout << endl << "No pets found";
		return;
	}

	while (ptr != NULL)
	{
		if (!ptr->isSelected)
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

void PetList::FilterByColor(string color)
{
	cout << endl << "====================================";
	cout << endl << "Displaying filtered pets";
	cout << endl << "====================================";

	Pet* ptr = petHead;

	if (ptr == NULL)
	{
		cout << endl << "No pets found";
		return;
	}

	while (ptr != NULL)
	{
		if (ptr->petColor == color)
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

void PetList::SortByPrice()
{
	mergeSort(&petHead);
	cout << endl << "====================================";
	cout << endl << "Displaying sorted pets";
	cout << endl << "====================================";
	this->Print();
	return;
}

void PetList::RevertPurchaseFlag()
{
	Pet* ptr;
	ptr = petHead;

	while (ptr != NULL)
	{
		ptr->isSelected = false;
		ptr = ptr->next;
	}
}
