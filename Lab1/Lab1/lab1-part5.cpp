#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, string> colors;
	colors["red"] = "FFOOOO";
	colors["green"] = "OOFFOO";
	colors["blue"] = "OOOOFF";
	colors["magenta"] = "FFOOFF";
	colors["yellow"] = "FFFFOO";
	colors["cyan"] = "OOFFFF";


	while (true)
	{
		string color;
		cout << endl << "Enter a color, or QUIT to stop: ";
		cin >> color;
		

		if (color == "QUIT")
		{
			break;
		}
		cout << "Hex: " << colors[color] << endl;
	}

	system("pause");
	return 0;
}

//OutPut
/*
Enter a color, or QUIT to stop: red
Hex: FFOOOO

Enter a color, or QUIT to stop: yellow
Hex: FFFFOO

Enter a color, or QUIT to stop: blue
Hex: OOOOFF

Enter a color, or QUIT to stop: QUIT
Press any key to continue . . .

*/