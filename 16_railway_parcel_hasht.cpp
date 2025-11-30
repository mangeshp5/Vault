#include <iostream>
#include <list>   // for chaining
using namespace std;

class ParcelSystem {
private:
    static const int SIZE = 10;     // hash table size
    list<int> table[SIZE];          // array of linked lists

public:
    // Hash Function
    int hashFunction(int trackingNo) {
        return trackingNo % SIZE;
    }

    // Insert Parcel
    void insertParcel(int trackingNo) {
        int index = hashFunction(trackingNo);
        table[index].push_back(trackingNo);
        cout << "Parcel Added at Slot " << index << endl;
    }

    // Search Parcel
    void searchParcel(int trackingNo) {
        int index = hashFunction(trackingNo);
        for(int x : table[index]) {
            if(x == trackingNo) {
                cout << "Parcel Found in Slot " << index << endl;
                return;
            }
        }
        cout << "Parcel NOT found!" << endl;
    }

    // Display All Parcels
    void display() {
        cout << "\n--- Railway Parcel Records ---\n";
        for(int i = 0; i < SIZE; i++) {
            cout << "Slot " << i << ": ";
            for(int x : table[i])
                cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    ParcelSystem ps;
    int choice, trackingNo;

    while(true) {
        cout << "\n1. Add Parcel\n2. Search Parcel\n3. Display All\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Tracking Number: ";
                cin >> trackingNo;
                ps.insertParcel(trackingNo);
                break;
            case 2:
                cout << "Enter Tracking Number to Search: ";
                cin >> trackingNo;
                ps.searchParcel(trackingNo);
                break;
            case 3:
                ps.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!";
        }
    }
}
