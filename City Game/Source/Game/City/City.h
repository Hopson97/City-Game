#ifndef CITY_H
#define CITY_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "Buildings/Building.h"

#include "City_Values.h"

#include "Buildings/Builder.h"

#include "Person.h"

typedef std::vector<sf::FloatRect> FloatRect_Vector;
typedef std::shared_ptr<Building> BuildingPtr;
typedef std::vector<std::shared_ptr<Building>> Building_Ptr_Vector;

class City
{
    public:
        City( const std::string& name );

        void update ( float dt );
        void draw   ();

        void tryAddBuilding ( std::shared_ptr<Building> b );

        const FloatRect_Vector& getWaterSections    () const;
        const FloatRect_Vector& getGroundSections   () const;
        const FloatRect_Vector& getNoBuildSections  () const;

        const Building_Ptr_Vector& getBuildings     () const;

        void tryDestory     ( sf::FloatRect area );

    private:
        void addBuilding    ( std::shared_ptr<Building> b );
        void addPerson      ();

        void removeBuilding ( Building& b );

        void init ();
        void loadFloatRectToVector ( std::vector<sf::FloatRect>& vect, std::ifstream& inFile );

        void nextDay    ();

        sf::RectangleShape m_background;

        sf::String      m_name;

        City_Values     m_values;
        Builder         m_builder;

        FloatRect_Vector m_waterSections;
        FloatRect_Vector m_groundSections;
        FloatRect_Vector m_noBuildSections;

        Building_Ptr_Vector m_buildings;
        Building_Ptr_Vector m_houses;
        Building_Ptr_Vector m_workPlaces;

        sf::Time    m_dayLength = sf::seconds( 30 );
        sf::Clock   m_dayTimer;

        GUI m_actionGUI;
        GUI m_newDayGUI;

        int m_day = 0;
        std::vector<PersonPtr> m_people;

        static
        constexpr int   WIDTH  = 1280,
                        HEIGHT = 600;
};

#endif // CITY_H
