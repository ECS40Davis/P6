#include "airport.h"

Airport::Airport()
{
} // Airport Default


Airport::Airport(const Airport& orig)
{
} // Airport Standard


Airport::~Airport()
{
} // ~Airport

bool Flight::operator < (const Flight f) const
{
    return true;
} // operator <

ostream& operator << (ostream &os, const Airport &a)
{
    return os;
} // operator <<

ostream& operator << (ostream &os, const Flight &f)
{
    return os;
} // operator <<
