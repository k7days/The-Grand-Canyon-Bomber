#include "targets.h"
#include "graphics.h"
#include "config.h"
#include <vector>
#include <random>

Targets::Targets(const Game& mygame, float x, float y, int val)
	:GameObject(mygame)
{
	posx_target = x;
	posy_target = y;
	targetValue = val;
}

void Targets::update()
{
	
}

void Targets::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;

	int random = std::rand() % 4;
	
	if (random == 1)
	{
		br.texture = std::string(ASSET_PATH) + "bball1.png";
	}
	else if ( random == 2)
	{
		br.texture = std::string(ASSET_PATH) + "bball2.png";
	}
	else
	{
		br.texture = std::string(ASSET_PATH) + "bball3.png";
	}
	
	graphics::drawRect(posx_target, posy_target, 20, 20, br);

}

void Targets::init()
{
}
