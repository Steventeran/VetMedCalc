
import os
import sys

def display_menu():
    print("\nPlease select a calculation:")
    print("1. Medication Dosage")
    print("2. Fluid Therapy Rate")
    print("3. Exit")

def calculate_dosage():
    try:
        weight = float(input("\nEnter the animal's weight: "))
        unit = input("Is the weight in kilograms (kg) or pounds (lb)? Enter 'kg' or 'lb': ").strip().lower()

        if unit == "lb":
            weight /= 2.20462  # Convert pounds to kilograms
            print(f"Converted weight: {weight:.2f} kg")
        elif unit != "kg":
            print("Invalid unit. Assuming kilograms.")

        dose_per_kg = float(input("Enter the dosage per kilogram (mg/kg): "))
        total_dose = weight * dose_per_kg
        print(f"The total dosage required is: {total_dose:.2f} mg")

        log_entry = f"Dosage Calculation: Weight = {weight:.2f} kg, Dosage = {total_dose:.2f} mg\n"
        save_log(log_entry)
    except ValueError:
        print("Invalid input. Please enter numeric values where applicable.")

def calculate_fluid_therapy():
    try:
        weight = float(input("\nEnter the animal's weight in kilograms (kg): "))
        rate_per_kg = float(input("Enter the fluid rate per kilogram (mL/kg/hour): "))

        total_rate = weight * rate_per_kg
        print(f"The total fluid rate is: {total_rate:.2f} mL/hour")

        log_entry = f"Fluid Therapy Calculation: Weight = {weight:.2f} kg, Rate = {total_rate:.2f} mL/hour\n"
        save_log(log_entry)
    except ValueError:
        print("Invalid input. Please enter numeric values where applicable.")

def save_log(log_entry):
    try:
        with open("vet_med_calculator_log.txt", "a") as log_file:
            log_file.write(log_entry)
        print("Calculation logged successfully.")
    except IOError:
        print("Error: Unable to open log file.")

def main():
    print("\nWelcome to the Veterinary Medicine Calculator!")

    while True:
        display_menu()
        try:
            choice = int(input("Enter your choice: "))
            if choice == 1:
                calculate_dosage()
            elif choice == 2:
                calculate_fluid_therapy()
            elif choice == 3:
                print("Exiting the calculator. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")
        except ValueError:
            print("Please enter a valid number.")

if __name__ == "__main__":
    main()
