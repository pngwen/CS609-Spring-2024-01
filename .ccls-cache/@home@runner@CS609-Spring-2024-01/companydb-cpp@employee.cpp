#include <string>
#include "employee.h"

using namespace std;

Employee::Employee()
{
    salary(0.0);
}

Employee::Employee(string _name, string _email, string _phone, double _salary)
    : Person(_name, _email, _phone)
{
    salary(_salary);
}

double Employee::salary() const
{
    return this->_salary;
}

void Employee::salary(double _salary)
{
    this->_salary = _salary;
}

ostream & operator << (ostream &os, const Employee& e)
{
    os << (const Person&)e << "\tSalary: $" << e.salary() << endl;
    return os;
}

ofstream& operator<<(ofstream& os, const Employee& e)
{
    os << (const Person&)e << e.salary() << endl;
    return os;
}

ifstream& operator>>(ifstream& is, Employee& e){
    string _salary;
    is >> (Person&) e;
    getline(is, _salary);
    e.salary(stod(_salary));
    return is;
}

istream& operator>>(istream& is, Employee& e){
    double salary;
    is >> (Person&)e;
    cout << "Salary: ";
    is >> salary;
    is.ignore();
    e.salary(salary);

    return is;
}
