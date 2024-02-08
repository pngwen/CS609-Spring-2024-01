#include "company.h"
#include <fstream>
#include <iostream>
 

// Constructor
Company::Company(std::string name) : _name(name) {
    // Parameterized constructor
}

// Accessor method for the company name
std::string Company::getName() const {
    return _name;
}

// Methods to add an employee or customer to the company
void Company::addEmployee(const Employee& employee) {
    _employees.push_back(employee);
}

void Company::addCustomer(const Customer& customer) {
    _customers.push_back(customer);
}

// Methods to iterate over employees and customers
std::vector<Employee>::iterator Company::employeeBegin() {
    return _employees.begin();
}

std::vector<Employee>::iterator Company::employeeEnd() {
    return _employees.end();
}

std::vector<Customer>::iterator Company::customerBegin() {
    return _customers.begin();
}

std::vector<Customer>::iterator Company::customerEnd() {
    return _customers.end();
}
// Save and load methods
void Company::saveToFile() const {
    std::ofstream file(_name + ".dat");
    if (file.is_open()) {
        file << _employees.size() << "\n";
        for (const auto& employee : _employees) {
            employee.save(file);
        }

        file << _customers.size() << "\n";
        for (const auto& customer : _customers) {
            customer.save(file);
        }
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
    }
}

void Company::loadFromFile() {
    std::ifstream file(_name + ".dat");
    if (file.is_open()) {
        int numEmployees;
        file >> numEmployees;
        file.ignore(); // Ignore the newline character after reading the number of employees

        _employees.clear();
        for (int i = 0; i < numEmployees; ++i) {
            Employee employee;
            employee.load(file);
            _employees.push_back(employee);
        }

        int numCustomers;
        file >> numCustomers;
        file.ignore(); // Ignore the newline character after reading the number of customers

        _customers.clear();
        for (int i = 0; i < numCustomers; ++i) {
            Customer customer;
            customer.load(file);
            _customers.push_back(customer);
        }
    } else {
        std::cerr << "Error: Unable to open file for reading. Creating a new one.\n";
    }
}
