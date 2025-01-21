class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)   return head;
        // Create a dummy node and point its next to head
        ListNode* dummy = new ListNode();  
        dummy->next = head;
        
        // Initialize the tail pointer to the dummy node
        ListNode* tail = dummy;
        
        
        while (tail->next != nullptr) {
            if (tail->next->val == val) {
                // If the value matches, delete the node
                ListNode* ptr = tail->next;
                tail->next = ptr->next; 
                delete ptr;  // Free the memory
            } else {
                tail = tail->next;
            }
        }
        
        // Return the updated list, starting from dummy's next node
        head = dummy->next;
        
        // Cleanup the dummy node
        delete dummy;
        
        return head;
    }
};
