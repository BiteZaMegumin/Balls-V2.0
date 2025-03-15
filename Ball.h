#pragma once
using namespace System::Drawing;

class Ball
{
private:
	int _diam, _rad, _frameX, _frameY;
	int _color;
	float _x, _y,_spdy,_spdx;
public:
	void draw(Graphics^ graphics);
	void setPos(float x, float y);
	Ball(int frameWidth, int frameHeight);
	int getSize() {
		return _diam;
	}
	void setColor(int color); 
	void setSize(int size);
	void getPos(int& x, int& y);
	void move();
	void setSpeed(float x, float y);
	float getSpdX() {
		return _spdx;
	}
	float getSpdY() {
		return _spdy;
	}
	void followTo(float x, float y);
};
 extern Ball* ball;

