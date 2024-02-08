#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "person.h"
#include "purchase.h"

using namespace std;

class Customer: public Person{
public:
    Customer();
    Customer(string _name, string _email, string _phone);

    virtual void add_purchase(Purchase purchase);
    virtual vector<Purchase>::const_iterator purchase_begin() const;
    virtual vector<Purchase>::const_iterator purchase_end() const;

private:
    vector<Purchase> _history;
};

istream& operator>>(istream& is, Customer& c);
ostream& operator<<(ostream& os, const Customer& c);
ofstream& operator<<(ofstream& os, const Customer& c);
ifstream& operator>>(ifstream& is, Customer& c);
#endif