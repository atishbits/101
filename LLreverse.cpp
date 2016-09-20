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
Node* Reverse(Node *head)
{
    Node* prev = NULL;
    Node* cur = head;
    Node* temp;
    while(true) {
        if (!cur)
            return head;
        if(cur->next) {
            head = cur->next;
        }
        else {
            head = cur;
            cur->next = prev;
            return head;
        }
        temp = cur->next->next;
        cur->next->next = cur;
        cur->next = prev;
        cur = temp;
        prev = head;
    }
}


