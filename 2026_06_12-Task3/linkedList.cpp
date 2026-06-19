#include <iostream>
using namespace std;


struct Node{
    string name;
    Node* next = nullptr;
};

int main(){
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();

    node1->name = "Liyana";
    node1->next = node2;

    node2->name = "Ahmad";
    node2->next = node3;

    node3->name = "Sarah";
    node3->next = node4;

    node4->name = "Omar";
    node4->next = nullptr;


    Node* display_node = node1;


    // // Create first node
    // Node* head = nullptr;
    // Node* tail = nullptr;

    // for (int i = 10; i <= 50 ; i +=10){
    //     Node* newNode = new Node;
    //     newNode->name = "liyana";
    //     newNode->next = nullptr;

    //     if (head == nullptr){
    //         head = newNode;
    //         tail = newNode;
    //     } else {
    //         tail->next = newNode; //(newNode)
    //         tail = newNode;
    //     }
    // }
}