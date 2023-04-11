#pragma once
#include <iostream>
#include <stdlib.h>

#include "ConsoleControl.h"
#include "Vector2.h"

#define NUM_BRICKS 72

class Brick {
private:
	Vector2 position;
	int health;
	ConsoleColor color;

public:
	Brick(Vector2 p, int h);
	Vector2	GetPosition() { return position; };
	void SetPosition(Vector2 p) { position = p; };
	int GetHealth() { return health; };
	void TakeDamage(int dmg) { health -= dmg; };
	void Render() {
		ConsoleXY(position.x, position.y);
		std::cout << "#";
	}
};