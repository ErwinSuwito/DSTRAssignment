
#include <iostream>
#include <chrono>
#include <iomanip>
#include "PurchaseList.h"
#include "Purchase.h"
using namespace std;

PurchaseList purchaseList = PurchaseList();
Purchase* purchaseHead = NULL;

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

void sandbox()
{

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
                cout << "1 selected" << endl;
                break;

            case 2:
                cout << "2 selected" << endl;
                break;

            case 3:
                cout << "3 selected" << endl;
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

            default:
                cout << "Invalid selection. Please try again. " << endl;
                break;
        }

        showMainMenu();
        cin >> input;
    }
}