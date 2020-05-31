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
        // if [1], head->next is null so no worry, we also will not enter while loop because currentEven will be nullptr
	// and currentOdd->next = evenHead which is the same as the given list, nothing changed, and so for [1,2]
        if(head == nullptr)
            return head;
        
        
        ListNode* evenHead = head->next;
        ListNode* currentOdd = head;
        ListNode* currentEven = evenHead;
        
	// [1,2,3,4,5] after last iteration we want, currentEven will be null and currentOdd 
        // will be 5 so we should check that currentEven != nullptr

	// [1,2,3,4] after last iteration, currentEven will be 4 and currentOdd will be 3, currentOdd is on the last odd so okay
	// currentEven has its next as null so it is the end of the list so it is correct, but we must stop new iteration, so we should
	// check that its next is not null to enter the loop
        while(currentEven != nullptr && currentEven->next != nullptr) {
            currentOdd->next = currentEven->next;
            currentOdd = currentOdd->next;
            
            currentEven->next = currentOdd->next;
            currentEven = currentEven->next;
        }
       
	// since currentOdd will always have the last odd in the last iteratio because it always jump to odd indecies and we stop it
	// from being null, we can make its next to be the first even 
        currentOdd->next = evenHead;
        
        return head;
    }
};
