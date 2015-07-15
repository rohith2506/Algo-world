/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
            if(head == NULL) return NULL;
            RandomListNode *hh = new RandomListNode(head->label);
            RandomListNode *cur = head;
            RandomListNode *ret = hh;
            unordered_map<RandomListNode *, RandomListNode *> pmap;
            pmap[cur] = hh;
            while(cur -> next){
                cur = cur -> next;
                hh -> next = new RandomListNode(cur->label);
                hh = hh -> next;
                pmap[cur] = hh;
            }
            
            cur = head;
            while(cur){
                if(pmap.count(cur)){
                    hh = pmap[cur];
                    if(cur -> random && pmap.count(cur -> random)){
                        hh -> random = pmap[cur -> random];
                    }
                }
                cur = cur -> next;
            }
            return ret;
    }
};