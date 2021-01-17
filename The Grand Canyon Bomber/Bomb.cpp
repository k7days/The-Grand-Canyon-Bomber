#include "Bomb.h"
#include "config.h"
#include "graphics.h"
#include "game.h"

Bomb::Bomb(const Game& mygame, float posx, float posy, bool fall)
	:GameObject(mygame)
{
	posx_bomb = posx;
	posy_bomb = posy;
	falling = fall;

}


void Bomb::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_SPACE))
	{
		returning = (game.isReturning()) ? true : false;
	}
	
	if (falling)
	{
		if (!returning)
		{
			if (posx_bomb >= CANVAS_WIDTH)
				returning = true;
				
			posy_bomb += speed * graphics::getDeltaTime() / 10.0f;
			posx_bomb += 0.5f * graphics::getDeltaTime() / 10.0f;
			
		}
		else
		{
			if (posx_bomb <= 0)
				returning = false;

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
		graphics::drawRect(posx_bomb, posy_bomb, 20,20, br);
		
		/*char info[40];
		sprintf_s(info, "(%6.2f, %6.2f))", posx_bomb, posy_bomb);
		graphics::drawText(80, 120, 20, info, br);*/
}

void Bomb::init()
{
}

Disk Bomb::getCollisionHull() const
{
	Disk disk;
	disk.cx = posx_bomb;
	disk.cy = posy_bomb;
	if (game.getDebugMode())
		disk.radius = 40.0f;
	else
		disk.radius = 12.0f;

	return disk;
}

