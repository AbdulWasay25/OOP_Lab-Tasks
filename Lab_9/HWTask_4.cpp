#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        virtual double getTuition(const string& status, int creditHours) const = 0;
};

class GraduateStudent : public Student {
    private:
        string researchTopic;
    public:
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }
    string getResearchTopic() const {
        return researchTopic;
    }
    double getTuition(const string& status, int creditHours) const override {
        double rate = 0;
        if (status == "undergraduate") {
            rate = 200;
        } else if (status == "graduate") {
            rate = 300;
        } else if (status == "doctoral") {
            rate = 400;
        } else {
            cout << "Invalid status provided." << endl;
            return 0;
        }
        return rate * creditHours;
    }
};

int main() {
    GraduateStudent grad;
    grad.setResearchTopic("Artificial Intelligence in Education");
    string status;
    int creditHours;
    cout << "Enter student status (undergraduate, graduate, doctoral): ";
    cin >> status;
    cout << "Enter number of credit hours: ";
    cin >> creditHours;
    cout << "\nResearch Topic: " << grad.getResearchTopic() << endl;
    cout << "Tuition Fee: $" << grad.getTuition(status, creditHours) << endl;

    return 0;
}
