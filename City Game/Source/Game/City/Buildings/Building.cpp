#include "Building.h"

#include "Building_Data.h"

Building :: Building ( Building_Data& data, const sf::Vector2f& position )
:   data      ( data )
,   position  ( position )
,   bounds    ( position, data.getSize() )
{ }

void Building :: draw ()
{
    data.draw ( position );
}

int Building :: getOccupantCount() const
{
    return m_people.occupants.size() | m_people.workers.size();
}

bool Building :: isSpacesAvalibleToLive() const
{
    return ( m_people.occupants.size() < (size_t)data.getStats().vacancy );
}

bool Building::isSpaceForWork() const
{
    return ( m_people.workers.size() < (size_t)data.getStats().jobs );
}


void Building :: addPerson ( PersonPtr person)
{
    m_people.occupants.push_back( person );
}

void Building::addWorker(PersonPtr person)
{
    m_people.workers.push_back( person );
}


Person_Group& Building :: destroy ()
{
    for ( auto& person : m_people.occupants ) {
        person->evictHome();
    }
    for ( auto& person : m_people.workers ) {
        person->sack();
    }

    return m_people;
}

