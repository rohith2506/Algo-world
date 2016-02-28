ListNode* Solution::mergeKLists(vector<ListNode* > &A) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<A.size(); i++) {
        if(A[i] != NULL) {
            pq.push(A[i]-> val);
            A[i] = A[i] -> next;
        }
    }
    ListNode *cur = NULL,  *res;
    while(!pq.empty()) {
        int value = pq.top();
        pq.pop();
        if(cur == NULL) {
            ListNode *cur = new ListNode(value);
            cur -> next = NULL;
            res = cur;
        }
        else {
            ListNode *r = new ListNode(value);
            r -> next = NULL;
            cur -> next = r;
            cur = r;
        }
        for(int i=0; i<A.size(); i++) {
            if(A[i] != NULL) {
                pq.push(A[i] -> val);
                A[i] = A[i] -> next;
            }
        }
    }
    return res;
}
