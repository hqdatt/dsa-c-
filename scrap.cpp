    void countElement(Node* head, int key){
        int frequency = 0;
        while(head){
            if(head->data==key){
                frequency++;
            }
            head = head->next;
        }
        cout<< "Frequency of " << key << ": " << frequency <<endl;
    }