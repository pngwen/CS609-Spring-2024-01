#include "person.h"

// Constructors
Person::Person() {
    // Default constructor
}

Person::Person(std::string name, std::string email, std::string phone) 
    : _name(name), _email(email), _phone(phone) {
    // Parameterized constructor
}

// Accessor methods
std::string Person::getName() const {
    return _name;
}

std::string Person::getEmail() const {
    return _email;
}

std::string Person::getPhone() const {
    return _phone;
}

// Mutator methods
void Person::setName(std::string name) {
    _name = name;
}

void Person::setEmail(std::string email) {
    _email = email;
}

void Person::setPhone(std::string phone) {
    _phone = phone;
}
