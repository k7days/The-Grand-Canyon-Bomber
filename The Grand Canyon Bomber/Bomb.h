#pragma once
#include "Player.h"
#include "config.h"

class Bomb : public GameObject, public Collidable {
	bool falling = false;
	float posx_bomb, posy_bomb;
	float speed = 1.0f;
	bool returning = false;
public:
	Bomb(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	bool isFalling() { return falling; };
	void setFalling(bool fall) { falling = fall; };
	Disk getCollisionHull() const override;
};