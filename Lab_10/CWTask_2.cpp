#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

struct Employee {
    int ID;
    string name;
    string des;
    int years;
};

Employee parseline(const string& line) {
    stringstream ss(line);
    Employee emp;
    string field;

    getline(ss, field, ',');
    emp.ID = stoi(field);
    getline(ss, emp.name, ',');
    getline(ss, emp.des, ',');
    getline(ss, field, ',');
    emp.years = stoi(field);

    return emp;
}

string to_empstruct(const Employee& emp) {
    return to_string(emp.ID) + " , "  + emp.name + " , " + emp.des + " , " + to_string(emp.years);
}

void sampledata() {
    vector<Employee> data = {
        {1, "Abdul Wasay", "Manager", 3},
        {2, "Umais Mustafa", "Manager", 3},
        {3, "Some One", "CEO", 1}
    };

    ofstream file("Task2.txt");
    for (const auto& emp : data) {
        file << to_empstruct(emp) << endl;
    }
    file.close();
}

vector<Employee> Reademployees() {
    ifstream ifile("Task2.txt");
    vector<Employee> emps;
    string line;
    while (getline(ifile, line)) {
        if (!line.empty()) {
            emps.push_back(parseline(line));
        }
    }
    ifile.close();
    return emps;
}

void writeemptofile(const vector<Employee>& emp) {
    ofstream file("Task2.txt");
    for (const auto& employee : emp) {
        file << to_empstruct(employee) << endl;
    }
    file.close();
}

int main() {
    sampledata();

    vector<Employee> allemps = Reademployees();
    vector<Employee> Managers;

    for (const auto& emp : allemps) {
        if (emp.des == "Manager" && emp.years >= 2) {
            Managers.push_back(emp);
        }
    }

    for (auto& emp : Managers) {        //increment ID and years
        emp.ID += 100;
        emp.years += 1;
    }

    writeemptofile(Managers);

    cout << "\nFinal Data in File:" << endl;
    for (const auto& emp : Managers) {
        cout << to_empstruct(emp) << endl;
    }

    return 0;
}
