
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML\Graphics.hpp> 
#include <string> 

#define FREE '0'
#define BLOCKED '1'
#define ENEMY '2'

namespace gconsts
{
	namespace Window
	{
		static std::string SCREEN_TITLE("Dungeon Crawler - INDEV");
		static const int WIDTH(1024);
		static const int HEIGHT(640);
	}

	namespace States
	{
		static const int GAMEPLAY_STATE_ID(1);
	}

	namespace Gameplay
	{
		static const int TILESIZE(64);
		static const int GAME_VIEW_WIDTH(512);
		static const int GAME_VIEW_HEIGHT(480);
		static const int GUI_VIEW_WIDTH(128);
		static const int GUI_VIEW_HEIGHT(480);
		static const std::string BAT_TYPE = "bat";
	}

	namespace Assets
	{
		static const std::string MAP_LOCATION("res//test.scr");
		static const std::string FONT_LOCATION("res//fonts//seriphim.ttf");
		static const std::string PLAYER_TEXTURE_LOCATION("res//entities//fighter.png");
		static const std::string PLAYER_TEXTURE_RECTS("res//entities//fighterrects.txt");
		static const std::string MAP_TEXT_LOC("res//");
	}

	namespace AITextureRectangles
	{
		static const int FLAP_UP = 0, FLAP_DOWN = 1;
	}

	namespace UtilStruct
	{
		struct EntityTween
		{
			float currentTime = 0.f;
			float startValue = 0.f;
			float delta = 0.f;
			float duration = 0.f;
		};
		struct TileData
		{
			bool blocked; 
			char value;
			sf::FloatRect bounds;
		};
	}

}

#endif