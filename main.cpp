#include "gameControl.h"

int main()
{
	cout << "-----------Welcome to Zork-----------" << endl;
	cout << "A land where there are many ways to" << endl;
	cout << "die and only a few ways to not die." << endl;
	cout << "Will you be able to make it to the end?" << endl;
	cout << "--------------------------------" << endl;
	
	cout << "Type 'help' for a list of options" << endl;
	cout << "'help' is very usful for when\nyou don't know what to do" << endl;
	
	GameControl gameCont;

	string answer = "Y";
	while (answer[0] == 'Y')
	{
		Map map;
		cout << "Good Luck, " << map.getName() << endl;
		cout << "--------------------------------" << endl;
		answer = gameCont.loop(&map);
	}
	
	cout << "Thanks for playing!" << endl;

	return 0;
}