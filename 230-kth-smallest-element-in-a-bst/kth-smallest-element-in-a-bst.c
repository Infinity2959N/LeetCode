/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

// Stack Operations
void push(struct StackNode** top, struct TreeNode* node) {
    struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
    new_node->node = node;
    new_node->next = *top;
    *top = new_node;
}

struct TreeNode* pop(struct StackNode** top) {
    if (*top == NULL) return NULL;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    struct TreeNode* popped_node = temp->node;
    free(temp);
    return popped_node;
}

int kthSmallest(struct TreeNode* root, int k) {
    
    struct StackNode* stack = NULL;
    struct TreeNode* current = root;
    
    // Traverse the tree iteratively using the stack
    while (current != NULL || stack != NULL) {
        // Go to the leftmost node
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        
        // Pop the top element from the stack (this is the next smallest element)
        current = pop(&stack);
        
        // Decrement k, if k becomes 0, we've found the kth smallest
        k--;
        if (k == 0) {
            return current->val;
        }
        
        // Move to the right subtree
        current = current->right;
    }
    
    return -1; 
}