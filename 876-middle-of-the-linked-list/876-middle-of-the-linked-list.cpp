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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* t=head,*mid=head;
        while(t){
            t=t->next;
            if(t){
               mid=mid->next;
                t=t->next;
            }
        }
        return mid;
    }
};