#ifndef PERSON_H
#define PERSON_H

class Building;

class Person
{
    public:
        Person();


    private:
        Building* m_workPlace   = nullptr;
        Building* m_house       = nullptr;
};

#endif // PERSON_H
