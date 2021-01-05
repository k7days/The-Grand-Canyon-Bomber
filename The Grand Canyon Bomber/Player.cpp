#include "Player.h"
#include "graphics.h"
#include "config.h"

void Player::update()
{
	//Plane movement
	if (pos_x <= CANVAS_WIDTH + 80 && go_back == false) {
		pos_x += speed * graphics::getDeltaTime() / 10.0f;
	}
	else {
		go_back = true;
		pos_x -= speed * graphics::getDeltaTime() / 10.0f;
		if (pos_x < -80) { go_back = false; }
	}
}

void Player::draw()
{
	//Draw plane based on it's direction
	graphics::Brush br;
	if (go_back == false) {
		br.texture = std::string(ASSET_PATH) + "ANA.png";
	}
	else {
		br.texture = std::string(ASSET_PATH) + "ANAleft.png";
	}
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, CANVAS_WIDTH / 6, CANVAS_HEIGHT / 8, br);

	char info[40];
	sprintf_s(info, "(%6.2f, %6.2f))", pos_x, pos_y);
	graphics::drawText(80, 120, 20, info, br);
}


void Player::init()
{
	pos_x = CANVAS_WIDTH / 2;
	pos_y = CANVAS_HEIGHT / 4;

}

