#pragma once
#include "gameobject.h"
#include "config.h"




class Bomb : public GameObject {
	float pos_xbomb = get_pos_x();
	float pos_ybomb = get_pos_y();
	float speed = get_speed();
public:
	void update() override;
	void draw() override;
	void init() override;
	
};