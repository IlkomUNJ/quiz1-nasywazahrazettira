#pragma once
#include "buyer.h"
#include "item.h"
#include <string>
#include <vector>
#include <iostream>

class Seller : public Buyer {  
private:
    int sellerId;
    std::string sellerName;

    bool idDisplayed(int itemId) const { 
        return itemId > 0; 
    }

    vector<Item> items;

public:
    Seller() = default;

    Seller(Buyer buyer, int sellerId, const std::string& sellerName)
        : Buyer(buyer.getId(), buyer.getName(), buyer.getAccount()), 
          sellerId(sellerId), sellerName(sellerName) {
        Buyer::setId(buyer.getId());
    }

    virtual ~Seller() = default;

    void addNewItem(int newId, const std::string& newName, int newQuantity, double newPrice) {
        Item newItem(newId, newName, newQuantity, newPrice);
        items.push_back(newItem);
    }

    void updateItem(int itemId, const std::string& newName, int newQuantity, double newPrice) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.alterItemById(itemId, newName, newQuantity, newPrice);
            }
        }
    }

    void makeItemVisibleToCustomer(int itemId) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.setDisplay(true);
                break;
            }
        }
    }
    
    void printInventory() const {
        std::cout << "=== Inventory of " << sellerName << " ===\n";
        for (const auto& item : items) {
            std::cout << "ID: " << item.getId()
                      << " | Name: " << item.getName()
                      << " | Qty: " << item.getQuantity()
                      << " | Price: " << item.getPrice()
                      << std::endl;
        }
    }
};
