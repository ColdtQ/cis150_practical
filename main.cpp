/*
    ============================================================================
    Program: CIS 150 Lab Practical - Winter 2026
    File:    main.cpp

    Purpose:
    This program runs a simple D-Cell dorm kiosk for ordering phones.
    It reads phone data from a file named phones.dat, lets the student
    choose a valid phone model, collects customer info, calculates fees,
    and prints a polished receipt.

    Required fees:
      - Sales tax: 6%
      - UMich Service Fee: 3%

    Design notes:
      - Program uses a Phone class.
      - Data is stored in vector<Phone>.
      - Main handles file input and overall flow.
      - Helper functions are defined in Kiosk.cpp.
    ============================================================================
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Phone.h"
#include "Kiosk.h"

using namespace std;

int main()
{
    // ------------------------------------------------------------------------
    // 1) Open the phones data file.
    // ------------------------------------------------------------------------
    ifstream inFile("phones.dat");

    // If the file fails to open, show a clear message and exit gracefully.
    if (!inFile)
    {
        cout << "Error: Could not open phones.dat. Please verify the file exists." << endl;
        return 1;
    }

    // ------------------------------------------------------------------------
    // 2) Read all phones from file into a vector<Phone>.
    //    Expected file format per line:
    //      Brand Model Price
    //    Example:
    //      Samsung Galaxy-S25 649.99
    // ------------------------------------------------------------------------
    vector<Phone> phones;
    string brand;
    string model;
    double price;

    while (inFile >> brand >> model >> price)
    {
        phones.push_back(Phone(brand, model, price));
    }

    // Close file after reading is complete.
    inFile.close();

    // If no phone records were loaded, we cannot continue.
    if (phones.empty())
    {
        cout << "Error: phones.dat contains no valid phone records." << endl;
        return 1;
    }

    // ------------------------------------------------------------------------
    // 3) Call selectPhone to show menu and get a valid phone choice.
    // ------------------------------------------------------------------------
    Phone selectedPhone = selectPhone(phones);

    // ------------------------------------------------------------------------
    // 4) Get student information using reference parameters.
    // ------------------------------------------------------------------------
    string firstName;
    string roomNumber;
    getCustInfo(firstName, roomNumber);

    // ------------------------------------------------------------------------
    // 5) Calculate fees for selected phone.
    // ------------------------------------------------------------------------
    double salesTax = 0.0;
    double serviceFee = 0.0;
    calcFees(selectedPhone, salesTax, serviceFee);

    // ------------------------------------------------------------------------
    // 6) Print final receipt.
    // ------------------------------------------------------------------------
    printReceipt(selectedPhone, firstName, roomNumber, salesTax, serviceFee);

    return 0;
}
