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
    ListNode* swapNodes(ListNode* head, int k) {
        if(k<=0) return head;
        // List is 1 indexed
        ListNode* kth= head;
        for(int i=1; i<k; i++){
            kth= kth->next;
        }
        int val1= kth->val;
        ListNode* temp= kth;
        ListNode* kthback= head;
        while(temp && temp->next){
            temp= temp->next;
            kthback= kthback->next;
        }
        int val2= kthback->val;
        kth->val= val2;
        kthback->val= val1;

        return head;
    }
};