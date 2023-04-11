#include "GameManager.h"

void GameManager::Update() {
	switch (currentScene)
	{
		//Cridem funcions
	case GameManager::MENU:
		Menu();
		break;
	case GameManager::GAMEPLAY:
		Gameplay();
		break;
	case GameManager::HIGHSCORE:
		Highscore();
		break;
	}

}

	//Incloent Windows.h i un valor en ms dins una variable
	//es pot controlar els fps del joc amb Sleep()

void GameManager::Menu() {
	//Començo l'escena
	int sleepTime = 500; //in ms. El menu anirà a 2fps, no necessita més
	bool keyPressed = false;

	bool pressed1;
	bool pressed2;
	bool pressed3;

	//Actualitzo l'escena
	while (!keyPressed) {
		std::cout << "Main Menu\n\n" << std::endl;
		std::cout << "Press 1 to play" << std::endl;
		std::cout << "Press 2 to see Highscores" << std::endl;
		std::cout << "Press 3 to exit" << std::endl;

		//GetAsyncKeyState(VK_SPACE); 
		//trackeja si has apretat una tecla (1) si l'estas apretant o no (0)
		pressed1 = GetAsyncKeyState('1') != 0;
		pressed2 = GetAsyncKeyState('2') != 0;
		pressed3 = GetAsyncKeyState('3') != 0;

		keyPressed = pressed1 || pressed2 || pressed3;

		Sleep(sleepTime);
		system("cls");
	}
	
	//Descarrego l'escena
	if (pressed1)
		currentScene = Scene::GAMEPLAY;

	else if (pressed2)
		currentScene = Scene::HIGHSCORE;

	else	
		isPlaying = false;
}

void GameManager::Gameplay() {
	//START
	int sleepTime = 100; //in ms
	bool gameplayRunning = true;

	Pad* playerPad = nullptr;
	Ball* ball = nullptr;
	std::vector<Wall> walls;
	std::vector<Brick> bricks;

	InitGameplay(25, 15, &playerPad, &ball, walls, bricks);
	
	//---UPDATE
	while (gameplayRunning) {
		//---------- UPDATE
		ball->Update(walls, bricks, playerPad);
		//---------- RENDER
		playerPad->Render();

		for (std::vector<Wall>::iterator it = walls.begin(); it != walls.end(); it++) {
			it->Render();
		}

		for (std::vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); it++) {
			it->Render();
		}

		//Sleep & clear
		Sleep(sleepTime);
		system("cls");
	}

	ball->Render();

	//END
}

void GameManager::InitGameplay(int width, int height, Pad** p, Ball** b, std::vector<Wall>& w, std::vector<Brick>& brick) {
	//PAD
	*p = new Pad(Vector2(width / 2, height / 2 + height / 4), 3);

	//WALLS
	//First corner (top left)
	w.push_back(Wall(WallType::CORNER, Vector2(0, 0)));
		for (int i = i; i < width - 1; i++)
			w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, 0)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1, 0)));

	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < 2; j++)	{
			w.push_back(Wall(WallType::VERTICAL, Vector2(j * (width -1), i + 1)));
		}
	}

	w.push_back(Wall(WallType::CORNER, Vector2(0, height - 1)));
		for (int i = i; i < width - 1; i++)
			w.push_back(Wall(WallType::HORIZONTAL, Vector2(i, height - 1)));
	w.push_back(Wall(WallType::CORNER, Vector2(width - 1, height - 1)));

	//BRICKS (3 rows on the top)
	for (int i = 1; i <= 3; i++) //FILES
	{
		for (int j = 0; j < width - 1; j++)
		{
			brick.push_back(Brick(Vector2(j, i), 1));
		}
	}
	
	//BALL
	*b = new Ball(Vector2(width / 2, height / 2), Vector2(0, 1), 1);
}


void GameManager::Highscore() {

}