/*
    ============================================================================
    Program: CIS 150 Lab Practical - Winter 2026 (Modular Version)
    File:    main.cpp

    Purpose:
    This program runs a D-Cell dorm kiosk where students can order phones.
    The kiosk reads phone options from a text file, lets the user choose
    a phone model, collects student delivery details, calculates required
    fees, and prints a professional receipt.

    Why this version is modularized:
    - Phone.h: stores the Phone class definition.
    - KioskFunctions.h: stores function prototypes.
    - KioskFunctions.cpp: stores function definitions.
    - main.cpp: coordinates the overall program flow.

    This structure keeps each file focused on one job and is easier to
    maintain, test, and understand as projects grow.
    ============================================================================
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "KioskFunctions.h"

using namespace std;

int main()
{
    // --------------------------------------------------------------
    // 1) Open phones.dat.
    //    If the file is missing or cannot be opened, end gracefully.
    // --------------------------------------------------------------
    ifstream inFile("phones.dat");
    if (!inFile)
    {
        cout << "Error: Could not open phones.dat. Please make sure it exists." << endl;
        return 1;
    }

    // --------------------------------------------------------------
    // 2) Read all phone entries into vector<Phone>.
    //    File format expected: brand model price
    //    Example: Samsung Galaxy-S25 649.99
    // --------------------------------------------------------------
    vector<Phone> phones;
    Phone tempPhone;

    while (inFile >> tempPhone.brand >> tempPhone.model >> tempPhone.price)
    {
        phones.push_back(tempPhone);
    }

    // Close file after reading to release the resource.
    inFile.close();

    // If no phone records were read, there is nothing to display or sell.
    if (phones.empty())
    {
        cout << "Error: phones.dat was opened, but no valid phone data was found." << endl;
        return 1;
    }

    // --------------------------------------------------------------
    // 3) Ask user to select a phone model from the menu.
    //    selectPhone(...) performs input validation.
    // --------------------------------------------------------------
    Phone selectedPhone = selectPhone(phones);

    // --------------------------------------------------------------
    // 4) Get student first name and room number.
    // --------------------------------------------------------------
    string firstName;
    string roomNumber;
    getCustInfo(firstName, roomNumber);

    // --------------------------------------------------------------
    // 5) Calculate sales tax and UMich Service Fee.
    // --------------------------------------------------------------
    double salesTax = 0.0;
    double serviceFee = 0.0;
    calcFees(selectedPhone, salesTax, serviceFee);

    // --------------------------------------------------------------
    // 6) Print final formatted receipt.
    // --------------------------------------------------------------
    printReceipt(selectedPhone, firstName, roomNumber, salesTax, serviceFee);

    return 0;
}
