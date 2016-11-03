#include "player.h"

class Map
{
public:
	Map();
	~Map();

	void move(string theChoice);
	void look();
	void inspect();
	void pick();
	void drop();
	void playerInv();
	void use();
	Room* getPlayerLoc();
	string getName();

private:
	Player* m_pPlayer;
	Room* m_pPlayerLoc;
};
