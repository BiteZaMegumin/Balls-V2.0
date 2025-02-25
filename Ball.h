#pragma once
using namespace System::Drawing;

class Ball
{
private:
	int _size, _frameX, _frameY;
	int _color;
	float _x, _y;
public:
	void draw(Graphics^ graphics);
	void setPos(int x, int y);
	Ball(int frameWidth, int frameHeight);
	int getSize();
	void setColor(int color); 
	void setSize(int size);
	void getPos(int& x, int& y);
};
 extern Ball* ball;

