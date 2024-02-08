#include "company.h"
#include "employee.h"
#include "customer.h"
#include "purchase.h"
#include "person.h"
#include <iostream>

int main() {
  
    // Prompt for the name of the company
    std::string companyName;
    std::cout << "Enter the name of the company: ";
    std::cin >> companyName;
  
    // Create a company and load data from file
    Company company(companyName);
    company.loadFromFile();
    
    // Iterating over employees
    std::cout << "Employees:\n";
    for (auto it = company.employeeBegin(); it != company.employeeEnd(); ++it) {
        std::cout << "Name: " << it->getName() << ", Salary: " << it->getSalary() << "\n";
    }

    // Iterating over customers and their purchases
    std::cout << "\nCustomers and their purchases:\n";
    for (auto it = company.customerBegin(); it != company.customerEnd(); ++it) {
        std::cout << "Name: " << it->getName() << ", Email: " << it->getEmail() << "\n";
        for (auto purchaseIt = it->purchaseBegin(); purchaseIt != it->purchaseEnd(); ++purchaseIt) {
            std::cout << "  Item: " << purchaseIt->getItem() << ", Quantity: " << purchaseIt->getQty()
                      << ", Cost: " << purchaseIt->getCost() << ", Total: " << purchaseIt->total() << "\n";
        }
    }

    return 0;
}
