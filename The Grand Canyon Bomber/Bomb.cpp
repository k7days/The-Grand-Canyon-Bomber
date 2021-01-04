#include "Bomb.h"
#include "config.h"
#include "graphics.h"
#include "game.h"



void Bomb::update()
{
}

void Bomb::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "bomb.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_xbomb, pos_ybomb, 20, 20, br);
}

void Bomb::init()
{
	
}

void Bomb::setPosition(float posx, float posy) {
	pos_xbomb = posx;
	pos_ybomb = posy;
}
