/*
Finding a cycle using floyd cycle algorithm. But finding point of intersection in interesting.

Let's say this is the cycle.

A -> B -> C -> D -> E -> F
               |         |
               |         |
                <-  H <- G
Here, let's say the they met at G.

consider A -> D distance as X.
D -> G distance as y
G -> D distance as z

So, slow pointer travelled x+y while fast pointer travelled x+y+z+y = (x+2y+z) distance.

As time is constant, 2(x+y) = (x+2y+z) ===> x = z

So, if a new pointer starts at head and slow pointer from it's position, they both reach the cycle point in linkedlist.
*/

ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *fast = A, *slow = A;
    ListNode *res = A;
    ListNode *vid = NULL;
    while(fast != NULL) {
//        cout << fast -> val << "  " << slow -> val << endl;
        fast = fast -> next;
        if(slow -> next != NULL) slow = slow -> next;
        else break;
        if(slow -> next != NULL) slow = slow -> next;
        else break;
        if(fast == slow) break;
    }
    if(fast == NULL || slow -> next == NULL) return vid;
    else {
        while(fast != res) {
            fast = fast -> next;
            res = res -> next;
        }
        return res;
    }
}
