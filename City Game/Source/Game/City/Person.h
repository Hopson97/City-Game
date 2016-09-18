#ifndef PERSON_H
#define PERSON_H

class Building;

class Person
{
    public:
        Person();


    private:
        Building* m_workPlace;
        Building* m_house;
};

#endif // PERSON_H
