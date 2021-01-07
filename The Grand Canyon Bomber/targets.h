#pragma once

#include "gameobject.h"
#include <vector>

class Targets : public GameObject
{
	float posx_target, posy_target;
public:
	Targets(const class Game& mygame, int x, int y);
	void update() override;
	void draw() override;
	void init() override;
};