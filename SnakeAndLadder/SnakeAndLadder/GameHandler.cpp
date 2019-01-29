#include "GameHandler.h"

GameHandler::GameHandler(SnakeAndLadder* sandlptr)
{
	m_pSnakeandLadder = sandlptr;
}

GameHandler::~GameHandler()
{
	Init();
}

void GameHandler::Init(void)
{
	m_lPlayerlist.clear();
	m_bIsGameRunning = false;
	m_iPlayerid = 1;
}

int GameHandler::AddPlayer(std::string name)
{
	if(m_bIsGameRunning)
	{
		return 0;
	}

	Player *nplayer = new Player(name, m_iPlayerid);
	m_lPlayerlist.push_back(*nplayer);
	
	return m_iPlayerid++;
}

bool GameHandler::StartGame(void)
{
	if(m_bIsGameRunning)
	{
		return false;
	}
	
	std::cout << "**First Roll value will decide the order of player turns**\n";

	m_bIsGameRunning = true;
	for(auto& pl : m_lPlayerlist)
	{
		int dice = m_RollDice(pl.GetPlayerName());
		pl.SetFirstRoll(dice);
	}
	
	m_lPlayerlist.sort();
	m_PlayGame();
	
	return true;
}

void GameHandler::m_PlayGame(void)
{
	std::cout << "***Now the real game starts***\n";
	while(m_bIsGameRunning)
	{
		for(auto& pl : m_lPlayerlist)
		{
			int dice = m_RollDice(pl.GetPlayerName());
			std::cout << "Input Value: " << dice << " and his current position is " << pl.GetCurrentPosition() << "\n";
			int newposition = m_MakeMove(pl.GetCurrentPosition(), dice);
			pl.SetCurrentPosition(newposition);
			std::cout << "Player " << pl.GetPlayerName() << " is at: " << pl.GetCurrentPosition() << "\n";
			if(newposition == 100)
			{
				std::cout << "\n******Game Over******\n";
				std::cout << "Won by: PlayerID: " << pl.GetPlayerID() << " - PlayerName: " << pl.GetPlayerName() << "\n\n";
				m_bIsGameRunning = false;
				break;
			}
		}
	}
}

bool GameHandler::IsGamePlaying(void)
{
	return m_bIsGameRunning;
}

int GameHandler::m_RollDice(std::string name)
{
	int rdice;
	
	//rdice = rand() % 6 + 1;

	std::cout << "Hi " << name << ", Please roll the dice and input value: ";
	std::cin >> rdice;

	while (rdice < 1 || rdice > 6)
	{
		std::cout << "Hi " << name << ", Please roll and input a valid dice value: ";
		std::cin >> rdice;
	}

	return rdice;
}

int GameHandler::m_MakeMove(int currentposition, int steps)
{	
	return m_pSnakeandLadder->PlaceMove(currentposition, steps);
}
