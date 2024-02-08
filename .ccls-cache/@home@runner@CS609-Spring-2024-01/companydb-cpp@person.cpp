#include "person.h"

using namespace std;

Person::Person(){}
Person::Person(const string &_name, const string &_email, const string &_phone){
    name(_name);
    email(_email);
    phone(_phone);
}

string Person::name() const{
    return this->_name;
}

void Person::name(const string &_name){
    this->_name = _name;
}

string Person::email() const{
    return this->_email;
}

void Person::email(const string &_email){
    this->_email = _email;
}

string Person::phone() const{
    return this->_phone;
}

void Person::phone(const string &_phone){
    this->_phone = _phone;
}

istream& operator>>(istream& is, Person& p){
    string _name, _email, _phone;

    cout << "Name: ";
    getline(is, _name);
    cout << "Email: ";
    getline(is, _email);
    cout << "Phone: ";
    getline(is, _phone);

    p.name(_name);
    p.email(_email);
    p.phone(_phone);

    return is;
}

ostream & operator << (ostream &os, const Person& p){
    os << p.name() << "\t<" << p.email() << ">\tPhone: " << p.phone();
    return os;
}

ofstream& operator<<(ofstream& os, const Person& p){
    os << p.name() << endl << p.email() << endl << p.phone() << endl;
    return os;
}

ifstream& operator>>(ifstream& is, Person& p){
    string _name, _email, _phone;

    getline(is, _name);
    p.name(_name);
    getline(is, _email);
    p.email(_email);
    getline(is, _phone);
    p.phone(_phone);

    return is;
}