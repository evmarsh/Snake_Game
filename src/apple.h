#ifndef	APPLE_H
#define APPLE_H
#include "snake.h"
//#include "vector2.h"
#include <cstdlib>
#include <ctime>

class Apple {
	public:
		Apple(Snake &s);
		void draw(SDL_Renderer* gRenderer);	
		int x();
		int y();
		void setPos(int x, int y);
		void move();

	private:
		Vector2 pos;
		int size_;
		Snake &s_;
};

#include "apple.inl"

#endif
