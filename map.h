#include "player.h"

class Map
{
public:
	Map();
	~Map();

	void move(string theChoice);
	void look();
	void ground();
	void pick();
	void drop();
	void playerInv();
	void use();
	string getName();

private:
	Player* m_pPlayer;
	Room* m_pPlayerLoc;
};
