#include "Game.h"

#include <SFML/System.hpp>
#include <memory>

#include "Util/FPS_Counter.h"
#include "Util/Window.h"
#include "Util/Mouse.h"
#include "States/Splash_Screen.h"

//They are unique pointers so that the life time of these objects can
//be controlled.
//Also, they should only exist once, hence the use of static functions in
//the game class to access these.
namespace
{
    std::unique_ptr<Font_Manager>    m_fontManager;
    std::unique_ptr<Music_Manager>   m_musicManager;
    std::unique_ptr<Sound_Manager>   m_soundManager;
    std::unique_ptr<Texture_Manager> m_textureManager;
}

Game::Game()
{
	Window::init();
	Mouse::init();

    m_fontManager       = std::make_unique<Font_Manager>    ();
    m_musicManager      = std::make_unique<Music_Manager>   ();
    m_soundManager      = std::make_unique<Sound_Manager>   ();
    m_textureManager    = std::make_unique<Texture_Manager> ();

    loadFont( Res::getFont("rs"), Font_Name::Rs);

	pushState( std::make_unique<State::Splash_Screen>( *this ) );
}

void Game::run()
{
    FPS_Counter counter;
	sf::Clock clock;
	while ( Window::isOpen() ) {
		Window::checkForClose();
		if( !Window::isOpen() )
			break;

		float dt = clock.restart().asSeconds();

		Window::clear();
		Mouse::update();

		m_stateHandler.peekState()->input	(dt);
		m_stateHandler.peekState()->update	(dt);
		m_stateHandler.peekState()->draw	(dt);

		Mouse::draw();
		counter.update();
		counter.drawFPS();

		Window::update();
	}
}

//General functions that allow quick access to the texture managers and such, as well as states
void Game :: loadFont ( const std::string& fileName, Font_Name name )
{
    m_fontManager->load( fileName, name );
}


void Game :: loadSound ( const std::string& fileName, Sound_Name name )
{
    m_soundManager->load( fileName, name );
}


void Game :: loadTexture ( const std::string& fileName, Texture_Name name, bool makeSmooth, bool repeated )
{
    m_textureManager->load ( fileName, name );
}


const sf::Font& Game::getFont( Font_Name name )
{
    return m_fontManager->get ( name );
}


const sf::Texture& Game :: getTexture ( Texture_Name name )
{
    return m_textureManager->get( name );
}


const sf::SoundBuffer& Game :: getSound (Sound_Name name)
{
    return m_soundManager->get( name );
}


void Game :: changeSong ( const std::string& name )
{
    m_musicManager->playSong( name );
}


void Game :: popState()
{
    if ( m_stateHandler.popState() ) {
        m_fontManager   ->popState();
        m_soundManager  ->popState();
        m_textureManager->popState();
    }
    Log::logMessage( "Finished popping game state.", Log_Type::State_Switch );
}

void Game::pushManagerStates()
{
    m_fontManager   ->pushState();
    m_soundManager  ->pushState();
    m_textureManager->pushState();
}

void Game :: pushState ( StatePtr state )
{
    m_stateHandler.pushState( std::move(state) );

    Log::logMessage( "Finished pushing game state.", Log_Type::State_Switch );
}

void Game :: changeState ( StatePtr state )
{
    popState();
    pushState( std::move ( state ) );
    Log::logMessage( "Finished changing game state.", Log_Type::State_Switch );
}

Game::~Game()
{
	Window::destroy();
}

