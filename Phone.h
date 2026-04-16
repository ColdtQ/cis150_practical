#ifndef PHONE_H
#define PHONE_H

#include <string>

using namespace std;

// ============================================================================
// Class: Phone
// Purpose:
//   This class is a very simple container (sometimes called a "data class")
//   used to store one phone option from the phones.dat file.
//
// Why a class here?
//   The assignment specifically requires a class named Phone with three fields.
//   Each Phone object keeps related information together so our program can
//   pass one object around instead of three separate variables.
//
// Fields:
//   - brand : The phone manufacturer (Samsung, Apple, Google, etc.)
//   - model : The model name the user must type exactly (Galaxy-S25, etc.)
//   - price : Base cost of the phone before tax/fees
// ============================================================================
class Phone
{
public:
    string brand;
    string model;
    double price;
};

#endif
