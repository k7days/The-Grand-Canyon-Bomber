#pragma once
#include "Player.h"
#include "Bomb.h"
#include "targets.h"
#include <vector>



class Game {
	typedef enum{STATUS_START, STATUS_PLAYING, STATUS_END} status_t;
	Player* player = nullptr;
	Bomb* bomb = nullptr;
	Targets* target = nullptr;
	bool player_initialized = false;
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
	void updateEndScreen();
	void drawEndScreen();
	bool collided;
	bool bomb_initialized = false;
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
	float get_pos_x_bomb() const { return posx_bomb; };
	float get_pos_y_bomb() const { return posy_bomb; };
	void set_pos_x_bomb(Bomb* bomb) { pos_x = bomb->get_pos_x_bomb(); }
	void set_pos_y_bomb(Bomb* bomb) { pos_y = bomb->get_pos_y_bomb(); }
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