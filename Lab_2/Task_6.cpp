#include <iostream>
#include <vector>
using namespace std;
struct Subject {
    string name;
};

struct Student {
    int id;
    vector<Subject> subjects;
};

int main() {
    vector<Student> students;
    students.push_back({1, { {"Math"}, {"Science"}, {"History"} }});
    students.push_back({2, { {"English"}, {"Physics"}, {"Chemistry"} }});
    for (const auto& student : students) {
        cout << "ID: " << student.id << "\nSubjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.name << " ";
        }
        cout << endl;
    }
    return 0;
}