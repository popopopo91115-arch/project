#include <iostream>
using namespace std;

int main() {
    int pin, choice, attempts = 0;
    double balance = 1000.0; // حساب واحد فقط برصيد افتراضي
    double amount;
    bool isAuthenticated = false;

    // التحقق من الرقم السري (PIN) - بحد أقصى 3 محاولات
    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> pin;

        if (pin == 1234) {
            isAuthenticated = true;
            break;
        } else {
            attempts++;
            cout << "Incorrect PIN! Attempts left: " << (3 - attempts) << endl;
        }
    }

    if (!isAuthenticated) {
        cout << "Account locked due to 3 incorrect attempts!" << endl;
        return 0;
    }

    do {
        cout << "\n--- ATM Menu (Single Account) ---" << endl;
        cout << "1. Withdraw" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > balance) {
                    cout << "Insufficient balance!" << endl;
                } else if (amount <= 0) {
                    cout << "Invalid amount!" << endl;
                } else {
                    balance -= amount;
                    cout << "Withdrawal successful. Current balance: " << balance << endl;
                }
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                if (amount <= 0) {
                    cout << "Invalid amount!" << endl;
                } else {
                    balance += amount;
                    cout << "Deposit successful. Current balance: " << balance << endl;
                }
                break;

            case 3:
                cout << "Your current balance: " << balance << endl;
                break;

            case 4:
                cout << "Thank you for using the ATM!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
