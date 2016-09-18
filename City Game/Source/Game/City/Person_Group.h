#ifndef PERSON_GROUP_H_INCLUDED
#define PERSON_GROUP_H_INCLUDED

#include <vector>

#include "Person.h"

struct Person_Group
{
    std::vector<PersonPtr> workers;
    std::vector<PersonPtr> occupants;

    void clear()
    {
        workers.clear();
        occupants.clear();
    }
};


#endif // PERSON_GROUP_H_INCLUDED
