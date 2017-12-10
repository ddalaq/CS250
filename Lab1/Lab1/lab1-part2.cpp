#include <iostream>   
#include <list>    
#include <string>   
using namespace std;

void AddCourses(list<string>& courses)
{
	courses.push_back("cs 250");
	courses.push_back("cs 200");
	courses.push_back("cs 210");
	courses.push_back("cs 235");
	courses.push_back("cs 134");
	courses.push_back("cs 211");
}

void SortList(list <string>& courses)
{
	courses.sort();
}

void ReverseList(list <string>& courses)
{
	courses.reverse();
}

void DisplayCourses(list <string>& courses)
{
	int counter = 0;
	// this is how we have to iterate thru a list.
	for (list<string>::iterator it = courses.begin(); it != courses.end(); it++)
	{
		if (counter != 0) { cout << ", "; }
		cout << counter++ << ". " << (*it);
	}
	cout << "\n" << endl;
}

int main()
{
	list<string> courses;

	AddCourses(courses);
	cout << "Normal order " << endl;
	DisplayCourses(courses);
	

	SortList(courses);
	cout << "Sorted Order" << endl;
	DisplayCourses(courses);

	ReverseList(courses);
	cout << "Reverse Order" << endl;
	DisplayCourses(courses);



	system("pause");
	return 0;
}

//OutPut

/*
Normal order
0. cs 250, 1. cs 200, 2. cs 210, 3. cs 235, 4. cs 134, 5. cs 211

Sorted Order
0. cs 134, 1. cs 200, 2. cs 210, 3. cs 211, 4. cs 235, 5. cs 250

Reverse Order
0. cs 250, 1. cs 235, 2. cs 211, 3. cs 210, 4. cs 200, 5. cs 134

Press any key to continue . . .

*/