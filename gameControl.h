#include "map.h"

class GameControl
{
public:
	void info();
	void loop(Map* theMap);
	void playerDead();

private:
	bool gameOver;
	Map* m_TheMap;
};
