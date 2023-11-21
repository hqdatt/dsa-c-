#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList{
public:
    void insertAtHead(Node** head_ref, int data){
        Node* newNode = new Node(data);
        newNode->next = *head_ref;
        *head_ref = newNode;
    }

    void insertAtTail(Node** head_ref, int data){
        Node* newNode = new Node(data);
        if(*head_ref==NULL){
            *head_ref = newNode;
        }
        else{
            Node* temp = *head_ref;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertSpecific(Node** head_ref, int data, int index){
        Node* newNode = new Node(data);
        if(index==0){
            newNode->next = *head_ref;
            *head_ref = newNode;
            return;
        }
        Node* current = *head_ref;
        for(int i=0; i < index - 1 && current != NULL; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteAtHead(Node** head_ref){
        if(*head_ref==NULL){
            cout << "The list is empty. " << endl;
            return;
        }
        Node* current = *head_ref;
        *head_ref = (*head_ref)->next;
        delete current;
        current = NULL;
    }

    void deleteAtTail(Node** head_ref){
        if(*head_ref==NULL){
            cout << "The list is empty. " << endl;
            return;
        }
        if((*head_ref)->next==NULL){
            delete *head_ref;
            *head_ref = NULL;
            return;
        }
        Node* current = *head_ref;
        while(current->next->next!=NULL){
            current = current->next;
        }
        delete current->next;
        current->next = NULL;
    }

    void deleteAtSpecific(Node** head_ref, int index){
        if(*head_ref==NULL){
            cout << "The list is empty. " << endl;
            return;
        }
        if(index==1){ 
            Node* temp = *head_ref;
            *head_ref = (*head_ref)->next;
            delete temp;
            temp = NULL;
            return;
        }
        Node* prev = *head_ref;
        for(int i=0; i < index - 1 && prev != NULL; i++){
            prev = prev->next;
        }
        Node* current = prev->next;
        prev->next = current->next;
        delete current;
        current = NULL;
    }

    void print(Node* head){
        if(head==NULL){
            return;
        }
        while(head!=NULL){
            cout << head->data << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    void reversePrint(Node* head) {
        if (head == nullptr) {
            std::cout  <<  "NULL";
            return;
        }
        reversePrint(head->next);
        std::cout  <<  "<-"  <<  head->data;
    }

    void reverseLL(Node** head_ref, Node* current) {
        if (current->next == NULL) {
            *head_ref = current;
            return;
        }
        reverseLL(head_ref, current->next);
        Node* temp = current->next;
        temp->next = current;
        current->next = NULL;
    }

    int getLen(Node* head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    // recursive method
    // int getLen(Node* head, int count = 0){
    //     if(head==NULL){return count;}
    //     return getLen(head->next, count + 1)
    // }

    void printMiddle(Node* head){
        int len = getLen(head);
        int midIdx = len/2;
        for(int j = 0; j<midIdx; j++){
            head = head->next;
        }
        cout << "Middle Value Of Linked List is: " << head->data << endl;
    }

    void PrintSpecific(Node* head, int index){
        for(int j = 0; j<index; j++){
            head = head->next;
        }
        cout << index << "th Value Of Linked List is: " << head->data << endl;
    }

    void deleteList(Node* head){
        Node* prev = head;
        Node* current = head;
        while(current){
            prev = current;
            current = current->next;
            delete prev;
        }
        cout << "Linked list deleted" << endl;
    }
    
    void searchElement(Node* head, int key, int position = 0){
        if(head){
            if(head->data==key){
                cout << key << " is at " << position <<  "th position" << endl;
                return;
            } else {
                searchElement(head->next, key, position + 1);
            }
        } else {
            cout << "There is no " << key << " element in the linked list" << endl;
        }
    }

    void countElement(Node* head, int key, int count = 0){
        if(head){
            if(head->data==key){
                countElement(head->next, key, count + 1);
            } else {
                countElement(head->next, key, count);
            }
        } else {
            cout << "Frequency of " << key << ": " << count <<endl;
        }
    }
};

int main(){
    Node* head = NULL;
    LinkedList* itemList = new LinkedList();

    itemList->insertAtHead(&head, 8);
    itemList->insertAtHead(&head, 4);
    itemList->insertAtTail(&head, 9);
    itemList->insertAtHead(&head, 3);
    itemList->insertSpecific(&head, 7, 1);
    itemList->insertSpecific(&head, 4, 4);
    itemList->print(head);
    itemList->searchElement(head, 8);
    itemList->countElement(head, 4);

    delete itemList;
    return 0;
}