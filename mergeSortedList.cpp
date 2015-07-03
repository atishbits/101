/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(headA==nullptr && headB == nullptr)
        return nullptr;
    if(headA == nullptr)
        return headB;
    if(headB==nullptr)
        return headA;
   
    Node *me, *other, *ret, *temp;
    if(headA->data <= headB->data) {
        me = ret = headA;
        other = headB;
    }
    else {
        me = ret = headB;
        other = headA;        
    }
    while(1) {
        if(me->next == nullptr) {
            me->next = other;
            return ret;
        }
        if(me->next->data <= other->data) {
            me = me->next;
        }
        else {
            temp = me->next;
            me->next = other;
            me = me -> next;
            other = temp;
        }
    }
    return ret;
}
