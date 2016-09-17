#ifndef City_VALUES_H
#define City_VALUES_H

#include "../GUI/GUI.h"

#include <ostream>

struct Resources
{
    Resources() = default;
    Resources( int coins,
               int wood,
               int stone,
               int metal,
               int food )
               : coins ( coins )
               , wood  ( wood  )
               , stone ( stone )
               , metal ( metal )
               , food  ( food  ) {}



    int coins   = 0;
    int wood    = 0;
    int stone   = 0;
    int metal   = 0;
    int food    = 0;

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

    bool operator >= ( const Resources& other )
    {
        return  ( coins >= other.coins  ) &&
                ( wood  >= other.wood   ) &&
                ( stone >= other.stone  ) &&
                ( metal >= other.metal  ) &&
                ( food  >= other.food   );
    }
};

struct Statistics
{
    Statistics () = default;

    Statistics ( int population,
                 int vacancy,
                 int unemployedPopulation,
                 int happiness )
    :   population              ( population           )
    ,   vacancy                 ( vacancy              )
    ,   unemployedPopulation    ( unemployedPopulation )
    ,   happiness               ( happiness            )
    {}


    int population              = 0;
    int vacancy                 = 0;
    int unemployedPopulation    = 0;
    int happiness               = 0;

    void operator +=( const Statistics& other )
    {
        population              += other.population;
        vacancy                 += other.vacancy;
        unemployedPopulation    += other.unemployedPopulation;
        happiness               += other.happiness;
    }

};

class City_Values
{
    public:
        City_Values();

        void update ();
        void draw   ();

        Resources   m_resources;
        Resources   m_dailyResourceChange;
        Statistics  m_statistics;

        void newDay();

    private:
        void setUpResourceGUI   ();
        void setUpStatisticGUI  ();

        GUI         m_resourceGUI;
        GUI         m_statsGUI;
};

#endif // City_VALUES_H
