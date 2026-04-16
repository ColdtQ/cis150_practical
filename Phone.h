#ifndef PHONE_H
#define PHONE_H

#include <string>

using namespace std;

// ============================================================================
// Class: Phone
// Purpose:
//   This class stores information for one phone that D-Cell can sell.
//   Each phone has:
//     1) A brand name (for example: Samsung)
//     2) A model name (for example: Galaxy-S25)
//     3) A price (for example: 649.99)
//
// Beginner note:
//   A class is a custom data type. It lets us group related information
//   together so it is easy to pass around in functions and store in a vector.
// ============================================================================
class Phone
{
public:
    string brand;
    string model;
    double price;

    // Default constructor:
    // Creates a Phone with empty text and 0.0 price.
    Phone();

    // Full constructor:
    // Creates a Phone with specific values.
    Phone(const string& phoneBrand, const string& phoneModel, double phonePrice);
};

#endif
