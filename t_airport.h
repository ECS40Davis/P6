#ifndef AIRPORT_H
#define	AIRPORT_H

#include "city.h"
#include "list.h"

class Flight
{
    friend class Airport;
public:
    bool operator < (const Flight f) const;
    friend ostream& operator << (ostream &os, const Flight &f);
}; // class Flight


class Airport: public City
{
    List<Flight> flights;
public:
    Airport();
    Airport(const Airport& orig);
    virtual ~Airport();
    friend ostream& operator << (ostream &os, const Airport &a);
}; // class Airport

#endif


