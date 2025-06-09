#pragma once
#include "manager.h"
using namespace System::Drawing;

class Ball: public PopObject{
private:
	int _diam, _rad, _frameX, _frameY, _color;
	float _x, _y,_spdy,_spdx;
public:
	float getX() {
		return _x;
	}
	float getY() {
		return _y;
	}
	void setPos(float x, float y);
	int getSize() {
		return _rad;
	}
	void draw(Graphics^ graphics)override;
	float getSpdX() {
		return _spdx;
	}
	float getSpdY() {
		return _spdy;
	}
	void setSpeed(float x, float y);
	void move();
	void interact(PopObject* popObject);
	Ball(int frameWidth, int frameHeight, int x, int y);
	void setColor(int color); 
	void setSize(int size);
	void getPos(int& x, int& y);
	void followTo(float x, float y);
};

