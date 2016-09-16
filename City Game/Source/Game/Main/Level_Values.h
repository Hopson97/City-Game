#ifndef LEVEL_VALUES_H
#define LEVEL_VALUES_H

#include "../GUI/GUI.h"

class Level_Values
{
    struct Resources
    {
        int coins   = 100;
        int wood    = 10;
        int stone   = 10;
        int metal   = 10;
        int food    = 10;
    };

    struct Statistics
    {
        int population              = 0;
        int vacancy                 = 0;
        int unemployedPopulation    = 0;
        int happiness               = 0;
    };

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
