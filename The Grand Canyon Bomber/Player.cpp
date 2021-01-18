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
		br.texture = std::string(ASSET_PATH) + "dc6.png";
	}
	else {
		br.texture = std::string(ASSET_PATH) + "dc6left.png";
	}
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x, pos_y, CANVAS_WIDTH / 6, CANVAS_HEIGHT / 8, br);

	
}


void Player::init()
{
	
}