#include <iostream>
using namespace std;

#define SIZE 5  // size of circular queue

class CircularQueue {
    string queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    // Add passenger to queue
    void boardPassenger(string name) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Full! No more passengers can board.\n";
        }
        else {
            if (front == -1) front = 0;  // first passenger
            rear = (rear + 1) % SIZE;
            queue[rear] = name;
            cout << name << " boarded the bus.\n";
        }
    }

    // Remove passenger from queue
    void exitPassenger() {
        if (front == -1) {
            cout << "Queue Empty! No passenger to exit.\n";
        }
        else {
            cout << queue[front] << " exited the bus.\n";
            if (front == rear)    // last passenger exits
                front = rear = -1;
            else
                front = (front + 1) % SIZE;
        }
    }

    // Display current status
    void displayQueue() {
        if (front == -1) {
            cout << "No passengers in the queue.\n";
            return;
        }
        cout << "\nPassengers currently in queue: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue bus;
    int choice;
    string name;

    do {
        cout << "\n--- BUS TICKET COUNTER MENU ---\n";
        cout << "1. Passenger Board\n2. Passenger Exit\n3. Display Queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name;
                bus.boardPassenger(name);
                break;

            case 2:
                bus.exitPassenger();
                break;

            case 3:
                bus.displayQueue();
                break;

            case 4:
                cout << "End of Simulation.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 4);

    return 0;
}
