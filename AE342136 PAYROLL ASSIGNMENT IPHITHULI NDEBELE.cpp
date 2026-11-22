
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// This function makes sure the user enters a valid number.
int getInteger(string prompt, int minimum, int maximum) {
    int number;

    while (true) {
        cout << prompt;

        if (cin >> number && number >= minimum && number <= maximum) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }

        cout << "Invalid input. Please enter a number between "
             << minimum << " and " << maximum << ".\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Ask for the employee's salary and make sure it is more than zero.
double getSalary() {
    double salary;

    while (true) {
        cout << "Enter basic monthly salary (R): ";

        if (cin >> salary && salary > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return salary;
        }

        cout << "Invalid salary. Please enter an amount greater than R0.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Get the employee's name.
string getName() {
    string name;

    while (true) {
        cout << "Enter employee full name: ";
        getline(cin, name);

        if (!name.empty()) {
            return name;
        }

        cout << "Please enter the employee's name.\n";
    }
}

// Each department has its own bonus percentage.
double getDepartmentRate(int department) {
    switch (department) {
        case 1:
            return 0.03;   // Sales
        case 2:
            return 0.02;   // IT
        case 3:
            return 0.025;  // Finance
        case 4:
            return 0.015;  // HR
        case 5:
            return 0.01;   // Operations
        default:
            return 0.0;
    }
}

// Display the department name on the payslip.
string getDepartmentName(int department) {
    switch (department) {
        case 1: return "Sales";
        case 2: return "IT";
        case 3: return "Finance";
        case 4: return "HR";
        case 5: return "Operations";
        default: return "Unknown";
    }
}

// Work out the bonus percentage using the employee's rating.
double getPerformanceRate(int rating) {
    if (rating == 5) {
        return 0.15;
    }
    else if (rating == 4) {
        return 0.10;
    }
    else if (rating == 3) {
        return 0.05;
    }
    else {
        return 0.0;
    }
}

// Employees get an extra bonus depending on how long they have worked.
double getServiceRate(int years) {
    if (years >= 5) {
        return 0.02;
    }
    else if (years >= 2) {
        return 0.01;
    }
    else {
        return 0.0;
    }
}

int main() {
    cout << "============================================\n";
    cout << "       GAUTENG CITY COLLEGE PAYROLL\n";
    cout << "============================================\n";

    int employeeCount = getInteger(
        "How many employees do you want to process? ", 1, 50
    );

    double grandTotal = 0.0;

    // Repeat the same steps for every employee.
    for (int i = 1; i <= employeeCount; i++) {
        cout << "\n--- Employee " << i << " of " << employeeCount << " ---\n";

        int employeeId = getInteger("Enter employee ID (1-999999): ", 1, 999999);
        string employeeName = getName();
        double basicSalary = getSalary();

        cout << "\nChoose department:\n";
        cout << "1. Sales\n";
        cout << "2. IT\n";
        cout << "3. Finance\n";
        cout << "4. HR\n";
        cout << "5. Operations\n";

        int department = getInteger("Enter department number (1-5): ", 1, 5);
        int rating = getInteger("Enter performance rating (1-5): ", 1, 5);
        int years = getInteger("Enter years of service (0-50): ", 0, 50);

        // Calculate the three bonuses and add them together.
        double performanceBonus = basicSalary * getPerformanceRate(rating);
        double departmentBonus = basicSalary * getDepartmentRate(department);
        double serviceBonus = basicSalary * getServiceRate(years);

        double bonusAmount = performanceBonus + departmentBonus + serviceBonus;
        double totalPay = basicSalary + bonusAmount;

        cout << fixed << setprecision(2);
        cout << "\n========== PAYSLIP ==========\n";
        cout << "Employee ID:       " << employeeId << "\n";
        cout << "Employee Name:     " << employeeName << "\n";
        cout << "Department:        " << getDepartmentName(department) << "\n";
        cout << "Basic Salary:      R" << basicSalary << "\n";
        cout << "Performance Bonus: R" << performanceBonus << "\n";
        cout << "Department Bonus:  R" << departmentBonus << "\n";
        cout << "Service Bonus:     R" << serviceBonus << "\n";
        cout << "Total Bonus:       R" << bonusAmount << "\n";
        cout << "TOTAL PAY:         R" << totalPay << "\n";
        cout << "=============================\n";

        grandTotal = grandTotal + totalPay;
    }

    cout << fixed << setprecision(2);
    cout << "\nEmployees processed: " << employeeCount << "\n";
    cout << "Combined total payroll: R" << grandTotal << "\n";
    cout << "Thank you for using the payroll system.\n";

    return 0;
}
