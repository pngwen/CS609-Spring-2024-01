#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"
#include "purchase.h"
#include <vector>

class Customer : public Person {
private:
    std::vector<Purchase> _history;

public:
    // Constructors
    Customer();
    Customer(std::string name, std::string email, std::string phone);

public:
std::string readStringFromFile(std::ifstream& file);

    // Method to add a purchase to the customer's history
    void addPurchase(const Purchase& purchase);

    // Methods to iterate over purchase history
    std::vector<Purchase>::const_iterator purchaseBegin() const;
    std::vector<Purchase>::const_iterator purchaseEnd() const;
public:
// Save and load methods
void save(std::ofstream& file) const;
void load(std::ifstream& file);
};

#endif // CUSTOMER_H
