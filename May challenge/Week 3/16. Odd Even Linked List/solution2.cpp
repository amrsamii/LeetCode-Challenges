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
    
    
ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* current = head;
        ListNode* leader = head->next;
        ListNode* evenhead = head->next;
        // extract the two lists, even and odd, stepwise.
        while(leader) {
            current->next = leader->next;
            current = leader;
            leader = leader->next;
        }
        // go back to the front of the list, which will be the odd head.
        current = head;
        // iterate to the end of the odd list,
        while(current->next) {
            current = current->next;
        }
        // point the end of the odd list to the beginning of the even list,
        current->next = evenhead;
        // which should be null terminated weither node count is even or odd.
        return head;
    }};
