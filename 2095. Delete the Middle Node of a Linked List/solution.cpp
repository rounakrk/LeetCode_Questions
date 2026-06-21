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
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Approach: We can use the slow and fast pointer technique to find the middle node of the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end of the list, the slow pointer will be at the middle node. We can then delete the middle node by updating the next pointer of the previous node to skip the middle node.
    // If the linked list has an even number of nodes, we can delete the second middle node. If the linked list has only one node, we can return NULL.

    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if(slow==NULL || slow->next == NULL){
            if(prev) {
                prev->next = NULL;
                return prev;
            }
            return NULL;
        }else{
            prev->next = slow->next;
            slow->next = NULL;
        }

        return head;
    }
};