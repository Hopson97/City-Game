#include "Person.h"

#include <iostream>

void Person :: setHouse(Building& building)
{
    m_house = &building;
}

void Person :: setWork(Building& building)
{
    m_workPlace = &building;
}

bool Person :: isHomeless ()
{
    return m_house;
}

bool Person :: isUnemployed ()
{
    return !m_workPlace;
}

void Person :: evictHome  ()
{
    m_house = nullptr;
}

void Person :: sack       ()
{
    m_workPlace = nullptr;
}
