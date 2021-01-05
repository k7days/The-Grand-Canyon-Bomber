#include "Bomb.h"
#include "config.h"
#include "graphics.h"
#include "game.h"
#include "Player.h"

void Bomb::update()
{
	
	/*if (falling) {
		posx_bomb = pos_x;
		posy_bomb = pos_y;
	}*/
	//else
	//{
		
	
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		falling = true;
		posx_bomb = pos_x;
		posy_bomb = pos_y;
	}

	if (falling)
	{
		if (pos_x <= CANVAS_WIDTH && go_back == false)
		{
			posy_bomb += speed * graphics::getDeltaTime() / 10.0f;
			posx_bomb += 0.5f * graphics::getDeltaTime() / 10.0f;
		}
		else
		{
			go_back = true;
			posy_bomb += speed * graphics::getDeltaTime() / 10.0f;
			posx_bomb -= 0.5f * graphics::getDeltaTime() / 10.0f;
			if (posx_bomb < 0) { go_back = false; }
		}
	}
	//}
	
}


void Bomb::draw()
{
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "bomb.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(posx_bomb, posy_bomb, 20, 20, br);
		
		char info[40];
		sprintf_s(info, "(%6.2f, %6.2f))", pos_x, pos_y);
		graphics::drawText(80, 80, 20, info, br);
		
		//char info[40];
		sprintf_s(info, "(%6.2f, %6.2f)", posx_bomb, posy_bomb);
		graphics::drawText(80, 100, 20, info, br);
	
}

void Bomb::init()
{
	//posx_bomb = pos_x;
	//posy_bomb = pos_y;
}

//void Bomb::setPosition(float posx, float posy) {
//	pos_xbomb = posx;
//	pos_ybomb = posy;
//}




