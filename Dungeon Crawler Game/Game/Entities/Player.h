#ifndef PLAYER_H
#define PLAYER_H


#include <fstream>
#include <SFML\Graphics.hpp> 
#include "Entities.h"
#include "..\Map\TiledMap.h"
#include "..\Constants\Constants.h"
#include "..\Utils\MathUtils.h"
#include <iostream>

class Player :
	public Entity
{
public:
	Player(sf::Vector2i, TiledMap*, sf::RenderWindow*, sf::RenderTexture*);
	~Player();
	bool init();
	void render() const;
	void update(const sf::Time&);
	void handleEvents(sf::Event&, const sf::Time&);
	bool hasPlayerTurned() const;
	void setTurn(bool);
	sf::IntRect getAttackTileLocation() const;
	bool isAttacking() const;
	int getAttackDamage() const;
	void endAttackTurn();
private:
	bool loadTextureRect(void);
	void setTextureRect(int);
	void handleTween(const sf::Time&);
	//Param: start value, change in value
	void setupTween(float, float);
	void resetTween();
	sf::IntRect getAutoMeleeSquare()const;
private:
	struct TextureRects
	{
		sf::IntRect down, up, left, right;
		sf::IntRect  attackDown, attackUp, attackLeft, attackRight;
	};
	TextureRects txtRects_;
	const int W_DOWN = 0, W_UP = 1, W_LEFT = 2, W_RIGHT = 3;
	const int A_DOWN = 4, A_UP = 5, A_LEFT = 6, A_RIGHT = 7;
	const int TILESIZE;
	const float ANIMATION_LENGTH = 0.5f;
	const float TWEEN_LENGTH = 0.25f;
	TiledMap * map_;
	sf::RectangleShape shape_;
	sf::Time attackTime;
	int state_;
	int attackDamage_;
	bool attacking_ = false;
	bool endOfTurn_ = false;
	bool animationActive_ = false;
	bool tweenActive_ = false;
	float tweenTimer_ = 0.f;
	char direc_ = '0';
	gconsts::UtilStruct::EntityTween tweenData_;
};

#endif
