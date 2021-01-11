#pragma once

#include "gameobject.h"
#include <vector>

class Targets : public GameObject, public Collidable
{
	float posx_target, posy_target;
	int targetValue;
public:
	Targets(const class Game& mygame, float x, float y, int val);
	void update() override;
	void draw() override;
	void init() override;
	int get_value() { return targetValue; }
	Disk getCollisionHull() const override;
};