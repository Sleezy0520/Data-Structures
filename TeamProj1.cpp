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
void printData(vector<studentType> &student, ofstream &outfile);
int highestTestScore(vector<studentType> &student);
void cinfail();

int main()
{
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
    printData(student, outFile);

    inFile.close();
    outFile.close();

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


void printData(vector<studentType> &student, ofstream &outfile)
{
    int highest = highestTestScore(student);
    for (int i = 0; i < student.size(); i++)
    {
        outfile << "Student Name: " << student[i].studentLName << ", " << student[i].studentFName << endl;
        outfile << "Test Score: " << student[i].testScore << endl;
        outfile << "Grade: " << student[i].grade << endl;
        outfile << "---------------------------------" << endl;
    }
    for (int i = 0; i < student.size(); i++)
    {
        if (student[i].testScore == highest)
        {
            outfile << student[i].studentFName << " " << student[i].studentLName << " has the highest test score of " << student[i].testScore << endl;
        }
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
