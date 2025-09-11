#include <iostream>
#include <fstream>

using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void getData(studentType student[], int maxsize);
void calcGrade(studentType student[], int size);
void printData(const studentType student[], int size);
int highestTestScore(studentType student[], int size);
void printHighestTestScore(studentType student[], int size);
void cinfail();


int main() {
    const int maxsize = 3;
    studentType student[maxsize];

    ifstream infile;

    infile.open("students.txt");
    if(!infile){
        cout << "Error opening file." << endl;
        exit(1);
    }

    while(!infile.eof()){
        for(int i = 0; i < maxsize; i++){
            infile >> student[i].studentFName
                   >> student[i].studentLName
                   >> student[i].testScore
                   >> student[i].grade;
        }
    }
    infile.close();

    getData(student, maxsize);
    calcGrade(student, maxsize);
    printData(student, maxsize);
    printHighestTestScore(student, maxsize);

    ofstream outfile;
    outfile.open("students.txt");
    if(!outfile){
        cout << "Error opening file." << endl;
        exit(1);
    }

    for(int i = 0; i < maxsize; i++){
        outfile << student[i].studentFName << " "
                << student[i].studentLName << " "
                << student[i].testScore << " "
                << student[i].grade << endl;
    }

    outfile.close();

    return 0;
}


void getData(studentType student[],int maxsize){
    for (int i = 0; i < maxsize; i++){
        cout << "Enter first name: ";
        cin >> student[i].studentFName;
        cinfail();
        cout << "Enter last name: ";
        cin >> student[i].studentLName;
        cinfail();
        cout << "Enter test score: ";
        cin >> student[i].testScore;
        cinfail();
    }
}

void calcGrade(studentType student[], int size){
    for(int i = 0; i < size; i++){
        if(student[i].testScore >= 90){
            student[i].grade = 'A';
        }
        else if(student[i].testScore >= 80){
            student[i].grade = 'B';
        }
        else if(student[i].testScore >= 70){
            student[i].grade = 'C';
        }
        else if(student[i].testScore >= 60){
            student[i].grade = 'D';
        }
        else{
            student[i].grade = 'F';
        }
    }
}

int highestTestScore(studentType student[], int size){
    int highest = student[0].testScore;
    for(int i = 1; i < size; i++){
        if(student[i].testScore > highest){
            highest = student[i].testScore;
        }
    }
    return highest;
}

void printHighestTestScore(studentType student[], int size){
  int highest = highestTestScore(student, size);
  for (int i = 0; i < size; i++) {
    if (student[i].testScore == highest){
      cout << "---------------------------------"<<endl;
      cout << student[i].studentFName  << " " << student[i].studentLName << " has the highest test score of " << student[i].testScore << endl;
    }
  }
}

void printData(const studentType student[], int size){
    for(int i = 0; i < size; i++){
        cout << "Student Name: " << student[i].studentLName << ", "  << student[i].studentFName << endl;
        cout << "Test Score: " << student[i].testScore << endl;
        cout << "Grade: " << student[i].grade << endl;
    }
}

void cinfail(){
    if(cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid input. Please try again." << endl;
    }
}
