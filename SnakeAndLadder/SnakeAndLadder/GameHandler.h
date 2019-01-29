#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <iostream>
#include <string>
#include <list>
#include "SnakeAndLadder.h"
#include "Player.h"

class GameHandler
{
	public:
		GameHandler(SnakeAndLadder* sandlptr);
		~GameHandler();
		
		void Init(void);
		bool StartGame(void);
		int AddPlayer(std::string name);
		bool RemovePlayer(std::string name);
		bool IsGamePlaying(void);

	private:
		int m_RollDice(std::string name);
		int m_MakeMove(int currentposition, int steps);
		void m_PlayGame(void);

	private:
		SnakeAndLadder* m_pSnakeandLadder;
		std::list<Player> m_lPlayerlist;
		bool m_bIsGameRunning{false};
		int m_iPlayerid{1};
};

#endif
