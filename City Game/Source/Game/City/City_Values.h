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
               int food)
               : coins ( coins )
               , wood  ( wood  )
               , stone ( stone )
               , metal ( metal )
               , food  ( food  ){}



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

    bool operator > ( const Resources& other ) const
    {
        return  ( coins > other.coins  ) ||
                ( wood  > other.wood   ) ||
                ( stone > other.stone  ) ||
                ( metal > other.metal  ) ||
                ( food  > other.food   );
    }

    Resources operator /( int division ) const
    {
        return {
            coins   / division,
            wood    / division,
            stone   / division,
            metal   / division,
            food    / division,
        };
    }
};

struct Statistics
{
    Statistics () = default;

    Statistics ( int population,
                 int vacancy,
                 int happiness ,
                 int unemployedPopulation,
                 int jobs,
                 int homeless )
    :   population              ( population           )
    ,   vacancy                 ( vacancy              )
    ,   happiness               ( happiness            )
    ,   unemployedPopulation    ( unemployedPopulation )
    ,   jobs                    ( jobs )
    ,   homeless                ( homeless )
    {}


    int population              = 0;
    int vacancy                 = 0;
    int happiness               = 0;
    int unemployedPopulation    = 0;
    int jobs                    = 0;
    int homeless                = 0;

    void operator +=( const Statistics& other )
    {
        population              += other.population;
        vacancy                 += other.vacancy;
        happiness               += other.happiness;
        jobs                    += other.jobs;
    }

    void operator -=( const Statistics& other )
    {
        population              -= other.population;
        vacancy                 -= other.vacancy;
        happiness               -= other.happiness;
        jobs                    -= other.jobs;
    }

};

class City_Values
{
    public:
        City_Values();

        void update ();
        void draw   ();

        Resources   m_resources;
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
