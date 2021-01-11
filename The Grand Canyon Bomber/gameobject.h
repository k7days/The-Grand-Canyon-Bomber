#pragma once
#include "util.h"

class Collidable {
public:
	virtual Disk getCollisionHull() const = 0;
};


class GameObject {
protected:
	const class Game & game;
public:
	GameObject(const class Game& mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	float get_pos_x();
	float get_pos_y();
	float get_speed();
};