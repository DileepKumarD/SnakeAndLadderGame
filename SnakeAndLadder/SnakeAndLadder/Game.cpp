#include <iostream>
#include "SnakeAndLadder.h"
#include "GameHandler.h"

using namespace std;

SnakeAndLadder* pSandL;
GameHandler* pghandler;

void CreateBoard(SnakeAndLadder* pSandL)
{		
	pSandL->AddLadder(5, 25);
	pSandL->AddLadder(10, 29);
	pSandL->AddLadder(22, 41);
	pSandL->AddLadder(28, 55);
	pSandL->AddLadder(44, 95);
	pSandL->AddLadder(70, 89);
	pSandL->AddLadder(79, 81);
	
	pSandL->AddSnake(31, 14);
	pSandL->AddSnake(37, 17);
	pSandL->AddSnake(73, 53);
	pSandL->AddSnake(78, 39);
	pSandL->AddSnake(92, 35);
	pSandL->AddSnake(99, 7);

	//To add snakes or ladders use the above api
}

void OrganiseGame(GameHandler *pghandler)
{
	int np;
	std::string name;
	
	cout << "****Organising new game****\n";

	pghandler->Init();
	cout << "No of Players: ";
	cin >> np;

	for(int i = 1; i <= np; ++i)
	{
		cout << "Input Name of player " << i << ": ";
		cin >> name;
		pghandler->AddPlayer(name);
	}

	pghandler->StartGame();
}

void CloseGame(SnakeAndLadder* pSandL, GameHandler* pghandler)
{
	delete pSandL;
	delete pghandler;
}

int main()
{
	SnakeAndLadder* pSandL = new SnakeAndLadder();
	CreateBoard(pSandL);

	GameHandler* pghandler = new GameHandler(pSandL);	
	OrganiseGame(pghandler);
	
	//To Start new game call OrganiseGame(pghandler);

	CloseGame(pSandL, pghandler);
	
	return 0;
}
