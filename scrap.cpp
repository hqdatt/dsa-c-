#include <iostream>

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a new node at the beginning of a circular linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* new_node = new Node(data);
    
    if (!head) {
        // If the list is empty, make the new node the only node.
        new_node->next = new_node;
    } else {
        // Find the last node and update its next pointer.
        Node* last_node = head;
        while (last_node->next != head) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        
        // Make the new node point to the current head.
        new_node->next = head;
    }
    
    // Update the head pointer.
    head = new_node;

    return head;
}

// Function to display a circular linked list
void displayList(Node* head) {
    if (!head) {
        std::cout << "Empty List";
        return;
    }

    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    std::cout << std::endl;
}

int main() {
    // Example Usage:
    Node* head = nullptr;

    // Inserting elements at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Displaying the circular linked list
    std::cout << "Circular Linked List: ";
    displayList(head);

    return 0;
}
