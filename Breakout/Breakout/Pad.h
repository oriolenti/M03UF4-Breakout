#pragma once

#include "ConsoleControl.h"
#include "Vector2.h"
#include "Wall.h"

class Pad {
private:
	Vector2 position;
	int width

public:
	Pad(Vector2 p, int w)
		: position(p), width(w) {}
	int GetWidth();
	void SetWidth(int w);
};