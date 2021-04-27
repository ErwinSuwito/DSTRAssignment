
#include <iostream>
#include <chrono>
#include <iomanip>
#include "PurchaseList.h"
#include "Purchase.h"
#include "PetList.h"
#include "Pet.h"
using namespace std;

PurchaseList purchaseList = PurchaseList();
Purchase* purchaseHead = NULL;

PetList petList = PetList();
Pet* petHead = NULL;

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

    cout << endl << "2001 to return to main menu" << endl;
    cout << "Selection: ";
}

void printPurchases()
{
    purchaseList.Print();
}

void newPurchase()
{
    cout << endl << "====================================";
    cout << endl << "New Transaction";
    cout << endl << "====================================";
    cout << endl << "Please enter all the required information below. You can cancel";
    cout << endl << "anytime by pressing the 0 key.";
    cout << endl;

    Purchase* purchase;
    string input, custName, custPhNo, custEmail;
    int progress = 0;

    cout << endl << "====================================";
    cout << endl << "Customer Information";
    cout << endl << "====================================";

    while (input != "0")
    {
        switch (progress)
        {
            case 0:
                cout << endl << "Customer Name: ";
                cin >> input;
                custName = input;
                progress++;
                break;

            case 1:
                cout << endl << "Customer Phone Number: ";
                cin >> input;
                custPhNo = input;
                progress++;
                break;

            case 2:
                cout << endl << "Customer Email: ";
                cin >> input;
                custEmail = input;
                progress++;
                break;

            case 3:
                bool result = purchaseList.AddPurchase(custName, custPhNo, custEmail);
                if (result)
                {
                    cout << endl << "====================================";
                    cout << endl << "Select Pet";
                    cout << endl << "====================================";

                    // TO-DO: Print all available pets
                }
                else
                {
                    cout << "Unable to add purchase. Please try again later.";
                    break;
                }
                cin >> input;
                break;
        }
    }

    if (input == "0")
    {
        cout << "Canceled.";
        // TO-DO: Write code to delete the previous purcahse object
    }
}

void browsePets()
{
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

    Pet* pet;
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

}

void load()
{
    petList.AddPet("Poodle", "White", 100);
    petList.AddPet("Samoyed", "White", 800);
    petList.AddPet("Welsh Corgi", "Brown", 250);
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
                cout << "Search Pets selected" << endl;
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