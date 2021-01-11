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
		if (pos_xbomb <= CANVAS_WIDTH && go_back == false) {
			pos_ybomb += speed * graphics::getDeltaTime() / 10.0f;
			pos_xbomb += 0.5f * graphics::getDeltaTime() / 10.0f;
		}
		else {
			go_back = true;
			pos_ybomb += speed * graphics::getDeltaTime() / 10.0f;
			pos_xbomb -= 0.5f * graphics::getDeltaTime() / 10.0f;
			if (pos_xbomb < 0) { go_back = false; }
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

//void Bomb::setPosition(float posx, float posy) {
//	pos_xbomb = posx;
//	pos_ybomb = posy;
//}




