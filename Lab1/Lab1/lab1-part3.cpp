#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	float balance = 0.0;
	queue<float> transactions;

	transactions.push(100.42);
	transactions.push(-5.58);
	transactions.push(50.78);
	transactions.push(-20.5);

	while (!transactions.empty())
	{
		//transactions.front();
		cout << transactions.front() << " " << "pushed to account" << endl;
		balance += transactions.front();
		transactions.pop();
	}

	cout<< "\n" << "Final balance: $" << balance << endl;

	system("pause");
	return 0;
}

//OutPut
/*
100.42 pushed to account
-5.58 pushed to account
50.78 pushed to account
-20.5 pushed to account

Final balance: $125.12
Press any key to continue . . .


*/