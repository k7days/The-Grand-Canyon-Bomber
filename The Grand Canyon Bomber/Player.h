#pragma once
#include "gameobject.h"
#include "config.h"

class Player : public GameObject {
	float speed = 1.0f;
	float pos_x = CANVAS_WIDTH / 10;
	float pos_y = CANVAS_HEIGHT / 4;
	bool go_back = false;
public:
	void update() override;
	void draw() override;
	void init() override;
	float get_pos_x();
	float get_pos_y();


};