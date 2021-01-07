#include "targets.h"
#include "graphics.h"
#include "config.h"
#include <vector>

Targets::Targets(const Game& mygame, int x, int y)
	:GameObject(mygame)
{
	posx_target = x;
	posy_target = y;
}

void Targets::update()
{
	
}

void Targets::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "bball1.png";
	br.outline_opacity = 0.0f;
	
	graphics::drawRect(posx_target, posy_target, 20, 20, br);

}

void Targets::init()
{
}
