#include<iostream>
using namespace std;

class Node {
    // node that has an integer value and a pointer to the next node
    public:
    int data;
    Node* next;
    Node (int data_from_outside) {
        this->data = data_from_outside;
        this->next = NULL;
    }
};
static int ll_length = 0;
static Node* ll = NULL; // create an ll that stores elements of type of, but the pointer is currently poiting to NULL


void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer

    // I would need the length of the ll -> this will let me know how  many times I should keep on going next
    // for this I can use a static variable
    
    Node* newNode = new Node(value); // this creates a new node in the memory to which our "newNode" pointer points
    if(ll_length == 0) {
        // it means that linked list is empty
        // so you can add a new node, but only if the position is 1
        if( position == 1 ) {
            ll = newNode;
            ll_length++;
        } else {
            return;
        }
    } else if ( position > ll_length+1 || position == 0 ){
        return;
    } else {
        // you can insert at given position
        int allowedTraversal = position - 1; // to insert at ith position you need to go till i-1th position and begin your insertion
        Node* current = ll;
        if( allowedTraversal == ll_length ) { // this means you will be adding the new element at the end
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            ll_length++;
            return;
        } else {
            while(allowedTraversal >= 1) {
                current = current->next;
                allowedTraversal--;
            }
            newNode->next = current->next;
            current->next = newNode;
            ll_length++;

        }
        
    }



}

void delete_node(int position) {
    // @params position, integer
}


void print_ll() {
    // Output each element followed by a space
    Node* current = ll;
    while(current != NULL) {
        cout << current->data;
        current = current->next;
    }
}

int main() {
    insert_node(1, 23);
    insert_node(2, 28);
    print_ll();
    return 0;
}