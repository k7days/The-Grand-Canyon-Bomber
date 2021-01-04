#include "game.h"
#include "graphics.h"
#include "config.h"
#include "Bomb.h"

void Game::update()
{
	//Creating one player 
	if (!player_initialized) {
		player = new Player;
		player_initialized = true;
	}
	if (player) {
		
		player->update();
	}

	//Creating bomb
	if (!bomb_initialized) {
		bomb = new Bomb;
		bomb->setPosition(player->get_pos_x(), player->get_pos_y());
		bomb_initialized = true;
	}
	if (bomb) {
		bomb->update();	
	}
	
}

void Game::draw()
{
	graphics::Brush br;
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

	//draw text
	graphics::Brush br2;
	graphics::drawText(30, 50, 15, "Lives : 3", br2);
	graphics::drawText(150, 50, 15, "Score : ", br2);
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "joystix.ttf");

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
