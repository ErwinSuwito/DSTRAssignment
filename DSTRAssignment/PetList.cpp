#include "PetList.h"

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

bool PetList::DeletePet(int petId)
{
	Pet* selectedPet = this->getItemBasedOnId(petId);
	Pet* nextPet = selectedPet->next;
	Pet* prevPet = selectedPet->prev;

	// There is no other pet in the linked list
	if (nextPet == NULL)
	{
		delete(selectedPet);
		petHead = NULL;
		return true;
	}

	// There is another pet in the linked list, check if there is a previous pet
	if (prevPet != NULL)
	{
		// There is a previous pet, fix their next and prev pointers.
		nextPet->prev = prevPet;
		prevPet->next = nextPet;
		delete(selectedPet);
		return true;
	}
	else
	{
		// There is no prev pet, set the prev to NULL and return
		nextPet->prev = NULL;
		delete(selectedPet);
		return true;
	}

	return false;
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
	this->Print();
	return;
}
