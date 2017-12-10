#include <iostream>
using namespace std;

int main()
{
	int arr[20];
	for (int x = 0; x < 10; x++)
	{
		for (int y = x + 1; y < 10; y++)
		{
			for (int z = y + 1; z < 10; z++)
			{
				arr[x] = y * z;
				cout << arr[x] << endl;
			}
		}
	}
	


	system("pause");
	return 0;
}