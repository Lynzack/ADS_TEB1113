#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next = nullptr;
    Node* prev = nullptr;
};

// 1. DISPLAY: Traverse the circular list until we loop back to the head
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Node* temp = head;
    cout << "Circular List: "<<endl;
    do {
        cout << temp->name << endl;
        temp = temp->next;
    } while (temp != head); // Stop when we circle back to the start
    
    cout << "(back to " << head->name << ")\n";
}

// 2. INSERTION: Insert at the end of the circular list
void insertAtEnd(Node*& head, string newName) {
    Node* newNode = new Node();
    newNode->name = newName;

    // Case 1: If the list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head; // Points to itself
        newNode->prev = head; // Points to itself
        return;
    }

    // Case 2: List has elements. The last node is head->prev
    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head; 
    head->prev = newNode; 
}

// 3. DELETION: Delete a specific node from the circular list
void deleteNode(Node*& head, string targetName) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    Node* current = head;
    
    // Search for the node
    while (current->name != targetName) {
        current = current->next;
        // If we looped all the way back to head, the name isn't here
        if (current == head) {
            cout << "Name \"" << targetName << "\" not found.\n";
            return;
        }
    }

  
    if (current->next == current) {
        head = nullptr;
    }
   
    else {
        if (current == head) {
            head = head->next; // Shift head to the next node
        }
        // Unlink current by bridging its neighbors
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
    cout << "Deleted \"" << targetName << "\" from the circular list.\n";
}

int main() {
    Node* head = nullptr;

    // --- Test Insertion ---
    cout << "--- Inserting Nodes ---\n";
    insertAtEnd(head, "Amar");
    insertAtEnd(head, "Akbar");
    insertAtEnd(head, "Anthony");
    insertAtEnd(head, "Amit");
    displayList(head);
    cout << endl;

    // --- Test Deleting a Middle Node ---
    deleteNode(head, "Anthony");
    displayList(head);
    cout << endl;

    // --- Test Deleting the Head Node ---
    deleteNode(head, "Amar");
    displayList(head);
    cout << endl;

    return 0;
}