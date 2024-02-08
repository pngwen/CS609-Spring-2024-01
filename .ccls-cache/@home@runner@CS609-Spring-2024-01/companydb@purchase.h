#ifndef PURCHASE_H
#define PURCHASE_H

#include <string>
#include <fstream>

class Purchase {
private:
    std::string _item;
    int _qty;
    double _cost;

public:
    // Constructors
    Purchase();
    Purchase(std::string item, int qty, double cost);

    // Accessor methods
    std::string getItem() const;
    int getQty() const;
    double getCost() const;

    double total() const;

    // Save and load methods
    void save(std::ofstream& file) const;
    void load(std::ifstream& file);
};

#endif // PURCHASE_H
