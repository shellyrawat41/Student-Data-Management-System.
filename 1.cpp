#include <iostream>
#include <sstream>
#include <vector>
#include <thread> // Include for std::this_thread::sleep_for
#include <chrono> // Include for std::chrono::seconds

using namespace std;

class University {
private:
    string RollNo, Name, Subject, Address;
public:
    University() : RollNo(""), Name(""), Subject(""), Address("") {}

    void setRollNo(string rollNo) {
        RollNo = rollNo;
    }

    void setName(string name) {
        Name = name;
    }

    void setSubject(string subject) {
        Subject = subject;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getRollNo() const { // Marked as const
        return RollNo;
    }

    string getName() const { // Marked as const
        return Name;
    }

    string getSubject() const { // Marked as const
        return Subject;
    }

    string getAddress() const { // Marked as const
        return Address;
    }
};

void add(vector<University>& students) {
    University student;
    string rollNo, name, subject, address;

    cout << "\tEnter RollNo Of Student: ";
    cin >> rollNo;
    student.setRollNo(rollNo);

    cout << "\tEnter Name Of Student: ";
    cin >> name;
    student.setName(name);

    cout << "\tEnter Subject Of Student: ";
    cin >> subject;
    student.setSubject(subject);

    cout << "\tEnter Address Of Student: ";
    cin >> address;
    student.setAddress(address);

    students.push_back(student); // Store the student in the vector
    cout << "\tStudent Added Successfully!" << endl;
}

void search(const vector<University>& students) {
    string rollNo;
    cout << "\tEnter RollNo Of Student: ";
    cin >> rollNo;

    bool found = false;
    for (const auto& student : students) {
        if (student.getRollNo() == rollNo) {
            cout << "\t" << student.getRollNo() << " : " << student.getName() << " : "
                 << student.getSubject() << " : " << student.getAddress() << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\tStudent Not Found!" << endl;
    }
}

void update(vector<University>& students) {
    string rollNo;
    cout << "\tEnter RollNo Of Student: ";
    cin >> rollNo;

    bool found = false;
    for (auto& student : students) {
        if (student.getRollNo() == rollNo) {
            string newAddress;
            cout << "\tEnter New Address: ";
            cin >> newAddress;
            student.setAddress(newAddress);
            found = true;
            cout << "\tData Updated!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "\tStudent Not Found!" << endl;
    }
}

int main() {
    vector<University> students; // Use a vector to store students

    bool exit = false;
    while (!exit) {
        system("cls"); // Clear the console (may not work in some online compilers)
        int val;
        cout << "\tWelcome To University Management System" << endl;
        cout << "\t***************************************" << endl;
        cout << "\t1. Add Student." << endl;
        cout << "\t2. Search Student." << endl;
        cout << "\t3. Update Data Of Student." << endl;
        cout << "\t4. Exit." << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            add(students);
            this_thread::sleep_for(chrono::seconds(6));
        } else if (val == 2) {
            system("cls");
            search(students);
            this_thread::sleep_for(chrono::seconds(6));
        } else if (val == 3) {
            system("cls");
            update(students);
            this_thread::sleep_for(chrono::seconds(6));
        } else if (val == 4) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
    }
    return 0;
}
