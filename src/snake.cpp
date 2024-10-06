#include "snake.h"
#include <iostream>

Snake::Snake()
: size_ (50),
  dx_ (0),
  dy_ (0)
{ 
	std::vector<Vector2> body_;
	init();
}

void Snake::init() {
	Vector2 p;
	p.x = 300;
	p.y = 300;
	this->body_.push_back(p);
}

void Snake::draw(SDL_Renderer* gRenderer) {
	SDL_Rect fillRect;
	for (int i = 0; i < this->length(); i++) {
		fillRect = {this->body_[i].x, this->body_[i].y, this->size_, this->size_ };
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0x00);
		SDL_RenderFillRect(gRenderer, &fillRect);
	}
}

void Snake::move(int direction) {
	//update position so constantly moving based on direction
	switch (direction) {
		case 0:
			if (this->body_[0].y > 0) {
				this->dy_ = -(this->size_);
				this->dx_ = 0;
			}
			break;

		case 1:
			if (this->body_[0].y < 700) {
				this->dy_ = this->size_;
				this->dx_ = 0;
			}
			break;

		case 2:
			if (this->body_[0].x > 0) {
				this->dx_ = -(this->size_);
				this->dy_ = 0;
			}
			break;

		case 3:
			if (this->body_[0].x < 700) {
				this->dx_ = (this->size_);
				this->dy_ = 0;
			}
			break;
	}

	if (this->length() > 1) {
		for (int i = this->length()-1; i > 0; i--) {
			this->body_[i].x = this->body_[i-1].x;
			this->body_[i].y = this->body_[i-1].y;
		}
	}
	
	this->body_[0].x += this->dx_;
	this->body_[0].y += this->dy_;
}

void Snake::grow() {
	Vector2 p;
	p.x = this->body_[length()-1].x += this->dx_;
	p.y = this->body_[length()-1].y += this->dy_;	
	this->body_.push_back(p);
}

bool Snake::colliding_self() {
	for (int i = 1; i < this->length(); i++) {
		if (this->body_[0].x == this->body_[i].x && this->body_[0].y == this->body_[i].y) {
			return true;
		}
	}

	return false;
}

void Snake::reset() {
	this->body_.clear();
	this->init();
}
