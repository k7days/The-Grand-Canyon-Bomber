#pragma once
#include "Player.h"
#include "config.h"

class Bomb : public GameObject, public Collidable {
	bool falling = false;
	float posx_bomb, posy_bomb;
	float speed = 1.0f;
	bool returning = false;
public:
	Bomb(const class Game& mygame, float posx, float posy, bool fall);
	void update() override;
	void draw() override;
	void init() override;
	bool isFalling() { return falling; };
	void setFalling(bool fall) { falling = fall; };
	Disk getCollisionHull() const override;
	float get_pos_x_bomb() const { return posx_bomb; };
	float get_pos_y_bomb() const { return posy_bomb; };
};