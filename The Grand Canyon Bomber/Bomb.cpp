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
	graphics::drawRect(pos_xbomb, pos_ybomb, CANVAS_WIDTH / 100, CANVAS_HEIGHT / 10, br);
}

void Bomb::init()
{
}


