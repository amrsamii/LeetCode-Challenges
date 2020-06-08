/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* This solution will cause memory leak since we didn't delete the next node, but it's a good trick to know, it works because *node will deference node ptr and access its content which is ListNode structure, we equal this structure object with the structure object of the next node, this means that the val of node will be equal val of next node, and next of node will be equal next of next node which means the next node will not be reached anymore but its content is inside node so we can say we delete the node, but the memory leak happend because we didn't delete the next node
*/
class Solution {
public:
    void deleteNode(ListNode* node) {     
        *node = *(node->next);
    }
};
