/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function       
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode l3 (-1);
        
        int carry = 0;
        
        while(l1!=NULL && l2!=NULL){
            
            int sum = (l1->val) + (l2->val) + carry;
            
            sum = sum%10;
            
            l3.insert(sum);
            
            carry = carry + sum/10;
            
        }
        
        
        while(l1!=NULL){
            
            int sum = l1->val + carry;
            
            sum = sum % 10;
            
            l3.insert(sum);
            
            carry = carry + sum/10;
        }
        
        
         while(l2!=NULL){
            
            int sum = l2->val + carry;
            
            sum = sum % 10;
            
            l3.insert(sum);
            
            carry = carry + sum/10;
        }
        
        ListNode * rl;
        
        l4 = reverse(rl);
        
        return l4;
        
    }
    
    ListNode * reverse(ListNode *p){
        
       ListNode * prev = NULL;
       ListNode * curr = p;
       ListNode * next;
       
        
        while(curr != NULL){
            
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            
        }
        
        return prev;
    }
    
    
    
    void insert(int x){
        
        if(head == NULL){
            head = new ListNode;
            head -> val = x;
            head -> next = NULL;
        }
        
        else{
            
            ListNode * temp = head ;
            
            while ( temp -> next != NULL)
                temp = temp -> next;
                
            ListNode * r = new ListNode;
            
            r -> val = x;
            
            temp -> next = r;
            
            r -> next = NULL;   
        }        
    }
    
    
};
