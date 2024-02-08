#include "customer.h"


// Constructors
Customer::Customer() {
    // Default constructor
}

Customer::Customer(std::string name, std::string email, std::string phone)
    : Person(name, email, phone) {
    // Parameterized constructor
}

// Method to add a purchase to the customer's history
void Customer::addPurchase(const Purchase& purchase) {
    _history.push_back(purchase);
}

// Methods to iterate over purchase history
std::vector<Purchase>::const_iterator Customer::purchaseBegin() const {
    return _history.begin();
}

std::vector<Purchase>::const_iterator Customer::purchaseEnd() const {
    return _history.end();
}
// Save and load methods
void Customer::save(std::ofstream& file) const {
    file << getName() << "\n" << getEmail() << "\n" << getPhone() << "\n" << _history.size() << "\n";
    for (const auto& purchase : _history) {
        purchase.save(file);
    }
}
std::string Customer::readStringFromFile(std::ifstream& file) {
    std::string value;
    std::getline(file, value);
    return value;
}

// Load method in Customer.cpp
void Customer::load(std::ifstream& file) {
    setName(readStringFromFile(file));
    setEmail(readStringFromFile(file));
    setPhone(readStringFromFile(file));

    int numPurchases;
    file >> numPurchases;
    file.ignore(); // Ignore the newline character after reading the number of purchases

    _history.clear();
    for (int i = 0; i < numPurchases; ++i) {
        Purchase purchase;
        purchase.load(file);
        _history.push_back(purchase);
    }
}


