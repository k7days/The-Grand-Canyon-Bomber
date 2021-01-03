#pragma once
#include "gameobject.h"
#include "config.h"

class Player : public GameObject {
	float speed = 1.0f;
	float pos_x = CANVAS_WIDTH / 10;
public:
	void update() override;
	void draw() override;
	void init() override;

};