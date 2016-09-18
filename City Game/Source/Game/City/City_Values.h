#ifndef City_VALUES_H
#define City_VALUES_H

#include "../GUI/GUI.h"

#include <memory>
#include "Buildings/Building.h"

#include <ostream>

struct Resources
{
    Resources() = default;
    Resources( int coins,
               int wood,
               int stone,
               int metal,
               int food,
               int unemployedPopulation )
               : coins ( coins )
               , wood  ( wood  )
               , stone ( stone )
               , metal ( metal )
               , food  ( food  )
               , unemployedPopulation   ( unemployedPopulation ){}



    int coins   = 0;
    int wood    = 0;
    int stone   = 0;
    int metal   = 0;
    int food    = 0;
    int unemployedPopulation    = 0;

    void operator -=( const Resources& other )
    {
        coins   -= other.coins;
        wood    -= other.wood;
        stone   -= other.stone;
        metal   -= other.metal;
        food    -= other.food;
        unemployedPopulation    -= other.unemployedPopulation;
    }

    void operator +=( const Resources& other )
    {
        coins   += other.coins;
        wood    += other.wood;
        stone   += other.stone;
        metal   += other.metal;
        food    += other.food;
        unemployedPopulation    += other.unemployedPopulation;
    }

    bool operator > ( const Resources& other ) const
    {
        return  ( coins > other.coins  ) ||
                ( wood  > other.wood   ) ||
                ( stone > other.stone  ) ||
                ( metal > other.metal  ) ||
                ( food  > other.food   ) ||
                ( unemployedPopulation > other.unemployedPopulation );
    }
};

struct Statistics
{
    Statistics () = default;

    Statistics ( int population,
                 int vacancy,
                 int happiness )
    :   population              ( population           )
    ,   vacancy                 ( vacancy              )
    ,   happiness               ( happiness            )
    {}


    int population              = 0;
    int vacancy                 = 0;
    int happiness               = 0;

    void operator +=( const Statistics& other )
    {
        population              += other.population;
        vacancy                 += other.vacancy;
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

        // BAG GUI

        void newDay(  const std::vector<std::shared_ptr<Building>>& buildings  );

    private:
        void tryDoRates         ( int& rate, int amount );

        void setUpResourceGUI   ();
        void setUpStatisticGUI  ();

        GUI         m_resourceGUI;
        GUI         m_statsGUI;
};

#endif // City_VALUES_H
