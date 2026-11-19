#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Student {
public:
    int id;
    string name, course;
    float marks;

    Student(int i, string n, string c, float m) {
        id = i;
        name = n;
        course = c;
        marks = m;
    }

    string getGrade() {
        if (marks >= 90) return "A+";
        else if (marks >= 80) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 60) return "C";
        else if (marks >= 40) return "D";
        else return "F";
    }

    void display() {
        cout << "\nStudent ID : " << id;
        cout << "\nName       : " << name;
        cout << "\nCourse     : " << course;
        cout << "\nMarks      : " << marks;
        cout << "\nPercentage : " << marks << "%";
        cout << "\nGrade      : " << getGrade() << endl;
    }
};

class StudentPortal {
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name, course;
        float marks;

        cout << "\nEnter Student ID: ";
        if (!(cin >> id) || id <= 0) {
            cout << "Invalid Student ID!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        for (const auto &s : students) {
            if (s.id == id) {
                cout << "Student ID already exists!\n";
                return;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks (0-100): ";
        if (!(cin >> marks) || marks < 0 || marks > 100) {
            cout << "Invalid Marks!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        students.emplace_back(id, name, course, marks);

        cout << "\nStudent Added Successfully!\n";
        saveToFile();
    }

    void searchStudent() {
        int id;

        cout << "\nEnter Student ID to Search: ";
        if (!(cin >> id)) {
            cout << "Invalid ID!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        for (auto &s : students) {
            if (s.id == id) {
                cout << "\nStudent Found!\n";
                s.display();
                return;
            }
        }

        cout << "Student Not Found!\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "\nNo Student Records Available!\n";
            return;
        }

        cout << "\n===== ALL STUDENT RECORDS =====\n";

        for (auto &s : students) {
            s.display();
            cout << "------------------------\n";
        }
    }

    void saveToFile() {
        ofstream file("students.txt");

        for (auto &s : students) {
            file << s.id << "\n";
            file << s.name << "\n";
            file << s.course << "\n";
            file << s.marks << "\n";
        }

        file.close();
        cout << "Records Saved Successfully!\n";
    }

    void loadFromFile() {
        ifstream file("students.txt");

        int id;
        string name, course;
        float marks;

        while (file >> id) {
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            if (!getline(file, name) ||
                !getline(file, course) ||
                !(file >> marks)) {
                break;
            }

            if (id > 0 && marks >= 0 && marks <= 100) {
                students.emplace_back(id, name, course, marks);
            }

            file.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        file.close();
    }

    void menu() {
        int choice;

        loadFromFile();

        do {
            cout << "\n===== STUDENT PORTAL =====\n";
            cout << "1. Add Student\n";
            cout << "2. Search Student\n";
            cout << "3. Display All Students\n";
            cout << "4. Save Records\n";
            cout << "5. Exit\n";

            cout << "\nEnter Your Choice: ";

            if (!(cin >> choice)) {
                cout << "Invalid Choice!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            switch (choice) {
                case 1:
                    addStudent();
                    break;

                case 2:
                    searchStudent();
                    break;

                case 3:
                    displayStudents();
                    break;

                case 4:
                    saveToFile();
                    break;

                case 5:
                    saveToFile();
                    cout << "Thank You!\n";
                    break;

                default:
                    cout << "Invalid Choice!\n";
            }

        } while (choice != 5);
    }
};

int main() {
    StudentPortal portal;
    portal.menu();

    return 0;
}