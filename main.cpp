#include "gameControl.h"

int main()
{


	cout << "-----------Welcome to Zork-----------" << endl;
	cout << "A fantastic adventure set in a creepy" << endl;
	cout << "world filled with treasure and terrors" << endl;
	cout << "Will you be able to make it to the end?" << endl;
	cout << "--------------------------------" << endl;
	Map map;
	cout << "Good Luck, " << map.getName() << endl;
	cout << "--------------------------------" << endl;
	cout << "Type 'help' for a list of options" << endl;
	
	GameControl gameCont;
	gameCont.loop(&map);

	return 0;
}