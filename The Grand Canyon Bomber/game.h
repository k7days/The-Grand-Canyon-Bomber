#pragma once
#include "Player.h"


class Game {
	Player* player = nullptr;
	bool player_initialized = false;
public:
	void update();
	void draw();
	void init();
	Game();
	~Game();
};