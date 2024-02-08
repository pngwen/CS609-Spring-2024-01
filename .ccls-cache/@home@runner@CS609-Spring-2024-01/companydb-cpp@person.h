#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Person{
public:
    Person();
    Person(const string &_name, const string &_email, const string &_phone);

    virtual string name() const;
    virtual void name(const string &_name);
    virtual string email() const;
    virtual void email(const string &_email);
    virtual string phone() const;
    virtual void phone(const string &_phone);


private:
    string _name, _email, _phone;
};

istream& operator>>(istream& is, Person& p);
ostream& operator<<(ostream& os, const Person& p);
ofstream& operator<<(ofstream& os, const Person& p);
ifstream& operator>>(ifstream& is, Person& p);
#endif