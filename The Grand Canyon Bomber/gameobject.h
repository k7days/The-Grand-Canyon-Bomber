#pragma once

class GameObject {
	

public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
	float get_pos_x();
	float get_pos_y();
	float get_speed();
};