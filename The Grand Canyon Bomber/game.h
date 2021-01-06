#pragma once
#include "Player.h"
#include "Bomb.h"



class Game {
	Player* player = nullptr;
	bool player_initialized = false;
	Bomb* bomb = nullptr;
	bool bomb_initialized = false;
	bool fall = false;
	float pos_x, pos_y, posx_bomb, posy_bomb;
	bool returning;
public:
	void update() ;
	void draw() ;
	void init() ;
	Game();
	~Game();
	float get_pos_x() const { return pos_x; };
	float get_pos_y() const { return pos_y; };
	void set_pos_x(Player* player) { pos_x = player->get_pos_x(); }
	void set_pos_y(Player* player) { pos_y = player->get_pos_y(); }
	bool isReturning() const { return returning; }
	void setReturning(Player* player) { returning = player->isReturning(); }
};