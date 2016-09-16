#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "Buildings/Building.h"

#include "Level_Values.h"

#include "Builder.h"

typedef std::vector<sf::FloatRect> FloatRect_Vector;

class Level
{
    public:
        Level( const std::string& name );

        void update ( float dt );
        void draw   ();

        void addBuilding ( std::shared_ptr<Building> b );

        const FloatRect_Vector& getWaterSections    () const;
        const FloatRect_Vector& getGroundSections   () const;
        const FloatRect_Vector& getNoBuildSections  () const;

    private:
        void init ();
        void loadFloatRectToVector ( std::vector<sf::FloatRect>& vect, std::ifstream& inFile );

        sf::RectangleShape m_background;

        sf::String      m_name;

        Level_Values    m_values;
        Builder         m_builder;

        FloatRect_Vector m_waterSections;
        FloatRect_Vector m_groundSections;
        FloatRect_Vector m_noBuildSections;

        std::vector<std::shared_ptr<Building>> m_buildings;

        std::vector<std::shared_ptr<Building>> m_houses;



        static
        constexpr int   WIDTH  = 1280,
                        HEIGHT = 600;
};

#endif // LEVEL_H
