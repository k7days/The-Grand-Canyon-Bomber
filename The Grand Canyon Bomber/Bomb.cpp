#include "Bomb.h"
#include "config.h"
#include "graphics.h"
#include "game.h"

Bomb::Bomb(const Game& mygame)
	:GameObject(mygame)
{
}


void Bomb::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		falling = true;
		posx_bomb = game.get_pos_x();
		posy_bomb = game.get_pos_y();

	}

	if (falling)
	{
		if (!game.isReturning())
		{
			posy_bomb += speed * graphics::getDeltaTime() / 10.0f;
			posx_bomb += 0.5f * graphics::getDeltaTime() / 10.0f;
		}
		else
		{
			posy_bomb += speed * graphics::getDeltaTime() / 10.0f;
			posx_bomb -= 0.5f * graphics::getDeltaTime() / 10.0f;
		}
	}
	}


void Bomb::draw()
{
		graphics::Brush br;
		br.texture = std::string(ASSET_PATH) + "bomb.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(posx_bomb, posy_bomb, 20, 20, br);
		
		//char info[40];
		//sprintf_s(info, "(%6.2f, %6.2f))", pos_x, pos_y);
		//graphics::drawText(80, 80, 20, info, br);
		//
		////char info[40];
		//sprintf_s(info, "(%6.2f, %6.2f)", posx_bomb, posy_bomb);
		//graphics::drawText(80, 100, 20, info, br);
	
}

void Bomb::init()
{
}

Disk Bomb::getCollisionHull() const
{
	Disk disk;
	disk.cx = posx_bomb;
	disk.cy = posy_bomb;
	disk.radius = 12.0f;

	return disk;
}

//void Bomb::setPosition(float posx, float posy) {
//	pos_xbomb = posx;
//	pos_ybomb = posy;
//}




