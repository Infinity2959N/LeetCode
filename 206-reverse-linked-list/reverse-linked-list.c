/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    //recursively
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    // Reverse the rest of the list
    struct ListNode* revHead = reverseList(head->next);
    
    // Make the current head the last node
    head->next->next = head;
    
    // Update the next of current head to NULL
    head->next = NULL;
    
    // Return the new head of the reversed list
    return revHead;
}