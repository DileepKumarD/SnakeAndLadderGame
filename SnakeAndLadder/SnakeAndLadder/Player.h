#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
	public:
		Player(std::string name, int playerid);
		std::string GetPlayerName(void);
		int GetPlayerID(void);
		int GetCurrentPosition();
		bool SetCurrentPosition(int position);
		int GetFirstRoll();
		bool SetFirstRoll(int dice);
		bool operator<(Player other)
	    {
	        return GetFirstRoll() > other.GetFirstRoll();
	    }
	private:
		std::string m_sPlayerName;
		int m_iPlayerID;
		int m_iCurrentPosition{0};
		int m_iFirstRoll{0};
};

#endif
