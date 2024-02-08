#include "company.h"

using namespace std;

Company::Company(string name)
{
    this->_name = name;
}

string Company::name() const
{
    return this->_name;
}

void Company::add_employee(Employee _employee)
{
    this->_employees.push_back(_employee);
}

void Company::add_customer(Customer _customer)
{
    this->_customers.push_back(_customer);
}

vector<Employee>::iterator Company::employee_begin()
{
    return this->_employees.begin();
}

vector<Employee>::iterator Company::employee_end()
{
    return this->_employees.end();
}

vector<Customer>::iterator Company::customer_begin()
{
    return this->_customers.begin();
}

vector<Customer>::iterator Company::customer_end()
{
    return this->_customers.end();
}

ofstream& operator<<(ofstream& os, Company& c)
{
    os << c.employee_end() - c.employee_begin() << endl;
    for(auto itr = c.employee_begin(); itr != c.employee_end(); itr++)
        os << *itr;

    os << c.customer_end() - c.customer_begin() << endl;
    for(auto itr = c.customer_begin(); itr < c.customer_end(); itr++)
        os << *itr;

    return os;
}
