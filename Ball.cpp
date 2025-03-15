#include "Ball.h"
#include "cmath"
using namespace System::Drawing;

Ball* ball;

void Ball::draw(Graphics^ graphics) {
	SolidBrush pen(Color::FromArgb(_color));
	graphics->FillEllipse(%pen, (int)_x-_rad, (int)_y-_rad, _diam, _diam);
}
void Ball::setPos(float x, float y) {
	if (_rad > x) x = _rad;
	else if (x > _frameX - _rad) x = _frameX - _rad;
	if (_rad > y) y = _rad;
	else if (y > _frameY - _rad) y = _frameY - _rad;
	_x = x;
	_y = y;
}
Ball::Ball(int frameWidth, int frameHeight) {
	_frameX = frameWidth;
	_frameY = frameHeight;
	_rad = 20;
	_diam = 40;
	_color = Color::Black.ToArgb();
	_x = frameWidth / 2;
	_y = frameHeight / 2;
	_spdy = 0;
	_spdx = 0;
}
void Ball::setColor(int color) {
	_color = color;
}
void Ball::setSize(int size) {
	_diam = size;
	_rad = size / 2;
	setPos(_x, _y);
}
void Ball::getPos(int& x, int& y) {
	x = _x;
	y = _y;
}
void Ball::move() {
	if (_rad > _x || _x > _frameX - _rad) _spdx = -_spdx;
	if (_rad > _y || _y > _frameY - _rad) _spdy = -_spdy;
	_x += _spdx;
	_y += _spdy;
}
void Ball::setSpeed(float x, float y) {
	_spdx = x;
	_spdy = y;
	if (x > 20) _spdx = 20;
	if (y > 20) _spdy = 20;
}
void Ball::followTo(float x, float y) {
	if (_x - x != 0 || _y - y != 0) {
		int speed = sqrt(_spdx * _spdx + _spdy * _spdy);
		if (_spdx == 0 && _spdy == 0) speed = 7;
		int anglex, angley;
		anglex = _x - x;
		angley = _y - y;
		float angle = atan2(angley,anglex);
		_spdx = -(speed * cos(angle));
		_spdy = -(speed * sin(angle));
	}
}