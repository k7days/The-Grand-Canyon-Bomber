#pragma once
#include "Player.h"
#include "config.h"

class Bomb : public Player {
	bool falling = false;
	float posx_bomb, posy_bomb;
public:
	void update() override;
	void draw() override;
	void init() override;
	/*float get_pos_x() { return posx_bomb; };
	float get_pos_y() { return posy_bomb; };
	void set_pos_x(float x) { posx_bomb = x; };
	void set_pos_y(float y) { posy_bomb = y; };
	void setPosition(float posx, float posy);*/
	bool isFalling() { return falling; };
	void setFalling(bool fall) { falling = fall; };
};