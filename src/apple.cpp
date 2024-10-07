#include "apple.h"

Apple::Apple(Snake &s)
: size_ (50),
  s_ (s)
{
	move();
}

void Apple::draw(SDL_Renderer* gRenderer) {
	SDL_Rect fillRect = {this->pos.x, this->pos.y, this->size_, this->size_ };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);
}

void Apple::move() {
	int randX = 0;
	int randY = 0;
	std::srand(std::time(nullptr));
	
	bool notDone = true;

	while(notDone) {
		//generate a rand num between 1 and 14 then multiply by 50 so apple is in line with snake
		randX = (1 + std::rand() / ((RAND_MAX + 1u) / 14)) * 50;
		randY = (1 + std::rand() / ((RAND_MAX + 1u) / 14)) * 50;

		//make sure apple isn't on snake
		for (int i = 0; i < s_.length(); i++) {
			if (randX != s_.x(i) && randY != s_.y(i)) {
				notDone = false;
			}
		}
	}

	this->pos.x = randX;
	this->pos.y = randY;
}
