#pragma once
#include "Player.h"
#include "Bomb.h"
#include "targets.h"
#include <vector>



class Game {
	typedef enum{STATUS_START, STATUS_PLAYING} status_t;
	Player* player = nullptr;
	Bomb* bomb = nullptr;
	Targets* target = nullptr;
	bool player_initialized = false;
	bool bomb_initialized = false;
	bool fall = false;
	float pos_x, pos_y, posx_bomb, posy_bomb;
	std::vector<Targets*> targets;
	bool returning;
	int targetval;
	bool checkCollision(Targets* t);
	status_t status = STATUS_START;
	void updateStartScreen();
	void updatePlayingScreen();
	void drawStartScreen();
	void drawPlayingScreen();
	unsigned int window_width = WINDOW_WIDTH, window_height = WINDOW_HEIGHT;
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
	int get_value() const { return targetval; }
	void set_value(Targets* target) { targetval = target->get_value(); }
	/*unsigned int getWindowWidth() { return WINDOW_WIDTH; }
	unsigned int getWindowHeight() { return WINDOW_HEIGHT; }
	void setWindowDimensions(unsigned int w, unsigned int h) {
		window_width = w;
		window_height = h;	
	}
	float window2canvasX(float x);
	float window2canvasY(float y);*/

};