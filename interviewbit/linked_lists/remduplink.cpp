#include <iostream>
using namespace std;

class Solution {
	private:
		struct ListNode {
			int val;
			ListNode *next;
			ListNode(int x): val(x), next(NULL) {}
		};

	public:
		ListNode* Solution::deleteDuplicates(ListNode *A) {
			if(A -> next == NULL) return A;
			ListNode *cur = A -> next, *prev = A;
			while(cur -> next != NULL) {
				if(cur -> val == prev -> val) {
					prev -> next = cur -> next;
					cur = cur -> next;
				}
				else {
					prev = prev -> next;
					cur = cur -> next;
				}
			}
			return A;
		}
};
