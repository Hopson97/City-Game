#ifndef RESOURCE_MANAGER_H_INCLUDED
#define RESOURCE_MANAGER_H_INCLUDED

#include "../Util/Debug_Log.h"

template < typename Key, typename Resource >
class Resource_Manager
{
    struct Resource_Type
    {
        int state;
        Resource resource;

        Resource_Type ( int state )
        :   state ( state )
        { }
    };

    public:
        void load( const std::string fileName, Key id  )
        {
            Resource_Type newResource ( m_gameState );

            if ( !newResource.resource.loadFromFile( fileName ) ) {
                throw std::runtime_error ( "Could not load resource from: " + fileName + "!" );
            }

            insert ( id, newResource );
        }


        const Resource& get ( Key id ) const
        {
            try {
                return m_resources.at ( id ).resource;
            } catch ( std::out_of_range e ) {
                throw std::runtime_error ( "(RM) ID " + std::to_string ( static_cast<int> ( id ) ) + " is out of range!" );
            }
        }


        void pushState()
        {
            m_gameState++;
        }

        void popState()
        {
            m_gameState--;

            for ( auto it = m_resources.begin() ; it != m_resources.end() ; ) {
                if ( it->second.state == m_gameState )  {
                    Log::logMessage( "Resource removed.", Log_Type::Resource);
                    m_resources.erase( it++ );
                } else {
                    ++it;
                }
            }
        }

    private:
        void insert ( Key id, Resource_Type resource )
        {
            Log::logMessage( "Resource inserted of ID: " + std::to_string ( static_cast<int> ( id ) )
                           + " during state "            + std::to_string ( m_gameState ),
                             Log_Type::Resource_Load );

            m_resources.insert( std::make_pair( id, resource ) );
        }


        std::map<Key, Resource_Type> m_resources;

        int m_gameState = 0;    //This is so that the game can automatically "deallocate" resources when the game state changes, so that the
                                //map is not filled up with a ton of unneeded resources
};

#endif // RESOURCE_MANAGER_H_INCLUDED
