#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <fstream>
#include "person.h"

class Employee : public Person {
private:
    double _salary;

public:
    // Constructors
    Employee();
    Employee(std::string name, std::string email, std::string phone, double salary);

public:
std::string readStringFromFile(std::ifstream& file);

    // Accessor method for salary
    double getSalary() const;

    // Mutator method for salary
    void setSalary(double salary);

    // Save and load methods
    void save(std::ofstream& file) const;
    void load(std::ifstream& file);
};

#endif // EMPLOYEE_H
