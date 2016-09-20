Node* swapNodes(Node* node) { 
    Node* temp = node->next->next;
    Node* temp2 = node->next;
    node->next->next = node;
    node->next = temp;
    return temp2;
}

Node* reversePairWise(Node* node) {
    Node* curr = node;
    if(!curr)
        return node;
    Node* head = node;
    Node* prev = NULL;
    int count = 0;
    while (true) { 
        if(!curr->next) 
            return head;
        else {
            temp = swapNodes(curr);
            if(!count)
                head = temp;
            if(prev) 
                prev->next = temp;
            curr = temp->next->next;
            prev = temp->next;
            count++;
        }
    }
}
