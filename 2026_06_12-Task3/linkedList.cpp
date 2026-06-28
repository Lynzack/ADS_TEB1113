#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next = nullptr;
};


void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name<<endl;
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void insertAtEnd(Node*& head, string newName) {
    Node* newNode = new Node();
    newNode->name = newName;
    newNode->next = nullptr;

   
    if (head == nullptr) {
        head = newNode;
        return;
    }


    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    

    temp->next = newNode;
}


void deleteNode(Node*& head, string targetName) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // Case 1: The node to be deleted is the head node
    if (head->name == targetName) {
        Node* temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Free memory
        cout << "Deleted " << targetName << " from the list.\n";
        return;
    }

    // Case 2: The node is somewhere else in the list
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->name != targetName) {
        prev = current;
        current = current->next;
    }

    // If the name wasn't found in the list
    if (current == nullptr) {
        cout << "Name \"" << targetName << "\" not found in the list.\n";
        return;
    }

    // Unlink the node from the linked list and free memory
    prev->next = current->next;
    delete current;
    cout << "Deleted " << targetName << " from the list.\n";
}

int main() {
    Node* head = nullptr; 

   
    cout << "--- Inserting Nodes ---" << endl;
    insertAtEnd(head, "Liyana");
    insertAtEnd(head, "Ahmad");
    insertAtEnd(head, "Sarah");
    insertAtEnd(head, "Omar");
    
  
    displayList(head); 
    cout << endl;

 
    cout << "--- Deleting 'Sarah' (Middle Node) ---" << endl;
    deleteNode(head, "Sarah");
    displayList(head);
    cout << endl;

    cout << "--- Deleting 'Liyana' (Head Node) ---" << endl;
    deleteNode(head, "Liyana");
    displayList(head);
    cout << endl;
    
    cout << "--- Trying to delete a non-existent node ---" << endl;
    deleteNode(head, "John");

    return 0;
}