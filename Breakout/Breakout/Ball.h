#pragma once

#include <vector>

#include "Vector2.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"

class Ball {

private:
	Vector2 position;
	Vector2 direction;
	int damage;

public:
	Ball(Vector2 pos, Vector2 dir, int dmg)
		: position(pos), direction(dir), damage(dmg) {}
	void Bounce(Vector2 normal);
	int GetDamage() { return damage; };
	Vector2 GetDirection() { return direction; };
	Vector2 GetPosition() { return position; };
	void Update(std::vector <Wall> walls, std::vector <Brick> bricks, Pad* pads);
	void Render() {
		ConsoleXY(position.x, position.y);
		std::cout << "@";
	}
};