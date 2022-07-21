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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto **pivot{&head->next}, **start{&head};

        for(; --right && --left; pivot = &(*(start = pivot))->next); 
        for(; right--; swap(*start, (*pivot)->next), swap(*start, *pivot)); 

        return head;
    }
};