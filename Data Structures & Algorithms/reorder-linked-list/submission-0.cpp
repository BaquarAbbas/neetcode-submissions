/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode()
 : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr  = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l2 = slow->next;
        slow->next = NULL;
        ListNode *l3 = reverse(l2);

        ListNode* first = head;

        while(l3 != NULL){
            ListNode* nxt1 = first->next;
            ListNode* nxt2 = l3->next;

            first->next = l3;
            l3->next = nxt1;

            first = nxt1;
            l3 = nxt2;
        }
    }
};