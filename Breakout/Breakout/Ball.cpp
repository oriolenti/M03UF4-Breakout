#include "Ball.h"

void Ball::Update(std::vector <Wall> walls, std::vector <Brick> bricks, Pad* pads) {
	
	Vector2 targetPos = position + direction;
	
	//Check the walls

	for (auto it = walls.begin(); it != walls.end(); it++)
	{
		if (it->GetPosition() == position)
		{
			switch (it->GetType())
			{
			case VERTICAL:
				direction.x *= -1;
				break;
			case HORIZONTAL:
				direction.y *= -1;
				break;
			case CORNER:
				direction.x *= -1;
				direction.y *= -1;
				break;
			}
		}
	}
	position = position + direction;
}
