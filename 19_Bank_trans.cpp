#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Structure to store each transaction
struct Transaction {
    string type;
    int amount;
};

int main() {
    queue<Transaction> q;
    int n;
    int balance = 0;

    cout << "Enter number of transactions: ";
    cin >> n;

    // Taking user input for transactions
    for (int i = 0; i < n; i++) {
        Transaction t;
        cout << "\nEnter transaction type (Deposit/Withdraw): ";
        cin >> t.type;

        cout << "Enter amount: ";
        cin >> t.amount;

        q.push(t); // Add transaction to queue
    }

    cout << "\nProcessing Transactions...\n";

    // Processing transactions in FIFO order
    while (!q.empty()) {
        Transaction t = q.front();
        q.pop();

        if (t.type == "Deposit" || t.type == "deposit") {
            balance += t.amount;
            cout << "Processed: Deposit " << t.amount 
                 << " | Balance = " << balance << endl;
        }
        else if (t.type == "Withdraw" || t.type == "withdraw") {
            balance -= t.amount;
            cout << "Processed: Withdraw " << t.amount
                 << " | Balance = " << balance << endl;
        }
        else {
            cout << "Invalid transaction type! Skipped.\n";
        }
    }

    cout << "\nFinal Balance = " << balance << endl;
    return 0;
}
