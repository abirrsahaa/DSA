#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int id;
    int marks[5];
};

void saveStudentData(Student *students, int numStudents)
{
    ofstream outfile("marks.dat");
    if (!outfile.is_open())
    {
        cout << "Error: Could not open file." << endl;
        return;
    }

    for (int i = 0; i < numStudents; i++)
    {
        outfile << students[i].id << ",";
        for (int j = 0; j < 5; j++)
        {
            outfile << students[i].marks[j] << ",";
        }
        outfile << endl;
    }

    outfile.close();
}

void retrieveStudentData(Student *students, int numStudents)
{
    ifstream infile("marks.dat");
    if (!infile.is_open())
    {
        cout << "Error: Could not open file." << endl;
        return;
    }

    int i = 0;
    while (infile >> students[i].id)
    {
        for (int j = 0; j < 5; j++)
        {
            infile >> students[i].marks[j];
        }
        i++;
    }

    infile.close();
}

void printStudentData(Student *students, int numStudents)
{
    //   cout << "Student ID, Mark 1, Mark 2, Mark 3, Mark 4, Mark 5" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << students[i].id << ",";
        for (int j = 0; j < 5; j++)
        {
            cout << students[i].marks[j] << ",";
        }
        cout << endl;
    }
}

int main()
{
    int numStudents;
    //   cout << "Enter the number of students: ";
    cin >> numStudents;

    Student *students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        // cout << "Enter student ID: ";
        // cin.ignore();
        cin >> students[i].id;
        // cin.ignore();
        for (int j = 0; j < 5; j++)
        {
            //   cout << "Enter mark " << j + 1 << ": ";
            if (i == 0 && j == 0)
            {
                int z;
                cin >> z;
                cout << "i am printing -" << z;
                students[i].marks[j] = z;
            }
            else
                cin >> students[i].marks[j];
        }
    }

    saveStudentData(students, numStudents);

    retrieveStudentData(students, numStudents);

    printStudentData(students, numStudents);

    delete[] students;

    return 0;
}