#pragma once
#include "Player.h"
#include "Bomb.h"



class Game {
	Player* player = nullptr;
	bool player_initialized = false;
	Bomb* bomb = nullptr;
public:
	void update();
	void draw();
	void init();
	Game();
	~Game();
};