#include <iostream>
#include <string>
#include <vector>
#include "bank_customer.h"
#include "buyer.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};
enum LoginPrompt{CHECK_STATUS, UPGRADE_SELLER, CREATE_BANK, LOGOUT};

using namespace std;

struct Account {
    string username;
    string password;
    string role; 
};

vector<Account> accounts;

int main() {
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    LoginPrompt loginPrompt = CHECK_STATUS;

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);

        switch (prompt) {
            case LOGIN: {
                cout << "Login selected." << endl;
                string user, pass;
                cout << "Enter username: ";
                cin >> user;
                cout << "Enter password: ";
                cin >> pass;

                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.username == user && acc.password == pass) {
                        cout << "Login successful! Welcome, " 
                             << acc.username << " (" << acc.role << ")\n";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Login failed. Please register first.\n";
                    break;
                }

                loginPrompt = CHECK_STATUS;
                while (loginPrompt != LOGOUT) {
                    cout << "=== Login Menu ===" << endl;
                    cout << "1. Check Account Status" << endl;
                    cout << "2. Upgrade Account to Seller" << endl;
                    cout << "3. Create Bank Account" << endl;
                    cout << "4. Logout (Back to Main Menu)" << endl;
                    int loginChoice;
                    cin >> loginChoice;
                    loginPrompt = static_cast<LoginPrompt>(loginChoice - 1);

                    switch (loginPrompt) {
                        case CHECK_STATUS:
                            cout << "Check Account Status selected." << endl;
                            break;
                        case UPGRADE_SELLER:
                            cout << "Upgrade to Seller selected." << endl;
                            break;
                        case CREATE_BANK:
                            cout << "Create Bank Account selected." << endl;
                            break;
                        case LOGOUT:
                            cout << "Logging out to main menu." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }
                break;
            }

            case REGISTER: {
                regPrompt = CREATE_BUYER; 
                while (regPrompt != BACK){
                    cout << "Register selected. " << endl;
                    cout << "Select an option: " << endl;
                    cout << "1. Create Buyer Account" << endl;
                    cout << "2. Create Seller Account" << endl;
                    cout << "3. Back" << endl;
                    int regChoice;
                    cin >> regChoice;
                    regPrompt = static_cast<RegisterPrompt>(regChoice - 1);

                    switch (regPrompt) {
                        case CREATE_BUYER: {
                            cout << "Create Buyer Account selected." << endl;
                            string user, pass;
                            cout << "Enter username: ";
                            cin >> user;
                            cout << "Enter password: ";
                            cin >> pass;
                            accounts.push_back({user, pass, "Buyer"});
                            cout << "Buyer account created successfully!\n";
                            break;
                        }
                        case CREATE_SELLER: {
                            cout << "Create Seller Account selected." << endl;
                            string user, pass;
                            cout << "Enter username: ";
                            cin >> user;
                            cout << "Enter password: ";
                            cin >> pass;
                            accounts.push_back({user, pass, "Seller"});
                            cout << "Seller account created successfully!\n";
                            break;
                        }
                        case BACK:
                            cout << "Back selected." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }
                break;
            }

            case EXIT:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }
    return 1;
}
