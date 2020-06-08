/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time complexity: O(1)
// Space complexity: O(1) (no memory leak)

/* The idea is, instead of deleting node (actually we cannot because we need a ptr to the previous of it but we don't have one), we will delete the next node, but first get the value of the next node and make the next of the current node point to next of next node, then delete the next node
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
	// put the data of next node in the current node
        node->val = node->next->val;
	// store the address of the next node in order to delete it later
        ListNode *temp = node->next;
	// make the next of current node point to the next of the next node
        node->next = node->next->next;
	// prevent memory leak by deleting the next node
        delete temp;
    }
};
