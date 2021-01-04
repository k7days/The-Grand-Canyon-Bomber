#pragma once
#include "gameobject.h"
#include "config.h"






class Bomb : public GameObject {
	float pos_xbomb;
	float pos_ybomb;
	float speed;
public:
	void update() override;
	void draw() override;
	void init() override;
	
};