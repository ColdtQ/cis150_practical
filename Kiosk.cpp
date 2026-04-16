#include <iostream>
#include <iomanip>
#include "Kiosk.h"

using namespace std;

// ============================================================================
// Function: selectPhone
// Purpose:
//   1) Display a D-Cell banner and menu of phones.
//   2) Prompt user to enter a model name exactly as shown.
//   3) Validate input by searching the vector.
//   4) Keep asking until a valid model is entered.
//   5) Return the selected Phone object.
//
// Beginner note:
//   A while(true) loop is used so the menu repeats until the user enters
//   correct input. Once a valid match is found, we return and exit function.
// ============================================================================
Phone selectPhone(const vector<Phone>& phones)
{
    string modelChoice;

    while (true)
    {
        cout << "\n==================================================\n";
        cout << "            D-Cell Dorm Kiosk Ordering            \n";
        cout << "==================================================\n";

        // Print column titles for a clean menu layout.
        cout << left << setw(15) << "Brand"
             << setw(15) << "Model"
             << right << setw(10) << "Price" << endl;
        cout << "--------------------------------------------------\n";

        // Print each phone on its own line.
        for (size_t i = 0; i < phones.size(); i++)
        {
            cout << left << setw(15) << phones[i].brand
                 << setw(15) << phones[i].model
                 << right << setw(10) << fixed << setprecision(2) << phones[i].price
                 << endl;
        }

        cout << "--------------------------------------------------\n";
        cout << "Enter the phone model exactly as shown: ";
        cin >> modelChoice;

        // Validation loop: check entered model against each phone model.
        for (size_t i = 0; i < phones.size(); i++)
        {
            if (modelChoice == phones[i].model)
            {
                return phones[i];
            }
        }

        // If no match was found, tell the user and repeat.
        cout << "Invalid model. Please enter a model from the menu.\n";
    }
}

// ============================================================================
// Function: getCustInfo
// Purpose:
//   Collect the student first name and room number.
//   The values are returned using reference parameters.
// ============================================================================
void getCustInfo(string& firstName, string& roomNumber)
{
    cout << "\nEnter student first name: ";
    cin >> firstName;

    cout << "Enter dorm room number: ";
    cin >> roomNumber;
}

// ============================================================================
// Function: calcFees
// Purpose:
//   Compute required fees using assignment percentages:
//     - Sales tax rate = 0.06
//     - UMich service fee rate = 0.03
//   Both results are returned through reference parameters.
// ============================================================================
void calcFees(const Phone& selectedPhone, double& salesTax, double& serviceFee)
{
    const double SALES_TAX_RATE = 0.06;
    const double SERVICE_FEE_RATE = 0.03;

    salesTax = selectedPhone.price * SALES_TAX_RATE;
    serviceFee = selectedPhone.price * SERVICE_FEE_RATE;
}

// ============================================================================
// Function: printReceipt
// Purpose:
//   Print a polished receipt that includes:
//     - D-Cell header
//     - Student first name and room number
//     - Phone brand/model
//     - Base price, sales tax, service fee
//     - Final total
//
// Formatting details:
//   - fixed and setprecision(2) for currency style
//   - setw for alignment so columns look neat
// ============================================================================
void printReceipt(const Phone& selectedPhone,
                  const string& firstName,
                  const string& roomNumber,
                  double salesTax,
                  double serviceFee)
{
    double total = selectedPhone.price + salesTax + serviceFee;

    cout << "\n\n";
    cout << "==================================================\n";
    cout << "                   D-Cell Receipt                 \n";
    cout << "==================================================\n";

    cout << left << setw(25) << "Student First Name:" << firstName << endl;
    cout << left << setw(25) << "Dorm Room Number:" << roomNumber << endl;

    cout << "--------------------------------------------------\n";

    cout << left << setw(25) << "Phone Brand:" << selectedPhone.brand << endl;
    cout << left << setw(25) << "Phone Model:" << selectedPhone.model << endl;

    cout << "--------------------------------------------------\n";

    cout << fixed << setprecision(2);
    cout << left << setw(25) << "Base Price:" << right << setw(10) << selectedPhone.price << endl;
    cout << left << setw(25) << "Sales Tax (6%):" << right << setw(10) << salesTax << endl;
    cout << left << setw(25) << "UMich Service Fee (3%):" << right << setw(10) << serviceFee << endl;
    cout << "--------------------------------------------------\n";
    cout << left << setw(25) << "Total:" << right << setw(10) << total << endl;

    cout << "==================================================\n";
    cout << "Thank you for choosing D-Cell!\n";
    cout << "==================================================\n";
}
