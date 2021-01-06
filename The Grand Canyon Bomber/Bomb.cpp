#include "Bomb.h"
#include "config.h"
#include "graphics.h"
#include "game.h"



void Bomb::update()
{

		if (pos_xbomb <= CANVAS_WIDTH  && go_back == false) {
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
		graphics::drawRect(pos_xbomb, pos_ybomb, 20, 20, br);
	
}

void Bomb::init()
{

}

void Bomb::setPosition(float posx, float posy) {
	pos_xbomb = posx;
	pos_ybomb = posy;
}


