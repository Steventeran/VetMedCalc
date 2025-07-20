
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    char more = 'y';

    while (more == 'y' || more == 'Y') {
        string patientName, species;
        double W, FR, FR1, BUP, DEX = 0, PF, PF1, RIM, CR, ANT, fluid_rate_min, fluid_rate_max;

        // Input: Patient Info
        cout << "\nEnter the patient's name: ";
        cin >> patientName;

        cout << "Is this a dog or cat? ";
        cin >> species;
        transform(species.begin(), species.end(), species.begin(), ::tolower);

        cout << "Enter " << patientName << "'s weight in lbs: ";
        cin >> W;
        while (W <= 0) {
            cout << "Please enter a valid weight (> 0): ";
            cin >> W;
        }

        // Convert to kg
        double weight_kg = W / 2.2;

        // Output: Basic Info
        cout << "\n--- Patient Info ---\n";
        cout << "Name: " << patientName << endl;
        cout << "Species: " << species << endl;
        cout << "Weight: " << fixed << setprecision(2) << W << " lbs (" << weight_kg << " kg)\n";

        // Fluid rates
        fluid_rate_min = weight_kg * 3;
        fluid_rate_max = weight_kg * 5;

        FR1 = (W * 10) / 8;
        FR = FR1 + 0.75 * FR1;

        cout << "\n--- Fluid Rate Calculations ---\n";
        cout << "Surgical Fluid Rate: " << fluid_rate_min << " mL/hr to " << fluid_rate_max << " mL/hr" << endl;
        cout << "Fluid Replacement Rate: " << round(FR) << " mL" << endl;

        // Meds
        BUP = ((W / 2.2) * 0.02) / 0.6;

        // Dexdomitor dosage
        if (W >= 4 && W < 7) DEX = 0.06;
        else if (W < 2 && W >= 0.01) DEX = 0.015;
        else if (W < 4 && W >= 2) DEX = 0.03;
        else if (W >= 7 && W < 9) DEX = 0.075;
        else if (W >= 9 && W < 11) DEX = 0.10;
        else if (W >= 11 && W < 22) DEX = 0.145;
        else if (W >= 22 && W < 29) DEX = 0.19;
        else if (W >= 29 && W < 33) DEX = 0.22;
        else if (W >= 33 && W < 44) DEX = 0.25;
        else if (W >= 44 && W < 55) DEX = 0.30;
        else if (W >= 55 && W < 66) DEX = 0.345;
        else if (W >= 66 && W < 73) DEX = 0.375;
        else if (W >= 73 && W < 81) DEX = 0.405;
        else if (W >= 81 && W < 99) DEX = 0.45;
        else if (W >= 99 && W < 110) DEX = 0.495;
        else if (W >= 110 && W < 121) DEX = 0.53;
        else if (W >= 121 && W < 132) DEX = 0.565;
        else if (W >= 132 && W < 143) DEX = 0.595;
        else if (W >= 143 && W < 154) DEX = 0.63;
        else if (W >= 154 && W < 176) DEX = 0.675;
        else if (W >= 176) DEX = 0.71;

        // Antisedan = 1:1 mL to Dexdomitor
        ANT = DEX;

        // Propofol
        PF = (W / 2.2) * 3 / 10;
        PF1 = (W / 2.2) * 5 / 10;

        // Rimadyl
        RIM = (W / 2.2) * 4.4 / 50;

        // Cerenia
        CR = W / 22;

        // Table Output
        cout << "\n--- Medication Dosages ---\n";
        cout << left << setw(25) << "Medication"
             << setw(18) << "Concentration"
             << setw(10) << "Dose (mL)"
             << setw(10) << "Route" << endl;

        cout << setw(25) << "Buprenex"
             << setw(18) << "0.6 mg/mL"
             << setw(10) << BUP
             << setw(10) << "IM/IV" << endl;

        cout << setw(25) << "Dexdomitor"
             << setw(18) << "0.5 mg/mL"
             << setw(10) << DEX
             << setw(10) << "IM" << endl;

        cout << setw(25) << "Antisedan"
             << setw(18) << "5 mg/mL"
             << setw(10) << ANT
             << setw(10) << "IM" << endl;

        cout << setw(25) << "Propofol (3 mg/kg)"
             << setw(18) << "10 mg/mL"
             << setw(10) << PF
             << setw(10) << "IV" << endl;

        cout << setw(25) << "Propofol (5 mg/kg)"
             << setw(18) << "10 mg/mL"
             << setw(10) << PF1
             << setw(10) << "IV" << endl;

        cout << setw(25) << "Rimadyl"
             << setw(18) << "50 mg/mL"
             << setw(10) << RIM
             << setw(10) << "SQ/PO" << endl;

        cout << setw(25) << "Cerenia"
             << setw(18) << "10 mg/mL"
             << setw(10) << CR
             << setw(10) << "SQ/IV" << endl;

        // Notes

        cout << "\nNote: Antisedan dose = " << fixed << setprecision(2) << ANT << " mL IM (1:1 with Dexdomitor). Propofol is given IV to effect.\n";

        // Repeat?
        cout << "\nWould you like to calculate for another animal? (y/n): ";
        cin >> more;
        cout << "\n---------------------------------------------\n";
    }

    return 0;
}
