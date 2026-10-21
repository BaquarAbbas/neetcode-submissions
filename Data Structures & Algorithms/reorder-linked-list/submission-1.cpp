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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
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
        //Idea is to use find a middle node and divide the list into two halves
        //utilize slow and fast pointer + reverse second list node and update pointers
        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head, * fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* list2 = slow->next;
        slow->next = NULL;
        ListNode* list3 = reverse(list2);
        ListNode* first = head;

        while(list3 != NULL){
            ListNode* nxtL3 = list3->next;
            ListNode* nxtFirst = first->next;

            first->next = list3;
            list3->next = nxtFirst;

            list3 = nxtL3;
            first = nxtFirst;
        }
        
    }
};
