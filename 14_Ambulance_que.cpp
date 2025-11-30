#include <iostream>
#include <queue>
using namespace std;

class Case {
public:
    string name;
    int priority;

    Case(string n, int p) {
        name = n;
        priority = p;
    }
};
struct Compare {
    bool operator()(Case const& c1, Case const& c2) {
        return c1.priority < c2.priority;  
    }
};
int main() {
    priority_queue<Case, vector<Case>, Compare> pq;

    int choice;
    do {
        cout << "\n--- Ambulance Dispatch System ---\n";
        cout << "1. Add Emergency Case\n";
        cout << "2. Dispatch Next Ambulance\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            string name;
            int p;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter priority (1-10): ";
            cin >> p;
            pq.push(Case(name,p));
            cout << "Case added.\n";
        }

        else if(choice == 2) {
            if(pq.empty()) {
                cout << "No emergency cases waiting!\n";
            } else {
                Case top = pq.top();
                pq.pop();
                cout << "\n Ambulance dispatched for: " << top.name;
                cout << " (Priority = " << top.priority << ")\n";
            }
        }

    } while(choice != 3);

    return 0;
}
