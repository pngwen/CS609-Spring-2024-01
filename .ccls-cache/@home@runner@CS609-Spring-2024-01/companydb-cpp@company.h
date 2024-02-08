#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "employee.h"
#include "customer.h"

using namespace std;

class Company{
public:
    Company(string name);

    virtual string name() const;
    virtual void add_employee(Employee _employee);
    virtual void add_customer(Customer _customer);
    virtual vector<Employee>::iterator employee_begin();
    virtual vector<Employee>::iterator employee_end();
    virtual vector<Customer>::iterator customer_begin();
    virtual vector<Customer>::iterator customer_end();


private:
    vector<Employee> _employees;
    vector<Customer> _customers;
    string _name;
};
ofstream& operator<<(ofstream& os, Company& c);
