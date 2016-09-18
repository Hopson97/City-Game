#ifndef PERSON_H
#define PERSON_H

class Building;

#include <memory>
#include <vector>

class Person
{
    public:
        bool isHomeless   ();
        bool isUnemployed ();

        void setHouse   ( Building& building );
        void setWork    ( Building& building );

        void evictHome  ();
        void sack       ();

    private:
        Building* m_workPlace   = nullptr;
        Building* m_house       = nullptr;
};

typedef std::shared_ptr<Person> PersonPtr;
typedef std::vector<PersonPtr> Person_Ptr_Vector;

#endif // PERSON_H
