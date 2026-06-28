#include <iostream>

using namespace std;
struct Node {
    string name;
    Node* next = NULL;
    Node* prev = NULL;

};

// 1. DISPLAY FORWARD
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward: "<<endl;
    while (temp != nullptr) {
        cout << temp->name<<endl;
        temp = temp->next;
    }
    cout << "NULL\n";
}

// 2. DISPLAY BACKWARD
void displayBackward(Node* tail) {
    Node* temp = tail;
    cout << "Backward: "<<endl;
    while (temp != nullptr) {
        cout << temp->name<<endl;
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// 3. INSERTION: Insert at the end of the list
void insertAtEnd(Node*& head, Node*& tail, string newName) {
    Node* newNode = new Node();
    newNode->name = newName;

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Link the current tail to the new node
    tail->next = newNode;
    newNode->prev = tail;
    
    // Move the tail pointer to the new node
    tail = newNode;
}

// 4. DELETION: Delete the first node that matches targetName
void deleteNode(Node*& head, Node*& tail, string targetName) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    Node* current = head;

    // Search for the node to delete
    while (current != nullptr && current->name != targetName) {
        current = current->next;
    }

    // Node not found
    if (current == nullptr) {
        cout << "Name \"" << targetName << "\" not found.\n";
        return;
    }

    // Case 1: head node
    if (current == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr; // List became empty
        }
    }
    // Case 2: tail node
    else if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    // Case 3: middle node
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current; // Free the memory
    cout << "Deleted \"" << targetName << "\" from the list.\n";
}


int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // --- Test Insertion ---
    insertAtEnd(head, tail, "Amar");
    insertAtEnd(head, tail, "Akbar");
    insertAtEnd(head, tail, "Anthony");
    insertAtEnd(head, tail, "Amit");

    cout << "--- Initial List ---\n";
    displayForward(head);
    displayBackward(tail);
    cout << endl;

    // --- Test Deleting a Middle Node ---
    deleteNode(head, tail, "Anthony");
    displayForward(head);
    cout << endl;

    // --- Test Deleting the Head Node ---
    deleteNode(head, tail, "Amar");
    displayForward(head);
    displayBackward(tail);
    cout << endl;

    return 0;

    // Node* node1 = new Node();
    // Node* node2 = new Node();
    // Node* node3 = new Node();
    // Node* node4 = new Node();

    // node1 -> name = "Amar";
    // node1 -> next = node2;
    // node1 -> prev = NULL;

    // node2 -> name = "Akbar";
    // node2 -> next = node3;
    // node2 -> prev = node1;

    // node3 -> name = "Anthony";
    // node3 -> next = node4;
    // node3 -> prev = node2;

    // node4 -> name = "Amit";
    // node4 -> next = NULL;
    // node4 -> prev = node3;

    // //FORWARD DIRECTION
    // Node* display_node = node1;
    // while (display_node != NULL){
    //     cout << display_node -> name << endl;
    //     display_node = display_node ->next;
    // };

    // cout<<endl;

    // //Backward DIRECTION
    // Node* back_node = node4;
    // while (back_node != NULL){
    //     cout << back_node -> name << endl;
    //     back_node = back_node ->prev;
    // };

};
