#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "KioskFunctions.h"

using namespace std;

// ------------------------------------------------------------------
// Function: selectPhone
// Purpose:
//   1) Display a banner so the kiosk looks professional.
//   2) Print all available phones from the vector loaded from file.
//   3) Ask the student to type a model name exactly as shown.
//   4) Keep asking until a valid model is entered.
//   5) Return the full Phone object for the chosen model.
//
// Important beginner note:
//   We use a while(true) loop and only exit by returning a valid phone.
//   This is a simple and common way to enforce input validation.
// ------------------------------------------------------------------
Phone selectPhone(const vector<Phone>& phones)
{
    string modelChoice;

    while (true)
    {
        cout << "\n==================================================\n";
        cout << "            D-Cell Dorm Kiosk Ordering            \n";
        cout << "==================================================\n";

        // Column headers for the phone menu.
        cout << left << setw(15) << "Brand"
             << setw(15) << "Model"
             << right << setw(10) << "Price" << endl;
        cout << "--------------------------------------------------\n";

        // Display each phone entry in aligned columns.
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

        // Validate model input by comparing against each phone's model.
        for (size_t i = 0; i < phones.size(); i++)
        {
            if (modelChoice == phones[i].model)
            {
                return phones[i];
            }
        }

        // If no matching model was found, tell user and loop again.
        cout << "Invalid model. Please enter a model from the menu.\n";
    }
}

// ------------------------------------------------------------------
// Function: getCustInfo
// Purpose:
//   Ask for the student's first name and room number.
//
// Why reference parameters?
//   firstName and roomNumber are passed by reference so changes made inside
//   this function are sent back to main() without needing a return value.
// ------------------------------------------------------------------
void getCustInfo(string& firstName, string& roomNumber)
{
    cout << "\nEnter student first name: ";
    cin >> firstName;

    cout << "Enter dorm room number: ";
    cin >> roomNumber;
}

// ------------------------------------------------------------------
// Function: calcFees
// Purpose:
//   Use the assignment's exact fee rates to calculate:
//   - Sales Tax: 6%
//   - UMich Service Fee: 3%
//
// Inputs:
//   selectedPhone : The phone that was chosen in selectPhone(...)
//
// Outputs (reference parameters):
//   salesTax   : computed tax amount
//   serviceFee : computed service fee amount
// ------------------------------------------------------------------
void calcFees(const Phone& selectedPhone, double& salesTax, double& serviceFee)
{
    const double SALES_TAX_RATE = 0.06;
    const double SERVICE_FEE_RATE = 0.03;

    salesTax = selectedPhone.price * SALES_TAX_RATE;
    serviceFee = selectedPhone.price * SERVICE_FEE_RATE;
}

// ------------------------------------------------------------------
// Function: printReceipt
// Purpose:
//   Print a neat, easy-to-read receipt that includes all required fields:
//   - D-Cell header
//   - Student info
//   - Phone info
//   - Base price, tax, service fee
//   - Final total
//
// Formatting details:
//   - fixed + setprecision(2) forces standard money style (2 decimals)
//   - setw(...) aligns labels and values for a professional look
// ------------------------------------------------------------------
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
