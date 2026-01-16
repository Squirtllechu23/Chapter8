#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <ctime>
#include <limits>
using namespace std;

const int MAX_STUDENTS = 10;
const int MAX_GRADES = 100;

string studentNames[MAX_STUDENTS];
double studentGrades[MAX_STUDENTS][MAX_GRADES];
int gradesperstudent[MAX_STUDENTS];
double Average[MAX_STUDENTS];
int studentCount = 0;


void FileIO();

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
			FileIO();
		}
		break;
		case 3:
		{
			return 0;
		}
		break;
		case 4:
		{
			return 0;
		}
		break;
		case 5:
		{
			return 0;
		}
		break;
		case 6:
		{
			cout << "\nnBye Bye(hehehehehehehehehehehehehehehehehehehehehe)";
		}
		break;
		default:
		{
			cout << "Invalid CHoice!!! Try again you failure!!!\n\n";
		}
		}
	}
}

void FileIO() {
	if (studentCount == 0) {
		cout << "\nNo data to save.\n";
		return;
	}

	string filename;
	cout << "\nEnter filename to save (e.g., grades.txt): ";
	getline(cin, filename);

	ofstream outFile("data/" + filename);

	if (!outFile) {
		cout << "Error: Could not open file for writing.\n";
		return;
	}

	outFile << studentCount << endl;

	for (int i = 0; i < studentCount; i++) {
		outFile << studentNames[i] << endl;
		outFile << gradesperstudent[i] << endl;

		for (int j = 0; j < gradesperstudent[i]; j++) {
			outFile << studentGrades[i][j];
			if (j < gradesperstudent[i] - 1) {
				outFile << " ";
			}
		}
		outFile << endl;
		outFile << Average[i] << endl;
	}

	outFile.close();
	cout << "\nData saved successfully to data/" << filename << "!\n";
}