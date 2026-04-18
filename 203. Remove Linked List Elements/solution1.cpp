/**
 * Definition for singly-linked list->
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        if (head->val == val) {
            if (head->next == NULL)
                return NULL;
            else {
                while(head != NULL && head->val == val) head = head->next;
            }
        }
        if (head == NULL)
            return NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            if (temp->val == val) {
                while (temp != NULL && temp->val == val)
                    temp = temp->next;
                if (prev != NULL) {
                    prev->next = temp;
                    temp = prev->next;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return prev ? head : prev;
    }
};