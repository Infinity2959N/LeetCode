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
        // Easy O(n) space solution: traverse one list, put them all in a hash set
        // Solution 2: Traverse both, find their length, move pointer for longer list forward to be wqual to distance of smaller pointer, then move both together
        // Best Solution: Two pointer technique: Move pointers from both the lists, when one pointer reaches the end of the list, it switches to head of the other list: Two pointers eventually meet the intersection, if no intersection, they reach null at the same time
        ListNode *pA= headA, *pB= headB;
        while(pA!=pB){
            (pA)? pA= pA->next: pA=headB;
            (pB)? pB= pB->next: pB=headA;
        }
        return pA;
    }
};