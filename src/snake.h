#ifndef SNAKE_H
#define SNAKE_H
#include <SDL2/SDL.h>
#include <vector>
//#include "vector2.h"

struct Vector2 {
	int x;
	int y;
};

class Snake {
	public:
		Snake();
		void init();
		void draw(SDL_Renderer* gRenderer);
		int x();
		int y();
		int x(int index);
		int y(int index);
		int length();
		void move(int direction);
		void grow();
		bool colliding_wall();
		bool colliding_self();
		void reset();
	
	private:
		int size_;
		int dx_;
		int dy_;
		std::vector<Vector2> body_;
};

#include "snake.inl"

#endif
