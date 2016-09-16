#ifndef LEVEL_VALUES_H
#define LEVEL_VALUES_H

#include "../GUI/GUI.h"

struct Resources
{
    int coins   = 100;
    int wood    = 10;
    int stone   = 10;
    int metal   = 10;
    int food    = 10;

    void operator -=( const Resources& other )
    {
        coins   -= other.coins;
        wood    -= other.wood;
        stone   -= other.stone;
        metal   -= other.metal;
        food    -= other.food;
    }

    void operator +=( const Resources& other )
    {
        coins   += other.coins;
        wood    += other.wood;
        stone   += other.stone;
        metal   += other.metal;
        food    += other.food;
    }
};

struct Statistics
{
    int population              = 0;
    int vacancy                 = 0;
    int unemployedPopulation    = 0;
    int happiness               = 0;
};

class Level_Values
{
    public:
        Level_Values();

        void update ();
        void draw   ();

        Resources   m_resources;
        Statistics  m_statistics;

    private:
        void setUpResourceGUI   ();
        void setUpStatisticGUI  ();

        GUI         m_resourceGUI;
        GUI         m_statsGUI;
};

#endif // LEVEL_VALUES_H
