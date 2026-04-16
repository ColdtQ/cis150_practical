#include "Phone.h"

// ============================================================================
// Default constructor definition
// ============================================================================
Phone::Phone()
{
    brand = "";
    model = "";
    price = 0.0;
}

// ============================================================================
// Full constructor definition
// ============================================================================
Phone::Phone(const string& phoneBrand, const string& phoneModel, double phonePrice)
{
    brand = phoneBrand;
    model = phoneModel;
    price = phonePrice;
}
