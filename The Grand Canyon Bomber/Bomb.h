#pragma once
#include "gameobject.h"
#include "config.h"







class Bomb : public GameObject {
	float pos_xbomb=0.0f;
	float pos_ybomb=0.0f;
	float speed=0.0f;
public:
	void update() override;
	void draw() override;
	void init() override;
	void setPosition(float posx, float posy);
};