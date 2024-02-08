#include <iomanip>
#include "customer.h"

using namespace std;

Customer::Customer(){}
Customer::Customer(string _name, string _email, string _phone)
    : Person(_name, _email, _phone){}

vector<Purchase>::const_iterator Customer::purchase_begin() const
{
    return this->_history.begin();
}

vector<Purchase>::const_iterator Customer::purchase_end() const
{
    return this->_history.end();
}

void Customer::add_purchase(Purchase purchase)
{
    this->_history.push_back(purchase);
}

istream& operator>>(istream& is, Customer& c){
    is >> (Person&)c;
    return is;
}

ostream & operator << (ostream &os, const Customer& c){
    os << (const Person&)c;
    cout << endl << "Order History" << endl << setw(20) << "Item" << setw(12) << "Price" << setw(12) << "Quantity" << setw(12) << "Total\n";

    for(auto itr = c.purchase_begin(); itr < c.purchase_end(); itr++)
        os << *itr << endl;
    return os;
}

ofstream& operator<<(ofstream& os, const Customer& c){
    os << (const Person&)c;
    os << c.purchase_end() - c.purchase_begin() << endl;
    for(auto itr = c.purchase_begin(); itr < c.purchase_end(); itr++)
        os << *itr;
    return os;
}

ifstream& operator>>(ifstream& is, Customer& c){
    is >> (Person&)c;
    return is;
}
