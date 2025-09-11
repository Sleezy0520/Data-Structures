#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readStudentData(ifstream &inFile, vector<studentType> &students);
void calcGrade(vector<studentType> &student);
void printData(vector<studentType> &student);
int highestTestScore(vector<studentType> &student);
void printHighestTestScore(vector<studentType> &student);
void cinfail();

int main()
{
    const int maxsize = 20;
    vector<studentType> student;
    ifstream inFile("students.txt");
    ofstream outFile("results.txt");

    if (!inFile)
    {
        cout << "Error: Could not open students.txt" << endl;
        return 1;
    }
    if (!outFile)
    {
        cout << "Error: Could not create results.txt" << endl;
        return 1;
    }

    readStudentData(inFile, student);
    calcGrade(student);
    printData(student);
    printHighestTestScore(student);

    return 0;
}

void readStudentData(ifstream &inFile, vector<studentType> &students)
{
    studentType temp;
    while (inFile >> temp.studentFName >> temp.studentLName >> temp.testScore)
    {
        students.push_back(temp);
    }
}

void calcGrade(vector<studentType> &student)
{
    for (int i = 0; i < student.size(); i++)
    {
        if (student[i].testScore >= 90)
        {
            student[i].grade = 'A';
        }
        else if (student[i].testScore >= 80)
        {
            student[i].grade = 'B';
        }
        else if (student[i].testScore >= 70)
        {
            student[i].grade = 'C';
        }
        else if (student[i].testScore >= 60)
        {
            student[i].grade = 'D';
        }
        else
        {
            student[i].grade = 'F';
        }
    }
}

int highestTestScore(vector<studentType> &student)
{
    int highest = student[0].testScore;
    for (int i = 1; i < student.size(); i++)
    {
        if (student[i].testScore > highest)
        {
            highest = student[i].testScore;
        }
    }
    return highest;
}

void printHighestTestScore(vector<studentType> &student)
{
    int highest = highestTestScore(student);
    for (int i = 0; i < student.size(); i++)
    {
        if (student[i].testScore == highest)
        {
            cout << "---------------------------------" << endl;
            cout << student[i].studentFName << " " << student[i].studentLName << " has the highest test score of " << student[i].testScore << endl;
        }
    }
}

void printData(vector<studentType> &student)
{
    for (int i = 0; i < student.size(); i++)
    {
        cout << "Student Name: " << student[i].studentLName << ", " << student[i].studentFName << endl;
        cout << "Test Score: " << student[i].testScore << endl;
        cout << "Grade: " << student[i].grade << endl;
    }
}

void cinfail()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please try again." << endl;
    }
}
