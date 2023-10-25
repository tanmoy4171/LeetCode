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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // support variables
        ListNode *originalHeadA = headA,  *originalHeadB = headB;
        // turtle headA vs hare headB
        while (headA || headB) {
            // checking if a match is found
            if (headA == headB) return headB;
            // resetting or advancing A and B as needed
            if (!headA) headA = originalHeadB;
            else headA = headA->next;
            if (!headB) headB = originalHeadA;
            else headB = headB->next;
        }
        return headB;
    }
};