/*
    ================================================================
    Program: CIS 150 Lab Practical - Winter 2026
    File:    main.cpp
    Author:  (Your Name)

    Purpose:
    This program simulates a simple D-Cell phone ordering kiosk used in
    college dormitories. The kiosk allows a student to:
      1) Choose a phone model from a menu loaded from "phones.dat"
      2) Enter first name and dorm room number
      3) See a professionally formatted receipt

    Required calculations:
      - Sales Tax: 6%
      - UMich Service Fee: 3%

    Notes for beginner students:
      - The program uses a class named Phone to store each phone's data.
      - Phone data is read from a file into a vector<Phone>.
      - Functions are declared before main() and defined after main().
      - Input validation ensures the user must enter a valid phone model.
    ================================================================
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// ------------------------------------------------------------------
// Phone class
// ------------------------------------------------------------------
// This class represents one phone option in the D-Cell inventory.
// Each Phone object stores:
//   - brand (example: Samsung)
//   - model (example: Galaxy-S25)
//   - price (example: 649.99)
// ------------------------------------------------------------------
class Phone
{
public:
    string brand;
    string model;
    double price;
};

// ------------------------------------------------------------------
// Function Prototypes (declarations)
// ------------------------------------------------------------------
// These tell the compiler which functions exist before main() so main
// can call them, even though full function definitions come later.
// ------------------------------------------------------------------
Phone selectPhone(const vector<Phone>& phones);
void getCustInfo(string& firstName, string& roomNumber);
void calcFees(const Phone& selectedPhone, double& salesTax, double& serviceFee);
void printReceipt(const Phone& selectedPhone,
                  const string& firstName,
                  const string& roomNumber,
                  double salesTax,
                  double serviceFee);

int main()
{
    // --------------------------------------------------------------
    // Step 1: Open the data file that contains available phones.
    // --------------------------------------------------------------
    ifstream inFile("phones.dat");

    // If the file cannot be opened, print a clear error and stop.
    if (!inFile)
    {
        cout << "Error: Could not open phones.dat. "
             << "Please make sure the file exists and try again." << endl;
        return 1; // Non-zero return value means program ended with an error.
    }

    // --------------------------------------------------------------
    // Step 2: Read all phone data from file into vector<Phone>.
    // --------------------------------------------------------------
    vector<Phone> phones;
    Phone tempPhone;

    // File format expected per line: brand model price
    // Example: Samsung Galaxy-S25 649.99
    while (inFile >> tempPhone.brand >> tempPhone.model >> tempPhone.price)
    {
        phones.push_back(tempPhone);
    }

    // Always close the file once we are done reading from it.
    inFile.close();

    // Optional safety check: if file was open but no valid phone entries
    // were read, we cannot continue because there is nothing to sell.
    if (phones.empty())
    {
        cout << "Error: No phone data was found in phones.dat." << endl;
        return 1;
    }

    // --------------------------------------------------------------
    // Step 3: Let user choose a valid phone model from the menu.
    // --------------------------------------------------------------
    Phone selectedPhone = selectPhone(phones);

    // --------------------------------------------------------------
    // Step 4: Get customer information (first name and room number).
    // --------------------------------------------------------------
    string firstName;
    string roomNumber;
    getCustInfo(firstName, roomNumber);

    // --------------------------------------------------------------
    // Step 5: Calculate fees for the selected phone.
    // --------------------------------------------------------------
    double salesTax = 0.0;
    double serviceFee = 0.0;
    calcFees(selectedPhone, salesTax, serviceFee);

    // --------------------------------------------------------------
    // Step 6: Print a neat, professional receipt.
    // --------------------------------------------------------------
    printReceipt(selectedPhone, firstName, roomNumber, salesTax, serviceFee);

    return 0; // Program completed successfully.
}

// ------------------------------------------------------------------
// Function: selectPhone
// Purpose:
//   - Display D-Cell banner and menu of available phones
//   - Ask user for a phone model
//   - Keep asking until user enters a valid model from the file
//   - Return the chosen Phone object
// ------------------------------------------------------------------
Phone selectPhone(const vector<Phone>& phones)
{
    string modelChoice;

    // This loop continues forever until we return a valid Phone.
    while (true)
    {
        cout << "\n==================================================\n";
        cout << "            D-Cell Dorm Kiosk Ordering            \n";
        cout << "==================================================\n";
        cout << left << setw(15) << "Brand"
             << setw(15) << "Model"
             << right << setw(10) << "Price" << endl;
        cout << "--------------------------------------------------\n";

        // Display each phone from the vector in a tidy table format.
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

        // Validation: search for exact model match.
        // If found, return that phone immediately.
        for (size_t i = 0; i < phones.size(); i++)
        {
            if (modelChoice == phones[i].model)
            {
                return phones[i];
            }
        }

        // If we get here, model was not valid.
        cout << "Invalid model. Please enter a model from the menu.\n";
    }
}

// ------------------------------------------------------------------
// Function: getCustInfo
// Purpose:
//   - Ask the student for first name and room number
//   - Use reference parameters so values are sent back to main()
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
//   - Compute sales tax and UMich service fee using required rates
//   - Return both values through reference parameters
// ------------------------------------------------------------------
void calcFees(const Phone& selectedPhone, double& salesTax, double& serviceFee)
{
    const double SALES_TAX_RATE = 0.06;   // 6%
    const double SERVICE_FEE_RATE = 0.03; // 3%

    salesTax = selectedPhone.price * SALES_TAX_RATE;
    serviceFee = selectedPhone.price * SERVICE_FEE_RATE;
}

// ------------------------------------------------------------------
// Function: printReceipt
// Purpose:
//   - Print a clean, aligned receipt with all required information:
//       company header, student data, phone data, fees, and total
//   - Use fixed/setprecision(2) and setw for professional formatting
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

    // Student section
    cout << left << setw(25) << "Student First Name:" << firstName << endl;
    cout << left << setw(25) << "Dorm Room Number:" << roomNumber << endl;

    cout << "--------------------------------------------------\n";

    // Phone section
    cout << left << setw(25) << "Phone Brand:" << selectedPhone.brand << endl;
    cout << left << setw(25) << "Phone Model:" << selectedPhone.model << endl;

    cout << "--------------------------------------------------\n";

    // Cost section
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
