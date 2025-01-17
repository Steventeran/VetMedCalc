
# Veterinary Medicine Calculator

This project provides a simple command-line tool designed to assist veterinary professionals in performing common medical calculations. The calculator can compute medication dosages, fluid therapy rates, and other essential veterinary metrics. By automating these repetitive calculations, the tool helps save time and reduces the likelihood of errors.

## Features

- **Medication Dosage Calculation:**
  - Allows input in kilograms or pounds
  - Converts units as needed.
  - Computes total dosages based on weight and dosage-per-kg

- **Fluid Therapy Calculation:**
  - Calculates fluid administration rates in mL/hour.
  - Helps determine appropriate therapy volumes based on patient weight

- **User-Friendly Interface:**
  - Simple text-based menus for selecting the desired calculation.
  - Input validation to minimize errors

- **Logging and Record-Keeping:**
  - Saves calculation results to a log file.
  - Provides a historical record of computations for future reference

## How to Use

### C++ Version
1. Compile the C++ source code using a compatible compiler (e.g., g++):
   ```
   g++ -o vet_med_calculator vet_med_calculator.cpp
   ```

2. Run the compiled executable:
   ```
   ./vet_med_calculator
   ```

3. Follow the on-screen prompts to select a calculation and input the necessary parameters.

4. Review the results displayed on-screen. Calculations will also be saved to a log file in the same directory

### Python Version
1. Make sure Python 3.x is installed on your system.

2. Run the Python script:
   ```
   python vet_med_calculator.py
   ```

3. Follow the on-screen prompts to select a calculation and input the necessary parameters.

4. Review the results displayed on-screen. Calculations will also be saved to a log file in the same directory

## Requirements

- For the C++ version: A C++ compiler supporting C++11 or later
- For the Python version: Python 3.x

## Future Enhancements

- Additional veterinary calculations, such as body condition scoring and anesthesia dosages.
- A graphical user interface (GUI) for improved usability
- Integration with online veterinary resources for automatic updates and reference data

With this tool, veterinary professionals can quickly and accurately perform crucial calculations, improving efficiency and patient care. We hope you find it helpful and look forward to seeing how it evolves!
