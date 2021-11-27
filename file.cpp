// Programmer: Kristina Fout
// Programmer ID: 1866884

#include <iostream>
#include <fstream>
using namespace std;

struct studentRecords
{
    string studentName;
    double studentGrade;
    int studentAbsences;
};

int main()
{
    cout << "Programmer: Kristina Fout\n";
    cout << "Programmer ID: 1866884\n";
    cout << "file: " << __FILE__ << "\n\n";
    
    string filename = "file.csv";
    ofstream outputFile(filename.c_str());
    
    if(!outputFile)
    {
        cout << "Error in opening file!";
        return 0;
    }

    studentRecords student[5] =
    {
        {"Kris", 98.72, 0},

        {"John", 83.21, 2},

        {"Jess", 70.56, 0},
        
        {"Sean", 91.23, 1},
        
        {"Anne", 68.34, 4}
    };

    outputFile << "Name, Grade, Absences" << endl;

    for(int i = 0; i < 5; i++)

    {
        outputFile << student[i].studentName << ", " << student[i].studentGrade << ", " << student[i].studentAbsences << endl;
    }

    outputFile.close();

}


