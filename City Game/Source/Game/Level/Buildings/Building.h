#ifndef BUILDING_TYPE_H
#define BUILDING_TYPE_H

#include "Building_Data.h"

class Building
{
    public:
        Building( Building_Data& data );

        Building_Data& m_data; //This is basically a read only class (just constants) so it is fine to be public really
};

#endif // BUILDING_TYPE_H
