// Varun pendem
// PRN: 23070123149
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;        // Data of the node
    Node* next;      // Pointer to the next node
};

// LinkedList class
class LinkedList {
    Node* head;      // Pointer to the head (first node) of the list

public:
    // Constructor to initialize the head to NULL (empty list)
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the list
    void insert(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;       // Assign value to the new node
        newNode->next = NULL;        // New node will point to NULL as it's the last node

        if (head == NULL) {
            head = newNode;          // If list is empty, new node becomes the head
        } else {
            Node* temp = head;       // Temporary pointer to traverse the list
            while (temp->next != NULL) {
                temp = temp->next;   // Move to the last node
            }
            temp->next = newNode;    // Point the last node to the new node
        }
    }

    // Function to delete a node with a specific value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        // If the node to be deleted is the head
        if (head->data == value) {
            Node* temp = head;       // Temporary pointer to store the current head
            head = head->next;       // Move the head pointer to the next node
            delete temp;             // Delete the old head
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }

        // Deleting node in the middle or end
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;       // Traverse the list to find the node
        }

        if (temp->next == NULL) {
            cout << "Node with value " << value << " not found." << endl;
        } else {
            Node* deleteNode = temp->next;  // Store the node to be deleted
            temp->next = temp->next->next;  // Unlink the node from the list
            delete deleteNode;              // Delete the node
            cout << "Node with value " << value << " deleted." << endl;
        }
    }

    // Function to display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (1) {
        // Display menu options
        cout << "\nMenu Options:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
