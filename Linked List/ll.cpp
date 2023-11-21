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
    void InsertAtHead(Node** head_ref, int data){
        Node* newNode = new Node(data);
        newNode->next = *head_ref;
        *head_ref = newNode;
    }

    void InsertAtTail(Node** head_ref, int data){
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

    void InsertSpecific(Node** head_ref, int data, int index){
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

    void DeleteAtHead(Node** head_ref){
        if(*head_ref==NULL){
            cout<<"The list is empty. "<<endl;
            return;
        }
        Node* current = *head_ref;
        *head_ref = (*head_ref)->next;
        delete current;
        current = NULL;
    }

    void DeleteAtTail(Node** head_ref){
        if(*head_ref==NULL){
            cout<<"The list is empty. "<<endl;
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

    void DeleteAtSpecific(Node** head_ref, int index){
        if(*head_ref==NULL){
            cout<<"The list is empty. "<<endl;
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

    void Print(Node* head){
        if(head==NULL){
            return;
        }
        while(head!=NULL){
            cout<<head->data<<"->";
            head = head->next;
        }
        cout<<"NULL"<<endl;
    }

    void ReversePrint(Node* head) {
        if (head == nullptr) {
            std::cout << "NULL";
            return;
        }
        ReversePrint(head->next);
        std::cout << "<-" << head->data;
    }

    void ReverseLL(Node** head_ref, Node* current) {
        if (current->next == NULL) {
            *head_ref = current;
            return;
        }
        ReverseLL(head_ref, current->next);
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

    void PrintMiddle(Node* head){
        int len = getLen(head);
        int midIdx = len/2;
        for(int j = 0; j<midIdx; j++){
            head = head->next;
        }
        cout<<"Middle Value Of Linked List is: "<<head->data<<endl;
    }

    void PrintSpecific(Node* head, int index){
        for(int j = 0; j<index; j++){
            head = head->next;
        }
        cout<<index<<"th Value Of Linked List is: "<<head->data<<endl;
    }

    void DeleteList(Node* head){
        Node* prev = head;
        Node* current = head;
        while(current){
            prev = current;
            current = current->next;
            delete prev;
        }
        cout<<"Linked list deleted"<<endl;
    }

};

int main(){
    Node* head = NULL;
    LinkedList* itemList = new LinkedList();

    itemList->InsertAtHead(&head, 8);
    itemList->InsertAtHead(&head, 4);
    itemList->InsertAtTail(&head, 9);
    itemList->InsertAtHead(&head, 3);
    itemList->InsertSpecific(&head, 7, 1);
    itemList->Print(head);
    itemList->ReversePrint(head);

    delete itemList;
    return 0;
}