#ifndef KIOSK_H
#define KIOSK_H

#include <vector>
#include <string>
#include "Phone.h"

using namespace std;

// ============================================================================
// Function Prototypes for the D-Cell kiosk workflow.
//
// selectPhone(...)
//   Shows the phone menu, validates model input, and returns the chosen phone.
//
// getCustInfo(...)
//   Gets student first name and room number using reference parameters.
//
// calcFees(...)
//   Calculates the required 6% sales tax and 3% service fee.
//
// printReceipt(...)
//   Prints a neat receipt including customer info, phone info, and totals.
// ============================================================================
Phone selectPhone(const vector<Phone>& phones);
void getCustInfo(string& firstName, string& roomNumber);
void calcFees(const Phone& selectedPhone, double& salesTax, double& serviceFee);
void printReceipt(const Phone& selectedPhone,
                  const string& firstName,
                  const string& roomNumber,
                  double salesTax,
                  double serviceFee);

#endif
