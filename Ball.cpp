#include "Ball.h"
using namespace System::Drawing;

Ball* ball;

void Ball::draw(Graphics^ graphics) {
	SolidBrush pen(Color::FromArgb(_color));
	graphics->FillEllipse(%pen, (int)_x-_size/2, (int)_y-_size/2, _size, _size);
}
void Ball::setPos(int x, int y) {
	if ((_size/2 < x) && (x < _frameX - _size/2) && (_size/2 < y) && (y < _frameY - _size/2)) {
		_x = x;
		_y = y;
	}
}
Ball::Ball(int frameWidth, int frameHeight) {
	_frameX = frameWidth;
	_frameY = frameHeight;
	_size = 40;
	_color = Color::Black.ToArgb();
	_x = frameWidth / 2;
	_y = frameHeight / 2;
}
int Ball::getSize(){
	return _size;
}
void Ball::setColor(int color) {
	_color = color;
}
void Ball::setSize(int size) {
	_size = size;
}
void Ball::getPos(int& x, int& y) {
	x = _x;
	y = _y;
}