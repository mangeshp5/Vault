#include <iostream>
#include <string>
using namespace std;

// Node class for BST
class Patient {
public:
    int id;
    string name;
    Patient* left;
    Patient* right;

    Patient(int patientID, string patientName) {
        id = patientID;
        name = patientName;
        left = right = nullptr;
    }
};

// BST class
class Hospital {
private:
    Patient* root;

    // Helper function to insert node
    Patient* insert(Patient* node, int id, string name) {
        if(node == nullptr) {
            return new Patient(id, name);
        }
        if(id < node->id)
            node->left = insert(node->left, id, name);
        else if(id > node->id)
            node->right = insert(node->right, id, name);
        else
            cout << "Patient ID already exists!\n";
        return node;
    }

    // Helper function to search node
    Patient* search(Patient* node, int id) {
        if(node == nullptr || node->id == id)
            return node;
        if(id < node->id)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    // Helper to find minimum node in right subtree
    Patient* minValueNode(Patient* node) {
        Patient* current = node;
        while(current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Helper to delete node
    Patient* deleteNode(Patient* node, int id) {
        if(node == nullptr) return node;

        if(id < node->id)
            node->left = deleteNode(node->left, id);
        else if(id > node->id)
            node->right = deleteNode(node->right, id);
        else {
            // Node with only one child or no child
            if(node->left == nullptr) {
                Patient* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr) {
                Patient* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Patient* temp = minValueNode(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->right = deleteNode(node->right, temp->id);
        }
        return node;
    }

    // In-order traversal
    void inorder(Patient* node) {
        if(node == nullptr) return;
        inorder(node->left);
        cout << "ID: " << node->id << " | Name: " << node->name << endl;
        inorder(node->right);
    }

public:
    Hospital() {
        root = nullptr;
    }

    void insertPatient(int id, string name) {
        root = insert(root, id, name);
        cout << "Patient added successfully.\n";
    }

    void deletePatient(int id) {
        root = deleteNode(root, id);
        cout << "Patient record deleted if exists.\n";
    }

    void searchPatient(int id) {
        Patient* result = search(root, id);
        if(result)
            cout << "Patient Found: ID = " << result->id << ", Name = " << result->name << endl;
        else
            cout << "Patient with ID " << id << " not found.\n";
    }

    void displayPatients() {
        if(root == nullptr) {
            cout << "No patient records.\n";
            return;
        }
        cout << "--- Patient Records (Sorted by ID) ---\n";
        inorder(root);
    }
};

// ================= Main Function =================
int main() {
    Hospital hospital;
    int choice, id;
    string name;

    do {
        cout << "\n--- Hospital Patient Record Menu ---\n";
        cout << "1. Insert Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Patient Name: ";
                getline(cin, name);
                hospital.insertPatient(id, name);
                break;

            case 2:
                cout << "Enter Patient ID to delete: ";
                cin >> id;
                hospital.deletePatient(id);
                break;

            case 3:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                hospital.searchPatient(id);
                break;

            case 4:
                hospital.displayPatients();
                break;

            case 5:
                cout << "Exiting system.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 5);

    return 0;
}
