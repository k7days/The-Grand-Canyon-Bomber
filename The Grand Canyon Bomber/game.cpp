#include "game.h"
#include "graphics.h"
#include "config.h"
#include "Bomb.h"
#include <iostream>
#include <random>


void Game::update()
{
	//Creating one player 
	if (!player_initialized) {
		player = new Player(*this);
		player_initialized = true;
	}
	if (player) {
		this->set_pos_x(player);
		this->set_pos_y(player);
		this->setReturning(player);
		player->update();	
	}

	//Creating bomb
	if (!bomb_initialized) {
		bomb = new Bomb(*this);
		bomb_initialized = true;
		
	}
	if (bomb) 
		bomb->update();
	
}

void Game::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "grandcanyon2.png";
	//draw background
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	//draw player
	if (player) {
		player->draw();
	}
	//draw bomb
	if (bomb) {
		bomb->draw();
		
	}

	

	for (std::size_t i = 0; i != targets.size(); ++i) {
		//this->set_value(&targets[i]);
		targets[i].draw();
	}
	

	//draw text
	graphics::Brush br2;
	graphics::drawText(30, 50, 15, "Lives : 3", br2);
	graphics::drawText(150, 50, 15, "Score : ", br2);
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "joystix.ttf");

	if (bomb)
		bomb->init();
	if (player) 
	{
		player->init();
		this->set_pos_x(player);
		this->set_pos_y(player);
	}
	
	int y = CANVAS_HEIGHT - 20;
	
	for (int i = 0; i < 7; i++)
	{
		
		for (int x = 20; x < CANVAS_WIDTH; x += 20)
		{
			int val = (rand() % 3) + 1;
			Targets* target = new Targets(*this, (float)x, (float)y, val);
			targets.push_back(*target);
		}
		y -= 20;

	}

}

Game::Game()
{
}

Game::~Game()
{
	if (player) {
		delete player;
	}

	if (bomb) {
		delete bomb;
	}

}
