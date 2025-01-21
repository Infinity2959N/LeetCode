/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {  //using the tortoise hare algo
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast!=NULL && fast->next != NULL){            
        fast = fast->next->next; //2 times
        slow = slow->next; //1 time
        if(fast == slow) return true;
    }
    return false;
}