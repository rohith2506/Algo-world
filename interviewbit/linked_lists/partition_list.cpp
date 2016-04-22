/*
The catch is instead of adding elements to the front which are lesser,
we can add elements which are greater at the end. In both cases, you 
will get the same result.
*/

ListNode* Solution::partition(ListNode* head, int B) {
    ListNode *p = new ListNode(0);
    p -> next = head;
    head = p;
    ListNode *last = head;
    if(head == NULL) return head;
    else if(head -> next == NULL) return head -> next;
    int n = 0;
    while(last -> next != NULL) { last = last -> next; n++; }
    while(n > 0) {
        if(p -> next -> val < B) {
            p = p -> next;
            n--;
        }
        else {
            last -> next = new ListNode(p -> next -> val);
            last = last -> next;
            p -> next = p -> next -> next;
            n--;
        }
    }
    return head -> next;
}
