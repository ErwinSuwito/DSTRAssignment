
#include <iostream>
#include <chrono>
#include <iomanip>
#include "PurchaseList.h"
#include "Purchase.h"
#include "PetList.h"
#include "Pet.h"
using namespace std;

PurchaseList purchaseList = PurchaseList();

PetList petList = PetList();

void showMainMenu()
{
    cout << endl << endl << "*** Pet inventory System ***" << endl;
    cout << "To perform an action, enter:" << endl;
    cout << "1 to add new pet" << endl;
    cout << "2 to browse pets" << endl;
    cout << "3 to search pets" << endl;
    cout << "4 to Make purchase" << endl;
    cout << "5 to view transaction history" << endl;

    cout << endl << "0 to exit" << endl;
    cout << "Selection: ";
}

void showBrowsePetMenu()
{
    cout << endl << endl << "*** Browse Pets Available Actions ***" << endl;
    cout << "To perform an action, enter:" << endl;
    cout << "1001 to sort by price" << endl;
    cout << "1002 to filter by color" << endl;
    cout << "1003 to modify pet information" << endl;
    cout << "1004 to delete a pet" << endl;

    cout << endl << "2001 to return to main menu" << endl;
    cout << "Selection: ";
}

void showBrowsePurchaseMenu()
{
    cout << endl << endl << "*** View Purchases Available Actions ***" << endl;
    cout << "To perform an action, enter:" << endl;
    cout << "1001 to view purchase details" << endl;
    cout << "1002 to sort by price" << endl;

    cout << endl << "2001 to return to main menu" << endl;
    cout << "Selection: ";
}

void printPurchases()
{
    cout << endl << "====================================";
    cout << endl << "Displaying all purchases";
    cout << endl << "====================================";

    if (purchaseList.getSize() >= 1)
    {
        purchaseList.Print();

        int input;
        showBrowsePurchaseMenu();
        cin >> input;
        Purchase* purchase = NULL;
        Pet* pet = NULL;

        while (input != 2001)
        {
            switch (input)
            {
            case 1001:
                cout << endl << "Enter an ID: ";
                cin >> input;
                purchase = purchaseList.getItemBasedOnId(input);

                purchaseList.ViewDetail(purchase);
                break;

            case 1002:
                purchaseList.SortByTotal();
                break;
            }

            showBrowsePurchaseMenu();
            cin >> input;
        }
    }
    else
    {
        cout << endl << "No purchases recorded.";
    }
}

void newPurchase()
{
    cout << endl << "====================================";
    cout << endl << "New Transaction";
    cout << endl << "====================================";
    cout << endl << "Please enter all the required information below.";
    cout << endl;

    Purchase* purchase = nullptr;
    string custName, custPhNo, custEmail;
    int petId = 0;

    cout << endl << "====================================";
    cout << endl << "Customer Information";
    cout << endl << "====================================";

    cout << endl << "Customer Name: ";
    cin >> custName;
    cout << endl << "Customer Phone Number: ";
    cin >> custPhNo;
    cout << endl << "Customer Email: ";
    cin >> custEmail;

    purchase = purchaseList.AddPurchase(custName, custPhNo, custEmail);

    if (purchase != nullptr)
    {
        cout << endl << "====================================";
        cout << endl << "Select Pet";
        cout << endl << "Enter a Pet Id to be added to the purchase. When you're done";
        cout << endl << "enter 0 to quit selection and save the purchase.";
        cout << endl << "====================================";

        int input;
        petList.Print();
        cout << endl << "Selection: ";
        cin >> input;
        while (input != 0)
        {
            Pet* selectedPet = petList.getItemBasedOnId(input);
            if (selectedPet != NULL)
            {
                selectedPet->isSelected = true;
            }

            petList.Print();

            cin >> input;
        }

        Pet* petPtr = petList.petHead;
        while (petPtr != NULL)
        {
            Pet* newPtr = petPtr->next;
            if (petPtr->isSelected)
            {
                purchaseList.AddPet(purchase, petPtr);
                petList.DeletePet(petPtr->petId);
            }

            petPtr = newPtr;
        }

        cout << "Purchase saved!";
    }
    else
    {
        cout << "Unable to add purchase. Please try again later.";
        return; 
    }
}

void updatePet()
{
    int id;
    cout << endl << "Enter a pet id to update: ";
    cin >> id;

    auto pet = petList.getItemBasedOnId(id);

    if (pet == NULL)
    {
        cout << "Pet ID not found.";
    }
    else
    {
        cout << endl << "====================================";
        cout << endl << "Editing Pet";
        cout << endl << "====================================";
        cout << endl << "Please enter all the required information below. You can cancel";
        cout << endl << "anytime by pressing the 0 key. The original values will be shown to you.";
        cout << endl;

        string input, petBreed, petColor;
        double price;
        int progress = 0;

        while (input != "0")
        {
            switch (progress)
            {
            case 0:
                cout << endl << "Pet Breed [" << pet->petBreed << "]: ";
                cin >> input;
                petBreed = input;
                progress++;
                break;

            case 1:
                cout << endl << "Pet Color [" << pet->petColor << "]: ";
                cin >> input;
                petColor = input;
                progress++;
                break;

            case 2:
                cout << endl << "Price [" << pet->price << "]: ";
                cin >> price;
                progress++;
                break;

            case 3:
                petList.UpdatePet(pet, petBreed, petColor, price);

                cout << "Pet successfully updated!";
                return;
            }
        }
    }
}

void browsePets()
{
    cout << endl << "====================================";
    cout << endl << "Displaying all pets";
    cout << endl << "====================================";

    petList.Print();

    if (petList.getSize() >= 1)
    {
        int input;
        string color = "";
        showBrowsePetMenu();
        cin >> input;

        while (input != 2001)
        {
            switch (input)
            {
            case 1001:
                petList.SortByPrice();
                break;

            case 1002:
                cout << endl << "Enter a color: ";
                cin >> color;
                petList.FilterByColor(color);
                break;
                
            case 1003:
                updatePet();
                break;

            case 1004:
                cout << endl << "Enter an ID: ";
                cin >> input;
                petList.DeletePet(input);
                cout << "Pet deleted successfully";
                break;
            }

            showBrowsePetMenu();
            cin >> input;
        }
    }
}

void newPet()
{
    cout << endl << "====================================";
    cout << endl << "Add new Pet";
    cout << endl << "====================================";
    cout << endl << "Please enter all the required information below. You can cancel";
    cout << endl << "anytime by pressing the 0 key.";
    cout << endl;

    string input, petBreed, petColor;
    double price;
    int progress = 0;

    while (input != "0")
    {
        switch (progress)
        {
            case 0:
                cout << endl << "Pet Breed: ";
                cin >> input;
                petBreed = input;
                progress++;
                break;

            case 1:
                cout << endl << "Pet Color: ";
                cin >> input;
                petColor = input;
                progress++;
                break;

            case 2:
                cout << endl << "Price: ";
                cin >> price;
                progress++;
                break;

            case 3:
                bool result = petList.AddPet(petBreed, petColor, price);
                if (result == true)
                {
                    cout << "Pet added successfuly!";
                    return;
                }
                else
                {
                    cout << "Unable to add pet. Please try again later.";
                    return;
                }
        }
    }
}

void sandbox()
{
    cout << endl << "Sandbox";

    petList.DeletePet(4);
}

void load()
{
    petList.AddPet("Poodle", "White", 100);
    petList.AddPet("Samoyed", "White", 800);
    petList.AddPet("Welsh Corgi", "Brown", 250);
    petList.AddPet("Beagle", "Brown", 500);
    petList.AddPet("Siberian Husky", "White", 1000);
    petList.AddPet("Pomeranian", "Brown", 650);
}

int main()
{
    int input;
    showMainMenu();
    cin >> input;

    while (input != 0)
    {
        switch (input)
        {
            case 1: 
                newPet();
                break;

            case 2:
                browsePets();
                break;

            case 3:
                int id;
                cout << endl << "Enter a pet id to search: ";
                cin >> id;

                petList.Search(id);
                break;

            case 4:
                newPurchase();
                break;

            case 5:
                printPurchases();
                break;

            case 6:
                sandbox();
                break;

            case 7:
                load();
                break;

            default:
                cout << "Invalid selection. Please try again. " << endl;
                break;
        }

        showMainMenu();
        cin >> input;
    }
}