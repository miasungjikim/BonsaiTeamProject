#include <iostream>
#include <vector>
#include <string>
#include "staff_scheduler.h"

using namespace std;

struct Employee {
    int id;
    string name;
    string contact;
    string role;
    string store;
};

struct Shift {
    string day;
    string timeSlot;
    int employeeId; // -1 means vacant
};

class StaffScheduler {
private:
    vector<Employee> employees;
    vector<Shift> roster;
    int nextEmpId = 1;

    // Helper: Find employee index by ID
    int findEmployeeIndex(int id) {
        for (int i = 0; i < employees.size(); ++i) {
            if (employees[i].id == id) return i;
        }
        return -1;
    }

public:
    // Feature 1: Add employee
    void addEmployee() {
        Employee e;
        e.id = nextEmpId++;
        cout << "\nEnter employee name: ";
        getline(cin, e.name);
        cout << "Enter contact info: ";
        getline(cin, e.contact);
        cout << "Enter job role: ";
        getline(cin, e.role);
        cout << "Enter store (Wellington/Christchurch/Auckland): ";
        getline(cin, e.store);

        if (e.name.empty() || e.contact.empty() || e.role.empty() || e.store.empty()) {
            cout << "Error: Please fill all fields!\n";
            return;
        }
        employees.push_back(e);
        cout << "Employee added successfully!\n";
    }

    // Feature 2: Delete employee
    void deleteEmployee() {
        viewEmployees();
        cout << "Enter Employee ID to delete: ";
        int id;
        cin >> id; cin.ignore();
        int idx = findEmployeeIndex(id);
        if (idx == -1) {
            cout << "Error: Employee not found!\n";
            return;
        }
        employees.erase(employees.begin() + idx);
        cout << "Employee deleted successfully!\n";
    }

    void viewEmployees() {
        cout << "\n-- Employee List --\n";
        if (employees.empty()) cout << "No employees.\n";
        for (auto& e : employees) {
            cout << "ID: " << e.id << ", Name: " << e.name << ", Store: " << e.store << ", Role: " << e.role << '\n';
        }
    }

    // Feature 3: View roster
    void viewRoster() {
        cout << "Enter store (Wellington/Christchurch/Auckland): ";
        string store; getline(cin, store);
        cout << "\n--- Roster for " << store << " ---\n";
        bool found = false;
        for (auto& shift : roster) {
            for (auto& e : employees) {
                if (e.id == shift.employeeId && e.store == store) {
                    cout << shift.day << " " << shift.timeSlot << ": " << e.name << " (" << e.role << ")\n";
                    found = true;
                }
            }
            if (shift.employeeId == -1) {
                cout << shift.day << " " << shift.timeSlot << ": [VACANT]\n";
                found = true;
            }
        }
        if (!found) cout << "No shifts assigned yet.\n";
    }

    // Feature 4: Edit roster
    void editRoster() {
        cout << "Enter day (e.g. Monday): ";
        string day; getline(cin, day);
        cout << "Enter time slot (e.g. Morning/Afternoon/Evening): ";
        string time; getline(cin, time);

        // Check if shift exists, otherwise add new
        int shiftIdx = -1;
        for (int i = 0; i < roster.size(); ++i) {
            if (roster[i].day == day && roster[i].timeSlot == time) {
                shiftIdx = i;
                break;
            }
        }
        if (shiftIdx == -1) {
            Shift s{day, time, -1};
            roster.push_back(s);
            shiftIdx = roster.size() - 1;
        }

        cout << "1. Assign staff to shift\n2. Remove staff from shift\nSelect: ";
        int choice; cin >> choice; cin.ignore();

        if (choice == 1) {
            viewEmployees();
            cout << "Enter Employee ID to assign: ";
            int id; cin >> id; cin.ignore();
            if (findEmployeeIndex(id) == -1) {
                cout << "Error: Employee not found!\n";
                return;
            }
            roster[shiftIdx].employeeId = id;
            cout << "Shift assigned!\n";
        } else if (choice == 2) {
            roster[shiftIdx].employeeId = -1;
            cout << "Shift unassigned!\n";
        } else {
            cout << "Invalid choice.\n";
        }
    }
};

// --- Main function: Only function calls here ---
void manageStaffSchedule() {
    StaffScheduler ss;
    int option;

    while (true) {
        cout << "\nStaff Scheduling\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. View Employees\n";
        cout << "4. View Weekly Roster\n";
        cout << "5. Edit Weekly Roster\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        cin >> option; cin.ignore();

        switch(option) {
            case 1: ss.addEmployee(); break;
            case 2: ss.deleteEmployee(); break;
            case 3: ss.viewEmployees(); break;
            case 4: ss.viewRoster(); break;
            case 5: ss.editRoster(); break;
            case 0: cout << "Goodbye!\n"; return ;
            default: cout << "Invalid!\n";
        }
    }
}
