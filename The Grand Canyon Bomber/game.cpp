#include "game.h"
#include "graphics.h"
#include "config.h"
#include "Bomb.h"
#include <iostream>
#include <random>
#include <ctime>
#include <map>



bool Game::checkCollision(Targets* t)
{
	if (!bomb)
		return false;

	Disk d1 = bomb->getCollisionHull();	



	Disk d2 = t->getCollisionHull();
	float dx = d1.cx - d2.cx;
	float dy = d1.cy - d2.cy;
	if (sqrt(dx * dx + dy * dy) < d1.radius + d2.radius) {
		return true;
	}
	else {
		return false;
	}
		
}

void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_1))
		status = STATUS_PLAYING;
}

void Game::updatePlayingScreen()
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
	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		bomb = new Bomb(*this, this->get_pos_x(), this->get_pos_y(), true);
		//bomb_initialized = true;
		bomb->update();

	}
	
	if (bomb)
		bomb->update();

	for (std::size_t i = 0; i != targets.size(); ++i) {
		if (targets[i]) {
			if (checkCollision(targets[i])) {
				player->setScore(targets[i]->get_value());
				delete targets[i];
				targets[i] = nullptr;
			}
		}
	}

	for (std::size_t i = 0; i != targets.size(); ++i) {
		if (targets[i]) {
			if (!checkCollision(targets[i]) && posy_bomb < 0) {
				bomb->decreaseLives();
			}
		}
	}
}

void Game::drawStartScreen()
{
	graphics::Brush br;
	graphics::drawText(CANVAS_WIDTH/3, 50, 20, "THE  GRAND  CANYON  BOMBER", br);
	graphics::drawText(CANVAS_WIDTH / 2.5f, CANVAS_HEIGHT/2.5f, 15, "1.  START  THE  GAME", br);
	graphics::drawText(CANVAS_WIDTH / 2.5f, CANVAS_HEIGHT / 2.2f, 15, "2.  CREDITS", br);
	graphics::drawText(CANVAS_WIDTH / 2.5f, CANVAS_HEIGHT / 1.93f, 15, "3.  EXIT  THE  GAME", br);
	br.texture = std::string(ASSET_PATH) + "grandcanyon2.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	

}

void Game::drawPlayingScreen()
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
		if (targets[i]) {
			this->set_value(targets[i]);
			targets[i]->draw();
		}
	}


	//draw text
	graphics::Brush br2;
	if (player && bomb) {
		std::string l = std::to_string(bomb->getLives());
		graphics::drawText(30, 50, 15, "Lives : " + l, br2);
		std::string s = std::to_string(player->getScore());
		graphics::drawText(150, 50, 15, "Score : " + s, br2);
	}
}

void Game::update()
{	
	if (status == STATUS_START)
		updateStartScreen();
	else
		updatePlayingScreen();


	
}

void Game::draw()
{
	if (status == STATUS_START)
		drawStartScreen();
	else
		drawPlayingScreen();
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
	//std::srand(std::time(0));
	std::random_device r;
	std::mt19937 gen(r());
	std::discrete_distribution<> d({ 0, 3, 97});
	
	for (int i = 0; i < 1; i++)
	{
		
		for (int x = 20; x < CANVAS_WIDTH; x += 20)
		{
			 
			//int val = (std::rand() % 3) + 1;
			int val = d(gen) + 1;
			Targets* target = new Targets(*this, (float)x, (float)y, val);
			targets.push_back(target);
		}
		y -= 20;

	}

	d = { 50, 43, 7};

	for (int i = 0; i < 3; i++)
	{

		for (int x = 20; x < CANVAS_WIDTH; x += 20)
		{

			//int val = (std::rand() % 3) + 1;
			int val = d(gen)+ 1;
			Targets* target = new Targets(*this, (float)x, (float)y, val);
			targets.push_back(target);
		}
		y -= 20;

	}

	d = {90, 9, 1};

	for (int i = 0; i < 3; i++)
	{

		for (int x = 20; x < CANVAS_WIDTH; x += 20)
		{

			//int val = (std::rand() % 3) + 1;
			int val = d(gen) + 1;
			Targets* target = new Targets(*this, (float)x, (float)y, val);
			targets.push_back(target);
		}
		y -= 20;

	}

	d = { 100, 0, 0 };



	for (int x = 20; x < 61; x += 20) {
		int val = d(gen) + 1;
		Targets* target = new Targets(*this, (float)x, (float)y, val);
		targets.push_back(target);
	}


	y -= 20;

	for (int x = 20; x < 41; x += 20) {
		int val = d(gen) + 1;
		Targets* target = new Targets(*this, (float)x, (float)y, val);
		targets.push_back(target);
	}

	y -= 20;

	for (int x = 20; x < 21; x += 20) {
		int val = d(gen) + 1;
		Targets* target = new Targets(*this, (float)x, (float)y, val);
		targets.push_back(target);
	}

	graphics::Brush br2;
	
	graphics::drawText(30, 50, 15, "Lives : 3", br2);
	graphics::drawText(150, 50, 15, "Score : 0", br2);
	
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

	for (Targets* i : targets) {
		if (i)
			delete i;
	}

	
}
//float Game::window2canvasX(float x)
//{
//	return x * CANVAS_WIDTH / (float)window_width;
//}
//
//float Game::window2canvasY(float y)
//{
//	return y * CANVAS_HEIGHT / (float)window_height;
//}
