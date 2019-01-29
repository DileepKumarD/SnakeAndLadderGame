#include "SnakeAndLadder.h"

SnakeAndLadder::SnakeAndLadder()
{
	//NULL
}

SnakeAndLadder::~SnakeAndLadder()
{
	board.clear();
}

bool SnakeAndLadder::m_IsValidPosition(int position)
{
	if(position < 1 || position > 100)
	{
		return false;
	}
	
	return true;
}

bool SnakeAndLadder::AddLadder(int source, int destination)
{
	if(!m_IsValidPosition(source) || !m_IsValidPosition(destination) || source >= destination)
	{
		return false;
	}
	
	board[source] = destination;
	
	return true;
}

bool SnakeAndLadder::AddSnake(int source, int destination)
{
	if(!m_IsValidPosition(source) || !m_IsValidPosition(destination) || source <= destination)
	{
		return false;
	}
	
	board[source] = destination;
	
	return true;
}

POSITIONSTATUS SnakeAndLadder::GetStatus(int position)
{
	if(!m_IsValidPosition(position))
	{
		return INVALID;	
	}	
	
	int status = board[position];

	if (status == SAFE)
	{
		return SAFE;
	}
	else if (status > position)
	{
		return LADDER;
	}
	else if (status < position)
	{
		return SNAKE;
	}
	else
	{
		return INVALID;
	}
}

int SnakeAndLadder::PlaceMove(int currentposition, int steps)
{
	int newposition = currentposition + steps;
	
	if(!m_IsValidPosition(newposition))
	{
		return currentposition;	
	}
	
	int status = board[newposition];
	if(status)
	{
		return status;
	}
	else
	{
		return newposition;
	}
}
