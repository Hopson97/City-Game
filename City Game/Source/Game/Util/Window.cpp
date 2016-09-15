#include "Window.h"

#include <memory>

namespace Window
{
	//This is all not in a class because it is very annoying having to pass a render window around to do stuff.
	//It is a pointer to a window because I can initilise it when I want to.
	namespace
	{
        std::unique_ptr<sf::RenderWindow> window;
	}

	void init()
	{
		window = std::make_unique<sf::RenderWindow>( sf::VideoMode( WIDTH, HEIGHT ), "Window" );
		window->setFramerateLimit ( 120 );
		window->setMouseCursorVisible ( false );
	}

	void destroy()
	{
		window = nullptr;
	}

	void draw( const sf::Drawable& toDraw )
	{
		window->draw( toDraw );
	}

	void clear( const sf::Color& color )
	{
		window->clear( color );
	}

	void update()
	{
		window->display();
	}

	bool isOpen()
	{
		return window->isOpen();
	}

	void checkForClose()
	{
		sf::Event e;
		while ( window->pollEvent( e ) ) {
			switch( e.type )
			{
				case sf::Event::Closed:
					close();
					break;
                default:
                    break;
			}
		}
	}

	void close()
	{
		window->close();
	}

	const sf::RenderWindow& get()
	{
	    return *window;
	}
}
