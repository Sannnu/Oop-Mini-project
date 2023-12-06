#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Class for patient information
class Patient {
private:
    string name;
    int age;
    string contact;
    string testResult;

public:
    // Set patient data
    void setPatientData(string n, int a, string c, string tr) {
        name = n;
        age = a;
        contact = c;
        testResult = tr;
    }

    // Display patient data
    void displayPatientData() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Test Result: " << testResult << endl;
    }

    // Getters for private members
    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    const string& getContact() const {
        return contact;
    }

    const string& getTestResult() const {
        return testResult;
    }
};

// Function to add patient information to a file
void addPatientToFile(const Patient& patient, const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << "Name: " << patient.getName() << endl;
        file << "Age: " << patient.getAge() << endl;
        file << "Contact: " << patient.getContact() << endl;
        file << "Test Result: " << patient.getTestResult() << endl;
        file << endl;
        file.close();
        cout << "Patient information written to file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

// Function to display patient information from a file
void displayPatientsFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    int choice;
    string filename = "patients.txt";

    do {
        cout << "\nCOVID-19 Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Patient patient;
                string name, contact, testResult;
                int age;

                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter patient age: ";
                cin >> age;

                cout << "Enter contact number: ";
                cin >> contact;

                cout << "Enter test result: ";
                cin >> testResult;

                patient.setPatientData(name, age, contact, testResult);
                addPatientToFile(patient, filename);
                break;
            }

            case 2:
                cout << "\nPatient Information:\n";
                displayPatientsFromFile(filename);
                break;

            case 3:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}
