cgpa_calculator.cpp/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Course {
    string name;
    double grade;
    double credits;
};

int main() {
    int n;
    double totalCredits = 0;
    double totalGradePoints = 0;

    cout << "===== CGPA CALCULATOR =====\n";

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses!\n";
        return 0;
    }

    vector<Course> courses(n);

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter course name (no spaces): ";
        cin >> courses[i].name;

        cout << "Enter grade points (0 to 10): ";
        cin >> courses[i].grade;

        cout << "Enter credit hours: ";
        cin >> courses[i].credits;

        if (courses[i].grade < 0 ||
            courses[i].grade > 10 ||
            courses[i].credits <= 0) {
            cout << "Invalid grade or credits!\n";
            return 0;
        }

        totalGradePoints +=
            courses[i].grade * courses[i].credits;

        totalCredits += courses[i].credits;
    }

    double gpa = totalGradePoints / totalCredits;

    cout << "\n===== RESULT =====\n";
    cout << fixed << setprecision(2);

    cout << "\nCourse Details:\n";

    for (int i = 0; i < n; i++) {
        cout << courses[i].name
             << " | Grade: " << courses[i].grade
             << " | Credits: " << courses[i].credits
             << endl;
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nSemester GPA: " << gpa;

    char choice;
    cout << "\nDo you want to calculate overall CGPA? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        double previousCGPA, previousCredits;

        cout << "Enter previous CGPA: ";
        cin >> previousCGPA;

        cout << "Enter total previous credits: ";
        cin >> previousCredits;

        if (previousCGPA < 0 || previousCGPA > 10 ||
            previousCredits < 0) {
            cout << "Invalid previous academic details!\n";
            return 0;
        }

        double overallCGPA =
            (previousCGPA * previousCredits +
             totalGradePoints) /
            (previousCredits + totalCredits);

        cout << "Overall CGPA: " << overallCGPA << endl;
    } else {
        cout << "\nYou can calculate overall CGPA later.\n";
    }

    cout << "\nThank you for using CGPA Calculator!\n";

    return 0;
}
