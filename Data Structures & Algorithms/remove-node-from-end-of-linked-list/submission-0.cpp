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
        //The idea is to use two pointer approach
        //where the right pointer is ahead n times from head.
        //once it is done, we need to think of pointers sequentially
        ListNode * dummy = new ListNode(0, head);
        ListNode *first = dummy;
        ListNode *second = head;

        while( n > 0){
            second = second->next;
            n--;
        }

        while(second != NULL){
            first = first->next;
            second = second->next;
        }

        first->next = first->next->next;
        return dummy->next;

        
    }
};
