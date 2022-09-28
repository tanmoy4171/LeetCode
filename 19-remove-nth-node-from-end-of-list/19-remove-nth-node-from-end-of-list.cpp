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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int counter = 1;
        
        while(prev->next != nullptr)
        {
            prev = prev->next;
            counter++;
        }
        
        prev = head;
        
       if(counter == 1 || counter == n)
        {
            prev = nullptr;
            return curr; 
        }
		
        for(int i = 0; i < counter - n - 1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        
        return head;
    }
};