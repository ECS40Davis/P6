#ifndef AIRPORT_H
#define	AIRPORT_H

#include "city.h"

class Airport: public City
{
public:
    Airport();
    Airport(const Airport& orig);
    virtual ~Airport();
private:

};

#endif

