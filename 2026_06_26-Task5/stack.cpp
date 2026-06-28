

#include <iostream>
using namespace std;


class Stack{
    public:
    string name;
    Stack* next = NULL;
    Stack* top = NULL;

    //push
    void push(string name){
        Stack* newnode = new Stack();
        newnode -> name = name;
        newnode ->next = top;
        top = newnode;
    }

    //pop
    void pop(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return;
        }
        Stack* temp = top;
        top = top->next;
        delete temp;
    }

    //peek
    void peek(){
        if(top == NULL){
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << top->name << endl;
    }
    
    
    void display(){
        Stack* display_node = top;
        while(display_node != nullptr){
            cout << display_node->name << endl; // 0x251732e2
            display_node = display_node->next; //  0x251732e3
        }
    }
};

int main(){

    Stack* stack = new Stack();
    stack -> push("Ali");
    stack -> push("Liyana");
    stack -> push("zed");
    stack -> push("Rach");
    
    
    stack-> pop();
    stack-> peek();
    stack->display();
    
    // Stack* node1 = new Stack();
    // Stack* node2 = new Stack();
    // Stack* node3 = new Stack();
    // Stack* node4 = new Stack();

    // node1->name = "Liyana";
    // node1->next = top;
    // top = node1;

    // node2->name = "Ahmad";
    // node2->next = top;
    // top = node2;
    

    // node3->name = "Sarah";
    // node3->next = top;
    // top = node3;

    // node4->name = "Omar";
    // node4->next = top;
    // top = node4;


    // Stack* display_node = top;
    // while(display_node != nullptr){
    
    //     cout << display_node->name << endl; // 0x251732e2
    //     display_node = display_node->next; //  0x251732e3
    // }
    
    return 0;
};