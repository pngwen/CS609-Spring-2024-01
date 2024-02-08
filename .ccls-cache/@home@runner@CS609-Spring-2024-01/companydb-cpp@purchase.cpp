#include <iomanip>
#include <cmath>
#include "purchase.h"

using namespace std;

Purchase::Purchase(string _item, int _qty, double _cost) { 
    this->_item= _item; 
    this->_qty = _qty;
    this->_cost = _cost; 
}

string Purchase::item() const
{
    return this->_item;
}

int Purchase::qty() const
{
    return this->_qty;
}

double Purchase::cost() const
{
    return this->_cost;
}

double Purchase::total() const
{
    return this->_qty * this->_cost;
}

ostream & operator << (ostream &os, const Purchase& p)
{
    cout << fixed << setprecision(2);

    os << setw(20) << p.item() << setw(12) << round(p.cost() * 100.00) / 100.00 << setw(12) << p.qty() << setw(12) << round(p.total() * 100.00) / 100.00;
    return os;
}

ofstream& operator<<(ofstream& os, const Purchase& p){
    os << p.item() << endl << p.qty() << endl << p.cost() << endl;
    return os;
}

istream& operator>>(istream& is, Purchase& p){
    string item;
    string quantity;
    string cost;

    cout << "Item: ";
    getline(is, item);
    cout << "Quantity: ";
    getline(is, quantity);
    cout << "Cost: ";
    getline(is, cost);

    Purchase pur(item, stoi(quantity), stod(cost));
    p = pur;

    return is;
}

ifstream& operator>>(ifstream& is, Purchase& p){
    string item;
    string quantity;
    string cost;

    getline(is, item);
    getline(is, quantity);
    getline(is, cost);

    Purchase pur(item, stoi(quantity), stod(cost));
    p = pur;

    return is;
}