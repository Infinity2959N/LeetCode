/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to help simplify merging
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;  // Initialize the dummy node
    
    // Iterate until one list is fully traversed
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    // Attach the remaining part of the list that is not fully traversed
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }
    
    // Return the merged list starting from dummy.next
    return dummy.next;
}