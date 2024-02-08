#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string _name;
    std::string _email;
    std::string _phone;

public:
    // Constructors
    Person();
    Person(std::string name, std::string email, std::string phone);

    // Accessor methods
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;

    // Mutator methods
    void setName(std::string name);
    void setEmail(std::string email);
    void setPhone(std::string phone);
};

#endif // PERSON_H
