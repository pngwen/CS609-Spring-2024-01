#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <fstream>
#include "person.h"

using namespace std;

class Employee: public Person
{
public:
    Employee();
    Employee(string _name, string _email, string _phone, double _salary);

    virtual double salary() const;
    virtual void salary(double _salary);

private:
    double _salary;
};

istream& operator>>(istream& is, Employee& e);
ostream& operator<<(ostream& os, const Employee& e);
ofstream& operator<<(ofstream& os, const Employee& e) ;
ifstream& operator>>(ifstream& is, Employee& e);
#endif