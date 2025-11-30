#include <iostream>
#include <string>
using namespace std;

// Node class for doubly linked list
class Song {
public:
    string name;
    Song* prev;
    Song* next;

    // Constructor
    Song(string songName) {
        name = songName;
        prev = nullptr;
        next = nullptr;
    }
};

// Playlist class
class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current; // pointer to currently playing song

public:
    Playlist() {
        head = tail = current = nullptr;
    }

    // Add song at the end
    void addSong(string name) {
        Song* newSong = new Song(name);

        if(head == nullptr) {
            head = tail = current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << name << " added to playlist.\n";
    }

    // Delete a song by name
    void deleteSong(string name) {
        Song* temp = head;
        while(temp != nullptr) {
            if(temp->name == name) {
                if(temp->prev != nullptr)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if(temp->next != nullptr)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                if(current == temp)
                    current = temp->next ? temp->next : temp->prev;

                delete temp;
                cout << name << " deleted from playlist.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song not found!\n";
    }

    // Play next song
    void nextSong() {
        if(current == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        if(current->next != nullptr) {
            current = current->next;
            cout << "Playing: " << current->name << endl;
        } else {
            cout << "Already at the last song!\n";
        }
    }

    // Play previous song
    void prevSong() {
        if(current == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        if(current->prev != nullptr) {
            current = current->prev;
            cout << "Playing: " << current->name << endl;
        } else {
            cout << "Already at the first song!\n";
        }
    }

    // Show playlist
    void display() {
        if(head == nullptr) {
            cout << "Playlist is empty!\n";
            return;
        }
        Song* temp = head;
        cout << "Playlist: ";
        while(temp != nullptr) {
            if(temp == current)
                cout << "[" << temp->name << "] "; // indicate current song
            else
                cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ================= Main Function =================
int main() {
    Playlist playlist;
    int choice;
    string name;

    do {
        cout << "\n--- Music Playlist Menu ---\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Play Next Song\n";
        cout << "4. Play Previous Song\n";
        cout << "5. Display Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter song name to add: ";
                cin.ignore();
                getline(cin, name);
                playlist.addSong(name);
                break;

            case 2:
                cout << "Enter song name to delete: ";
                cin.ignore();
                getline(cin, name);
                playlist.deleteSong(name);
                break;

            case 3:
                playlist.nextSong();
                break;

            case 4:
                playlist.prevSong();
                break;

            case 5:
                playlist.display();
                break;

            case 6:
                cout << "Exiting playlist simulation.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 6);

    return 0;
}
