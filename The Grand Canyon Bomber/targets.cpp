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
	
	if (targetValue == 1)
	{
		br.texture = std::string(ASSET_PATH) + "bball1.png";
	}
	else if ( targetValue == 2)
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

Disk Targets::getCollisionHull() const
{
	Disk disk;
	disk.cx = posx_target;
	disk.cy = posy_target;
	disk.radius = 12.0f;

	return disk;
}
