#pragma once
#include "gameobject.h"
#include "config.h"

class Player : public GameObject {
	float speed = 1.0f;
	float pos_x = CANVAS_WIDTH / 10;
	float pos_y = CANVAS_HEIGHT / 4;
	bool go_back = false;
public:
	Player(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	float get_pos_x() const { return pos_x; };
	float get_pos_y() const { return pos_y; };
	//void set_pos_x(int x) { pos_x = x; };
	//void set_pos_y(int y) { pos_y = y; };
	bool isReturning() const{ return go_back; };
};