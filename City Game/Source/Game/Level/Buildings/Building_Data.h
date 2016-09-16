#ifndef BUILDING_DATA_H
#define BUILDING_DATA_H

#include "E_Building_Use.h"
#include "../Level_Values.h"

struct Building_Data
{
    Building_Data( Building_Use use, Resources cost );

    const Building_Use  use;
    const Resources     cost;
};

#endif // BUILDING_DATA_H
