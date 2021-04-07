
#include <iostream>
using namespace std;

void showMainMenu()
{
    cout << endl << endl << "*** Pet inventory System ***" << endl;
    cout << "To perform an action, enter:" << endl;
    cout << "1 to add new pet" << endl;
    cout << "2 to browse pets" << endl;
    cout << "3 to search pets" << endl;
    cout << "4 to Make purchase" << endl;
    cout << "5 to view transaction history" << endl << endl;

    cout << "0 to exit" << endl;
    cout << "Selection: ";
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
                cout << "4 selected" << endl;
                break;

            case 5:
                cout << "5 selected" << endl;
                break;

            default:
                cout << "Invalid selection. " << endl;
        }

        showMainMenu();
        cin >> input;
    }
}