#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    BankAccount(string n, double b) {
        cout << "Constructor called for " << n << endl;

        if (b < 0) {
            cout << "Error: Negative balance not allowed!" << endl;
            throw b;
        }

        name = n;
        balance = b;
        cout << "Account created successfully!" << endl;
        cout << "Name: " << name << ", Balance: Rs. " << balance << endl;
    }

    ~BankAccount() {
        cout << "Destructor called for " << name << endl;
        cout << "Final balance was: Rs. " << balance << endl;
    }

    void withdraw(double amount) {
        cout << "\nTrying to withdraw Rs. " << amount << endl;

        if (amount > balance) {
            cout << "Error: Not enough money!" << endl;
            throw amount;
        }

        balance = balance - amount;
        cout << "Withdrawal successful!" << endl;
        cout << "New balance: Rs. " << balance << endl;
    }

    void deposit(double amount) {
        balance = balance + amount;
        cout << "Deposited Rs. " << amount << endl;
        cout << "New balance: Rs. " << balance << endl;
    }

    void show() {
        cout << "\nAccount holder: " << name << endl;
        cout << "Current balance: Rs. " << balance << endl;
    }
};

int main() {
    cout << "=== Test 1: Creating account with negative balance ===" << endl;

    BankAccount* account1 = nullptr;

    try {
        account1 = new BankAccount("Ahmed Khan", -500);
    }
    catch (double e) {
        cout << "Caught exception! Invalid balance: Rs. " << e << endl;
    }

    cout << "\n=== Test 2: Creating valid account ===" << endl;

    BankAccount* account2 = nullptr;

    try {
        account2 = new BankAccount("Fatima Ali", 50000);
        account2->show();

        account2->withdraw(15000);
        account2->show();

        account2->withdraw(45000);
    }
    catch (double e) {
        cout << "Caught exception! Tried to withdraw: Rs. " << e << endl;
    }

    if (account2 != nullptr) {
        cout << "\nCleaning up account2..." << endl;
        delete account2;
    }

    cout << "\n=== Test 3: Multiple operations ===" << endl;

    BankAccount* account3 = nullptr;

    try {
        account3 = new BankAccount("Hassan Raza", 25000);
        account3->deposit(10000);
        account3->withdraw(5000);
        account3->withdraw(35000);
    }
    catch (double e) {
        cout << "Caught exception! Invalid amount: Rs. " << e << endl;
    }

    if (account3 != nullptr) {
        cout << "\nCleaning up account3..." << endl;
        delete account3;
    }

    cout << "\nProgram finished successfully!" << endl;

    return 0;
}