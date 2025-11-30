#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> backStack, forwardStack;
    string currentPage = "Home";  // browser opens at Home

    int choice;
    do {
        cout << "\n--- Browser History Menu ---\n";
        cout << "1. Open New Page\n";
        cout << "2. Back\n";
        cout << "3. Forward\n";
        cout << "4. Show Current Page\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter page URL: ";
            string url;
            cin >> url;
            
            backStack.push(currentPage);    // save current page
            currentPage = url;              // move to new page
            while(!forwardStack.empty())    // clear forward stack
                forwardStack.pop();

            cout << "Opened: " << currentPage << endl;
        }

        else if(choice == 2) {
            if(backStack.empty())
                cout << "No history to go back!\n";
            else {
                forwardStack.push(currentPage);
                currentPage = backStack.top();
                backStack.pop();
                cout << "Moved Back to: " << currentPage << endl;
            }
        }

        else if(choice == 3) {
            if(forwardStack.empty())
                cout << "No forward pages!\n";
            else {
                backStack.push(currentPage);
                currentPage = forwardStack.top();
                forwardStack.pop();
                cout << "Moved Forward to: " << currentPage << endl;
            }
        }

        else if(choice == 4) {
            cout << "Current Page: " << currentPage << endl;
        }

    } while(choice != 5);

    return 0;
}
