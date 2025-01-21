/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //two pointer approach, we start one from A, other from B
        //When a pointer reaches the end, we move it to the head of the other list
        //Stop when either pA=pB or both become null
        ListNode* pA=headA;
        ListNode* pB=headB;

        while(pA!=pB){
            pA=(pA==nullptr)? headB:pA->next;
            pB=(pB==nullptr)? headA:pB->next;
        }
        return pA;
    }
};