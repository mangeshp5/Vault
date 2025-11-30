#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> bookStack;
    int choice;
    string book;

    while(true) {
        cout << "\n--- Book Return Bin ---\n";
        cout << "1. Return Book (Push)\n";
        cout << "2. Process Returned Book (Pop)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter book name: ";
                cin >> book;
                bookStack.push(book);
                cout << "Book returned to bin!\n";
                break;
            
            case 2:
                if(bookStack.empty()) {
                    cout << "No books to process!\n";
                } else {
                    cout << "Processing: " << bookStack.top() << endl;
                    bookStack.pop();
                }
                break;

            case 3:
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
