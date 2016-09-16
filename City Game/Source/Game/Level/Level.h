#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "Building_Type.h"

#include "Level_Values.h"

class Level
{
    public:
        Level( const std::string& name );

        void update ( float dt );
        void draw   ();

        void addBuilding ( std::unique_ptr<Building> b );

    private:
        void init ();
        void loadFloatRectToVector ( std::vector<sf::FloatRect>& vect, std::ifstream& inFile );

        sf::RectangleShape m_background;

        sf::String m_name;

        Level_Values m_values;

        std::vector<sf::FloatRect> m_waterSections;
        std::vector<sf::FloatRect> m_groundSections;
        std::vector<sf::FloatRect> m_noBuildSections;

        std::vector<std::unique_ptr<Building>> m_buildings;

        static
        constexpr int   WIDTH  = 1280,
                        HEIGHT = 600;
};

#endif // LEVEL_H
