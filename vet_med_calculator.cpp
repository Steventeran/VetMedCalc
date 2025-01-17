
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes
void calculateDosage();
void calculateFluidTherapy();
void saveLog(const string&);
void displayMenu();

int main() {
    int choice;
    bool running = true;

    cout << "\nWelcome to the Veterinary Medicine Calculator!\n";

    while (running) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                calculateDosage();
                break;
            case 2:
                calculateFluidTherapy();
                break;
            case 3:
                cout << "Exiting the calculator. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\nPlease select a calculation:\n";
    cout << "1. Medication Dosage\n";
    cout << "2. Fluid Therapy Rate\n";
    cout << "3. Exit\n";
}

void calculateDosage() {
    double weight, dosePerKg, totalDose;
    string unit;

    cout << "\n--- Medication Dosage Calculator ---\n";
    cout << "Enter the animal's weight: ";
    cin >> weight;
    cout << "Is the weight in kilograms (kg) or pounds (lb)? Enter 'kg' or 'lb': ";
    cin >> unit;

    if (unit == "lb") {
        weight /= 2.20462; // Convert pounds to kilograms
        cout << "Converted weight: " << fixed << setprecision(2) << weight << " kg\n";
    } else if (unit != "kg") {
        cout << "Invalid unit. Assuming kilograms.\n";
    }

    cout << "Enter the dosage per kilogram (mg/kg): ";
    cin >> dosePerKg;

    totalDose = weight * dosePerKg;
    cout << "The total dosage required is: " << fixed << setprecision(2) << totalDose << " mg\n";

    string log = "Dosage Calculation: Weight = " + to_string(weight) + " kg, Dosage = " + to_string(totalDose) + " mg\n";
    saveLog(log);
}

void calculateFluidTherapy() {
    double weight, ratePerKg, totalRate;

    cout << "\n--- Fluid Therapy Rate Calculator ---\n";
    cout << "Enter the animal's weight in kilograms (kg): ";
    cin >> weight;
    cout << "Enter the fluid rate per kilogram (mL/kg/hour): ";
    cin >> ratePerKg;

    totalRate = weight * ratePerKg;
    cout << "The total fluid rate is: " << fixed << setprecision(2) << totalRate << " mL/hour\n";

    string log = "Fluid Therapy Calculation: Weight = " + to_string(weight) + " kg, Rate = " + to_string(totalRate) + " mL/hour\n";
    saveLog(log);
}

void saveLog(const string& logEntry) {
    ofstream logFile("vet_med_calculator_log.txt", ios::app);

    if (logFile.is_open()) {
        logFile << logEntry;
        logFile.close();
        cout << "Calculation logged successfully.\n";
    } else {
        cout << "Error: Unable to open log file.\n";
    }
}
