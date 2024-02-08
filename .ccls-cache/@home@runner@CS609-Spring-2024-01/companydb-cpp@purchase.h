#ifndef PURCHASE_H
#define PURCHASE_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Purchase{
public:
    Purchase();
    Purchase(string _item, int _qty, double _cost);

    virtual string item() const;
    virtual int qty() const;
    virtual double cost() const;
    virtual double total() const;

private:
    string _item;
    int _qty;
    double _cost;
};

istream& operator>>(istream& is, Purchase& p);
ostream& operator<<(ostream& os, const Purchase& p);
ofstream& operator<<(ofstream& os, const Purchase& p);
ifstream& operator>>(ifstream& is, Purchase& p);
#endif