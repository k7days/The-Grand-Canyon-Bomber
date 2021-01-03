#pragma once

class GameObject {
	
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
};