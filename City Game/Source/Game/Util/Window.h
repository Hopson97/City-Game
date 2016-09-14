#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SFML/Graphics.hpp>

namespace Window
{
	constexpr static int HEIGHT = 720;
	constexpr static int WIDTH = 1280;

	void init	();

	void draw	( const sf::Drawable& toDraw );

	void clear	( const sf::Color& color = { 0, 0, 0 } );
	void update ();

	bool isOpen	();

	void checkForClose();
	void close	();

	void destroy();

	const sf::RenderWindow& get();
}

#endif
