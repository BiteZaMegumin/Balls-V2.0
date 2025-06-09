#pragma once
#include "cmath"
using namespace System::Drawing;
#define MAX_OBJECTS 40
class PopObject {
public:
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual void setPos(float x, float y) = 0;
	virtual int getSize() = 0;
	virtual void draw(Graphics^ graphics) = 0;
	virtual float getSpdX() = 0;
	virtual float getSpdY() = 0;
	virtual void setSpeed(float x, float y) = 0;
	virtual void move() = 0;
	virtual void interact(PopObject* popObject) = 0;
};

class Manager {
private:
	PopObject* _popObjects[MAX_OBJECTS];
	int _frameWidth, _frameHeight;
public:
	Manager(int frameWidth, int frameHeight);
	~Manager();
	void add(PopObject* popObject);
	void drawFrame(Graphics^ graphics);
	void move();
	bool remove(PopObject* popObject);
};
extern Manager* manager;

