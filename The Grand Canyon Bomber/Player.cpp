#include "Player.h"
#include "graphics.h"
#include "config.h"

void Player::update()
{
		pos_x += speed * graphics::getDeltaTime() / 10.0f;
		if (pos_x > CANVAS_WIDTH) {
			pos_x -= speed * graphics::getDeltaTime() / 10.0f;
		}
	
}

void Player::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "ANA.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, CANVAS_HEIGHT / 4, CANVAS_WIDTH / 6, CANVAS_HEIGHT / 8, br);
}

void Player::init()
{
}
