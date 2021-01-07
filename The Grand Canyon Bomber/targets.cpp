#include "targets.h"
#include "graphics.h"
#include "config.h"

Targets::Targets(const Game& mygame)
	:GameObject(mygame)
{
}

void Targets::update()
{
	
}

void Targets::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "bball1.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 4, 20, 20, br);
}

void Targets::init()
{
}
