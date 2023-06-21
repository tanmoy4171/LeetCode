/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *prev = NULL, *head = l1;
        int carry = 0;
        
        while(l1 || l2 || carry){
            int val1 = (l1 ? l1 -> val : 0);
            int val2 = (l2 ? l2 -> val : 0);
            
            if(!l1){
                l1 = new ListNode(0);
                prev -> next = l1;
                l1 -> val = (val1 + val2 + carry) % 10;
            }
            else
                l1 -> val = (val1 + val2 + carry) % 10;
            
            if((val1 + val2 + carry) > 9)
                carry = 1;
            else
                carry = 0;
            
            prev = l1;
            l1 = l1 -> next;
            l2 = (l2 ? l2 -> next : NULL);
        }
        
        return head;
    }
};