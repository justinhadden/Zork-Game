#include "gameControl.h"

int main()
{
	cout << "-----------Welcome to Zork-----------" << endl;
	cout << "A land where there are many ways to" << endl;
	cout << "die and only a few ways to not die." << endl;
	cout << "Will you be able to make it to the end?" << endl;
	cout << "--------------------------------" << endl;
	Map map;
	cout << "Good Luck, " << map.getName() << endl;
	cout << "--------------------------------" << endl;
	cout << "Type 'help' for a list of options" << endl;
	cout << "'help' is very usful for when\nyou don't know what to do" << endl;
	
	GameControl gameCont;
	gameCont.loop(&map);

	return 0;
}