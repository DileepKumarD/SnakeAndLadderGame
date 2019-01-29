#include "Player.h"

Player::Player(std::string name, int playerid)
{
	m_sPlayerName = name;
	m_iPlayerID = playerid;
}

bool Player::SetFirstRoll(int dice)
{
	m_iFirstRoll = dice;
	return true;
}
 
bool Player::SetCurrentPosition(int position)
{
	m_iCurrentPosition = position;
	return true;
}

int Player::GetFirstRoll(void)
{
	return m_iFirstRoll;
}

int Player::GetCurrentPosition(void)
{
	return m_iCurrentPosition;
}

std::string Player::GetPlayerName(void)
{
	return m_sPlayerName;
}

int Player::GetPlayerID(void)
{
	return m_iPlayerID;
}
