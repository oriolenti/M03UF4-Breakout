#include "Pad.h"

Pad

void Pad::Render() {
	//moure el cursor a la posici�
	ConsoleXY(position.x, position.y);

	//Canviar el color
	ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);

	//Dibuixar la pala
	std::cout << "-";
}