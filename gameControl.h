#include "map.h"

class GameControl
{
public:
	void info();
	string loop(Map* theMap);
	string playerDead();

private:
	bool gameOver;
	Map* m_TheMap;
};
