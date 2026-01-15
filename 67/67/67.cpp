#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	//Define variable for menu choice
	int choice = 0;
	while (choice != 6)
	{
		do
		{
			//Display the menu for the user
			cout << "Student Grades System \n"
				<< "Please make a sleection from the options below:\n";
			cout << "1. Data Input and Storage\n";
			cout << "2. File I/O\n";
			cout << "3. Data Analysis\n";
			cout << "4. Search Functionality\n";
			cout << "5. Sorting Functionality\n";
			cout << "6. Quit\n";
			cout << ":>";
			cin >> choice;
		} while (choice < 1 || choice > 6);

		//Process the choice
		switch (choice)
		{

		case 1:
		{
			int student;
			cout << "How many ";
		}
		break;
		case 2:
		{

		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{
			cout << "\nnBye Bye";
		}
		break;
		default:
		{
			cout << "Invalid CHoice\n\n";
		}
		}
	}
}