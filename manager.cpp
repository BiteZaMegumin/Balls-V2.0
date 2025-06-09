#include "manager.h"
#include "cmath"
using namespace System::Drawing;

Manager* manager;

Manager::Manager(int frameWidth, int frameHeight) {
	_frameWidth = frameWidth;
	_frameHeight = frameHeight;
	for (int i = 0; i < MAX_OBJECTS; i++) {
		_popObjects[i] = NULL;
	}
}
Manager::~Manager() {

}
void Manager::add(PopObject* popObject) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (!_popObjects[i]) {
		_popObjects[i] = popObject;
		break;
	}
}
void Manager::drawFrame(Graphics^ graphics) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (_popObjects[i]) {
		_popObjects[i]->draw(graphics);
	}
}
void Manager::move() {
	for (int i = 0; i < MAX_OBJECTS; i++) if (_popObjects[i]) {
		_popObjects[i]->move();
	}
	for (int i = 0; i < MAX_OBJECTS; i++) if (_popObjects[i]) {
		for (int j = i + 1; j < MAX_OBJECTS; j++) if (_popObjects[j]) {
			float x1 = _popObjects[i]->getX(), x2 = _popObjects[j]->getX(), y1 = _popObjects[i]->getY(), y2 = _popObjects[j]->getY();
			int size1 = _popObjects[i]->getSize(), size2 = _popObjects[j]->getSize();
			int dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			if (dist < size1 + size2) {
				_popObjects[i]->interact(_popObjects[j]);
				_popObjects[j]->interact(_popObjects[i]);
			}
		}
	}
}
bool Manager::remove(PopObject* popObject) {
	for (int i = 0; i < MAX_OBJECTS; i++) if (_popObjects[i] == popObject) {
		_popObjects[i] = NULL;
		delete popObject;
		return true;
	}
	return false;
}
