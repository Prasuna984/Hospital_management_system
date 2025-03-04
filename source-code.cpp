#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Patient {
public:
    string name;
    int age;
    string disease;

    Patient(string n, int a, string d) 
        : name(n), age(a), disease(d) {}
};

class Doctor {
public:
    string name;
    string specialty;
    int experienceYears;

    Doctor(string n, string s, int e) 
        : name(n), specialty(s), experienceYears(e) {}
};

class HospitalManagement {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    map<string, pair<string, string>> appointments;  // Maps patient's name to <doctor's name, appointment time>

public:
    void addPatient() {
        string name, disease;
        int age;

        cout << "Enter patient's name: ";
        cin >> name;
        cout << "Enter patient's age: ";
        cin >> age;
        cout << "Enter patient's disease: ";
        cin >> disease;

        Patient newPatient(name, age, disease);
        patients.push_back(newPatient);
        cout << "Patient added successfully!\n";
    }

    void viewPatients() {
        if (patients.empty()) {
            cout << "No patients found.\n";
            return;
        }

        cout << "List of Patients:\n";
        for (size_t i = 0; i < patients.size(); ++i) {
            cout << "Patient " << (i + 1) << ":\n";
            cout << "Name: " << patients[i].name << "\n";
            cout << "Age: " << patients[i].age << "\n";
            cout << "Disease: " << patients[i].disease << "\n\n";
        }
    }

    void addDoctor() {
        string name, specialty;
        int experienceYears;

        cout << "Enter doctor's name: ";
        cin >> name;
        cout << "Enter doctor's specialty: ";
        cin >> specialty;
        cout << "Enter years of experience: ";
        cin >> experienceYears;

        Doctor newDoctor(name, specialty, experienceYears);
        doctors.push_back(newDoctor);
        cout << "Doctor added successfully!\n";
    }

    void viewDoctors() {
        if (doctors.empty()) {
            cout << "No doctors found.\n";
            return;
        }

        cout << "List of Doctors:\n";
        for (size_t i = 0; i < doctors.size(); ++i) {
            cout << "Doctor " << (i + 1) << ":\n";
            cout << "Name: " << doctors[i].name << "\n";
            cout << "Specialty: " << doctors[i].specialty << "\n";
            cout << "Years of Experience: " << doctors[i].experienceYears << "\n\n";
        }
    }

    void viewDoctorsBySpecialty() {
        string specialty;
        cout << "Enter the specialty needed: ";
        cin >> specialty;

        bool found = false;
        cout << "Doctors with specialty " << specialty << ":\n";
        for (const auto& doctor : doctors) {
            if (doctor.specialty == specialty) {
                found = true;
                cout << "Name: " << doctor.name << ", Experience: " << doctor.experienceYears << " years\n";
            }
        }
        if (!found) {
            cout << "No doctors found with that specialty.\n";
        }
    }

    void scheduleAppointment() {
        if (patients.empty() || doctors.empty()) {
            cout << "Please add both patients and doctors before scheduling an appointment.\n";
            return;
        }

        string patientName, doctorName, time;
        cout << "Enter patient's name for appointment: ";
        cin >> patientName;
        cout << "Enter doctor's name for appointment: ";
        cin >> doctorName;
        cout << "Enter appointment time (e.g., 10:30 AM): ";
        cin.ignore();
        getline(cin, time);

        bool patientExists = false, doctorExists = false;
        for (const auto& patient : patients) {
            if (patient.name == patientName) {
                patientExists = true;
                break;
            }
        }

        for (const auto& doctor : doctors) {
            if (doctor.name == doctorName) {
                doctorExists = true;
                break;
            }
        }

        if (!patientExists || !doctorExists) {
            cout << "Invalid patient or doctor name. Please try again.\n";
            return;
        }

        appointments[patientName] = {doctorName, time};
        cout << "Appointment scheduled successfully between " << patientName << " and Dr. " << doctorName << " at " << time << "!\n";
    }

    void viewAppointments() {
        if (appointments.empty()) {
            cout << "No appointments scheduled.\n";
            return;
        }

        cout << "Scheduled Appointments:\n";
        for (const auto& appointment : appointments) {
            cout << "Patient: " << appointment.first << " has an appointment with Dr. " << appointment.second.first << " at " << appointment.second.second << "\n";
        }
    }

    void menu() {
        int choice;
        do {
            cout << "Hospital Management System\n";
            cout << "1. Add Patient\n";
            cout << "2. View Patients\n";
            cout << "3. Add Doctor\n";
            cout << "4. View Doctors\n";
            cout << "5. Schedule Appointment\n";
            cout << "6. View Appointments\n";
            cout << "7. View Doctors by Specialty\n";
            cout << "8. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addPatient();
                    break;
                case 2:
                    viewPatients();
                    break;
                case 3:
                    addDoctor();
                    break;
                case 4:
                    viewDoctors();
                    break;
                case 5:
                    scheduleAppointment();
                    break;
                case 6:
                    viewAppointments();
                    break;
                case 7:
                    viewDoctorsBySpecialty();
                    break;
                case 8:
                    cout << "Exiting the program.\n";
                    break;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 8);
    }
};

int main() {
    HospitalManagement system;
    system.menu();
    return 0;
}