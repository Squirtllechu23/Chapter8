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
void sortName(int, int);
int partitionName(int, int);
void displayData();


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
			cout << "6. Display data\n";
			cout << "7. Quit\n";
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
			sortName(0, studentCount -1);
		}
		break;
		case 6:
		{
			return 0;
		}
		break;
		case 7:
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

	for (int idk = 0; idk < studentCount; idk++) {
		outFile << studentNames[idk] << endl;
		outFile << gradesperstudent[idk] << endl;

		for (int idk1 = 0; idk1 < gradesperstudent[idk]; idk1++) {
			outFile << studentGrades[idk][idk1];
			if (idk1 < gradesperstudent[idk] - 1) {
				outFile << " ";
			}
		}
		outFile << endl;
		outFile << Average[idk] << endl;
	}

	outFile.close();
	cout << "\nData saved successfully to data/" << filename << "!\n";
}

void sortName(int left, int right) {
	if (left < right) {
		int pivotindex = partitionName(left, right);
		sortName(left, pivotindex - 1);
		sortName(pivotindex + 1, right);
	}
}

int partitionName(int left, int right) {
	string pivot = studentNames[right];
	int idk = left - 1;

	for (int idk1 = left; idk1 < right; idk1++) {
		if (studentNames[idk1] < pivot) {
			idk++;

			swap(studentNames[idk], studentNames[idk1]);
			swap(gradesperstudent[idk], gradesperstudent[idk1]);
			swap(Average[idk], Average[idk1]);

			for (int idk2 = 0; idk2 < MAX_GRADES; idk2++) {
				swap(studentGrades[idk][idk2], studentGrades[idk1][idk2]);
			}
		}
	}

	return idk + 1;
}

void displayData() {
	cout << "This is the data for the students sorted by name." << endl;
}