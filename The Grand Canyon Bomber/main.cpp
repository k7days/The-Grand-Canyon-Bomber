#include "graphics.h"
#include "scancodes.h"
#include "config.h"
#include "game.h"






void update(float ms) {
	Game* game = reinterpret_cast<Game *>(graphics::getUserData());
	game->update();

}

void draw() {
	Game* game = reinterpret_cast<Game*>(graphics::getUserData());
	game->draw();
}


int main() {

	
	Game mygame;

	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Grand Canyon Bomber");
	graphics::setFullScreen(true);

	graphics::setUserData(&mygame);
		
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	mygame.init();
	graphics::startMessageLoop();
	graphics::destroyWindow();
	

	return 0;
}