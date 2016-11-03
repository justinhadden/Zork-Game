#include "map.h"

class GameControl
{
public:
	void info();
	void loop(Map* theMap);

private:
	Player* m_pPlayer;
};
