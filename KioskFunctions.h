#ifndef KIOSK_FUNCTIONS_H
#define KIOSK_FUNCTIONS_H

#include <string>
#include <vector>
#include "Phone.h"

using namespace std;

// ============================================================================
// Function Prototypes for the D-Cell kiosk program
//
// These declarations allow main.cpp to call functions that are implemented in
// KioskFunctions.cpp. Splitting declarations and definitions into separate
// files is part of modular program design and makes code easier to maintain.
// ============================================================================

// Shows the D-Cell menu, asks user for model, validates input, and returns
// the selected phone object.
Phone selectPhone(const vector<Phone>& phones);

// Gets student first name and room number via reference parameters.
void getCustInfo(string& firstName, string& roomNumber);

// Calculates required fees (6% sales tax and 3% UMich Service Fee).
void calcFees(const Phone& selectedPhone, double& salesTax, double& serviceFee);

// Prints a polished receipt with student info, phone info, fees, and total.
void printReceipt(const Phone& selectedPhone,
                  const string& firstName,
                  const string& roomNumber,
                  double salesTax,
                  double serviceFee);

#endif
