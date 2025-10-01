#include "bank_customer.h"
using namespace std;

int BankCustomer::getId() const {
    return id;
}

string BankCustomer::getName() const {
    return name;
}

double BankCustomer::getBalance() const {
    return balance;
}

void BankCustomer::printInfo() const {
    cout << "Customer ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
}

void BankCustomer::setName(const string& name) {
    this->name = name;
}

void BankCustomer::setBalance(double balance) {
    this->balance = balance;
}

void BankCustomer::addBalance(double amount) {
    balance += amount;
}

bool BankCustomer::withdrawBalance(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}
