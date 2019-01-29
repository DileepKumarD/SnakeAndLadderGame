#ifndef SNAKEANDLADDER_H
#define SNAKEANDLADDER_H

#include <map>

enum POSITIONSTATUS
{
	SAFE,
	SNAKE,
	LADDER,
	INVALID
};

class SnakeAndLadder
{
	public:
		SnakeAndLadder();
		~SnakeAndLadder();
		bool AddLadder(int source, int destination);
		bool AddSnake(int source, int destination);
		POSITIONSTATUS GetStatus(int position);
		int PlaceMove(int currentposition, int steps);
	private:
		bool m_IsValidPosition(int position);		
	private:
		std::map<int, int> board;
};

#endif
