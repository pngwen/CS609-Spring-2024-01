#include "purchase.h"

// Constructor
Purchase::Purchase() : _qty(0), _cost(0.0) {
    // Default constructor
}

Purchase::Purchase(std::string item, int qty, double cost)
    : _item(item), _qty(qty), _cost(cost) {
    // Parameterized constructor
}

// Accessor methods
std::string Purchase::getItem() const {
    return _item;
}

int Purchase::getQty() const {
    return _qty;
}

double Purchase::getCost() const {
    return _cost;
}

// Calculation method
double Purchase::total() const {
    return _qty * _cost;
}
// Save and load methods
void Purchase::save(std::ofstream& file) const {
    file << _item << "\n" << _qty << "\n" << _cost << "\n";
}

void Purchase::load(std::ifstream& file) {
    std::getline(file, _item);
    file >> _qty >> _cost;
    file.ignore(); // Ignore the newline character after reading quantity and cost
}