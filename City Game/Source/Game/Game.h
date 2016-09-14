#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED


#include <SFML/Graphics.hpp>

#include "States\state_handler.h"

#include "Managers/music_manager.h"
#include "Managers/resource_identifier.h"

class Game
{
	public:
		Game		();

		void run	();

		static void loadFont       ( const std::string& fileName, Font_Name name   );
		static void loadSound      ( const std::string& fileName, Sound_Name name  );
		static void loadTexture    ( const std::string& fileName, Texture_Name name, bool makeSmooth = true, bool repeated = false );

		static const sf::Font&    getFont      ( Font_Name name    );
		static const sf::Texture& getTexture   ( Texture_Name name );
		static const sf::SoundBuffer& getSound ( Sound_Name name   );

		void popState   ();
		void pushState  ( StatePtr state );
		void changeState( StatePtr state );

		void changeSong( const std::string& name );

		~Game		();

	private:
		State_Handler m_stateHandler;
};

#endif // GAME_H_INCLUDED
