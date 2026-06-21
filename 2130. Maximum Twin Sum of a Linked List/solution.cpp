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
    // Space Complexity: O(n)
    // Approach: We can use the slow and fast pointer technique to find the middle of the linked list. 
    // Then, we can calculate the sum of each pair of nodes and keep track of the maximum sum.


    int pairSum(ListNode* head) {
        vector<int> sumArr;
        int n = 0;
        int maxValue = 0;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL and fast->next != NULL){
            sumArr.push_back(slow->val);
            n += 1;
            slow = slow->next;
            fast = fast->next->next;
        }

        while(slow != NULL){
            sumArr[n-1] += slow->val;
            maxValue = max(maxValue, sumArr[n-1]);
            n -= 1;
            slow = slow->next; 
        }

        return maxValue;
    }
};