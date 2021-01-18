#include "game.h"
#include "graphics.h"
#include "config.h"
#include "Bomb.h"
#include <iostream>
#include <random>
//#include <ctime>
//#include <map>


void Game::update()
{
	if (status == STATUS_START)
		updateStartScreen();
	else if (status == STATUS_PLAYING)
		updatePlayingScreen();
	else if (status == STATUS_LOSE)
		updateLoseScreen();
	else
		updateWinScreen();
}

void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
		status = STATUS_PLAYING;

	if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
	{
		debug_mode = true;
		current_time = graphics::getGlobalTime();
	}
		

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
	if (graphics::getKeyState(graphics::SCANCODE_SPACE) && bomb_initialized == false) {
		graphics::playSound(std::string(ASSET_PATH) + "dropping.wav", 0.1, false);
		bomb = new Bomb(*this, this->get_pos_x(), this->get_pos_y(), true);
		bomb_initialized = true;
	} 

	if (bomb)
		bomb->update();

	if (bomb && bomb->get_pos_y_bomb() > CANVAS_HEIGHT)
	{
		if (!collided)
		{
			player->decreaseLives();
		}
		collided = false;
		bomb_initialized = false;
		delete bomb;
		bomb = nullptr;

	}
	

	for (std::size_t i = 0; i != targets.size(); ++i) {
		if (targets[i]) {
			if (checkCollision(targets[i])) {
				graphics::playSound(std::string(ASSET_PATH) + "bomb.mp3", 0.1, false);
				player->setScore(targets[i]->get_value());
				collided = true;
				delete targets[i];
				targets[i] = nullptr;
				c++;
			}
		}
	}

	if (player->getLives() == 0)
	{
		status = STATUS_LOSE;
	}

	if (targets.size() == c) {
		targets.clear();
		status = STATUS_WIN;
	}



}

void Game::updateLoseScreen()
{
}

void Game::updateWinScreen()
{
	graphics::playSound(std::string(ASSET_PATH) + "congrats.mp3", 0.5, true);
}


void Game::drawStartScreen()
{
	graphics::Brush br;
	graphics::drawText(CANVAS_WIDTH/3.5f, CANVAS_HEIGHT / 3.4f, 30, "THE  GRAND  CANYON  BOMBER", br);
	graphics::drawText(CANVAS_WIDTH / 2.8f, CANVAS_HEIGHT/2.3f, 20, "PRESS  ENTER  TO  START ", br);

	
	br.texture = std::string(ASSET_PATH) + "grandcanyon2.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	br.texture = std::string(ASSET_PATH) + "test.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(50, 50, 15, 15, br);

	if (debug_mode)
	{
		if(graphics::getGlobalTime() - current_time< 15)
			graphics::drawText(CANVAS_WIDTH / 2.5f, 100, 15, "Testing mode active.", br);
	}
		
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
	if (player) 
	{
		std::string l = std::to_string(player->getLives());
		graphics::drawText(30, 50, 15, "Lives : " + l, br2);
		std::string s = std::to_string(player->getScore());
		graphics::drawText(150, 50, 15, "Score : " + s, br2);
	}
}

void Game::drawLoseScreen()
{
	graphics::Brush br;
	std::string s = std::to_string(player->getScore());
	graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT / 3.4, 30, "GAME   OVER   ", br);
	graphics::drawText(CANVAS_WIDTH / 2.8, CANVAS_HEIGHT / 2.3, 20, "YOUR  SCORE  IS :  " + s, br);
	br.texture = std::string(ASSET_PATH) + "grandcanyon2.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
}

void Game::drawWinScreen()
{
	graphics::Brush br;
	std::string s = std::to_string(player->getScore());
	graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT / 3.4, 30, "CONGRATULATIONS !!! ", br);
	graphics::drawText(CANVAS_WIDTH/ 2.8, CANVAS_HEIGHT / 2.3, 20, "YOUR  SCORE  IS :  " + s, br);
	br.texture = std::string(ASSET_PATH) + "grandcanyon2.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
}


void Game::draw()
{
	if (status == STATUS_START)
		drawStartScreen();
	else if (status == STATUS_PLAYING)
		drawPlayingScreen();
	else if (status == STATUS_LOSE)
		drawLoseScreen();
	else if(status == STATUS_WIN)
		drawWinScreen();
	
}

void Game::init()
{

	graphics::setFont(std::string(ASSET_PATH) + "joystix.ttf");
	graphics::playMusic(std::string(ASSET_PATH) + "plane.mp3", 0.25, true, 0);

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

	/*d = { 100, 0, 0 };



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
	}*/

	/*graphics::Brush br2;
	
	graphics::drawText(30, 50, 15, "Lives : 3", br2);
	graphics::drawText(150, 50, 15, "Score : 0", br2);*/
	
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