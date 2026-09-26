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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 != NULL)
         return list2;

        if(list2 == NULL && list1 != NULL)
         return list1;

        if (list1 == NULL && list2 == NULL)
         return NULL;

        ListNode* dummy = (list1->val <= list2->val) ? list1 : list2;


        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                while(list1->next != NULL && list1->next->val <= list2->val){
                    list1 = list1->next;
                }
                ListNode* nxt = list1->next;
                list1->next = list2;
                list1 = nxt;
            }
            else{
                while(list2->next != NULL && list2->next->val <= list1->val){
                    list2 = list2->next;
                }
                ListNode* nxt = list2->next;
                list2->next = list1;
                list2 = nxt;
            }
        }
        return dummy;
    }
};
