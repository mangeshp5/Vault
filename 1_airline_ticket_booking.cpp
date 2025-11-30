#include <iostream>
#include <string>
using namespace std;

class Seat {
public:
    int row, col;
    string name;
};

int main() {
    int rows = 5, cols = 6;
    int n;

    cout << "How many seats you want to book? ";
    cin >> n;

    Seat booked[50];  // Only store booked seats (Sparse)

    for(int i = 0; i < n; i++) {
        cout << "\nEnter row, column and passenger name: ";
        cin >> booked[i].row >> booked[i].col >> booked[i].name;
    }

    cout << "\n--- Seat Layout ---\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            bool flag = false;

            // Check if seat is booked
            for(int k = 0; k < n; k++) {
                if(booked[k].row == i && booked[k].col == j)
                    flag = true;
            }

            if(flag) cout << "1 ";  // Booked
            else     cout << "0 ";  // Empty
        }
        cout << endl;
    }

    cout << "\n--- Booked Seats with Passenger Name ---\n";
    for(int i = 0; i < n; i++) {
        cout << "Seat (" << booked[i].row << "," << booked[i].col
             << ") -> " << booked[i].name << endl;
    }

    return 0;
}
