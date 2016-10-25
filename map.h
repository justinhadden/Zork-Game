#include "player.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();

	void move(string theChoice, Map* theMap);
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