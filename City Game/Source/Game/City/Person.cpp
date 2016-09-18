#include "Person.h"

void Person :: setHouse(Building& building)
{
    m_house = &building;
}

void Person :: setWork(Building& building)
{
    m_workPlace = &building;
}




void Person :: evictHome  ()
{
    m_house = nullptr;
}

void Person :: sack       ()
{
    m_workPlace = nullptr;
}
