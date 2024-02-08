#include "employee.h"

// Constructors
Employee::Employee() : _salary(0.0) {
    // Default constructor
}

Employee::Employee(std::string name, std::string email, std::string phone, double salary)
    : Person(name, email, phone), _salary(salary) {
    // Parameterized constructor
}

// Accessor method for salary
double Employee::getSalary() const {
    return _salary;
}

// Mutator method for salary
void Employee::setSalary(double salary) {
    _salary = salary;
}

// Save and load methods
void Employee::save(std::ofstream& file) const {
    file << getName() << "\n" << getEmail() << "\n" << getPhone() << "\n" << _salary << "\n";
}

void Employee::load(std::ifstream& file) {
    setName(readStringFromFile(file));
    setEmail(readStringFromFile(file));
    setPhone(readStringFromFile(file));
    file >> _salary;
    file.ignore(); // Ignore the newline character after reading the salary
}
void readStringFromFile(std::ifstream& file, std::string& std){
    getline(file, std);
}