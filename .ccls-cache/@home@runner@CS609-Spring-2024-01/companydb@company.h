#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"
#include "customer.h"
#include <vector>

class Company {
private:
    std::vector<Employee> _employees;
    std::vector<Customer> _customers;
    std::string _name;

public:
    // Constructor
    Company(std::string name);

    // Accessor method for the company name
    std::string getName() const;

    // Methods to add an employee or customer to the company
    void addEmployee(const Employee& employee);
    void addCustomer(const Customer& customer);

    // Methods to iterate over employees and customers
    std::vector<Employee>::iterator employeeBegin();
    std::vector<Employee>::iterator employeeEnd();
    std::vector<Customer>::iterator customerBegin();
    std::vector<Customer>::iterator customerEnd();
    // Save and load methods
    void saveToFile() const;
    void loadFromFile();
};

#endif // COMPANY_H
