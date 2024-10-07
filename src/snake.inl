inline
int Snake::length() {
	return this->body_.size();
}

inline
int Snake::x() {
	return this->body_[0].x;
}

inline
int Snake::y() {
	return this->body_[0].y;
}

inline
int Snake::x(int index) {
	return this->body_[index].x;
}

inline
int Snake::y(int index) {
	return this->body_[index].y;
}
