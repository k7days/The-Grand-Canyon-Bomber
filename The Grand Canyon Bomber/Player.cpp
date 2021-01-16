#include "Player.h"
#include "graphics.h"
#include "config.h"
#include"game.h"

Player::Player(const Game& mygame)
	:GameObject(mygame)
{
	score = 0;
}


void Player::update()
{
	//Plane movement
	if (this->pos_x <= CANVAS_WIDTH + 80 && go_back == false) {
		this->pos_x += speed * graphics::getDeltaTime() / 10.0f;
	}
	else {
		go_back = true;
		this->pos_x -= speed * graphics::getDeltaTime() / 10.0f;
		if (pos_x < -80) { go_back = false; }
	}

}

void Player::draw()
{
	//Draw plane based on it's direction
	graphics::Brush br;
	if (go_back == false) {
		br.texture = std::string(ASSET_PATH) + "fedexright.png";
	}
	else {
		br.texture = std::string(ASSET_PATH) + "fedex.png";
	}
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, CANVAS_WIDTH / 6, CANVAS_HEIGHT / 8, br);

	/*char info[40];
	sprintf_s(info, "(%6.2f, %6.2f))", pos_x, pos_y);
	graphics::drawText(80, 120, 20, info, br);*/
}


void Player::init()
{
	/*pos_x = CANVAS_WIDTH / 2;
	pos_y = CANVAS_HEIGHT / 4;
	speed = 1.0f;*/

}