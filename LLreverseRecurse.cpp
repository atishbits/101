/*
https://www.hackerrank.com/challenges/reverse-a-linked-list?h_r=internal-search
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* ReverseUtil(Node* prev, Node* cur, Node* head) {
    if(!cur)
        return head;
    if(!cur->next) {
        head = cur;
        cur->next = prev;
        return head;
    }
    Node* temp;
    head = cur->next;
    temp = cur->next->next;
    cur->next->next = cur;
    cur->next = prev;
    cur = temp;
    prev = head;
    
    return ReverseUtil(prev, cur, head);
}

Node* Reverse(Node *head)
{
    Node* prev = NULL;
    Node* cur = head;
    return ReverseUtil(prev, cur, head);
}


