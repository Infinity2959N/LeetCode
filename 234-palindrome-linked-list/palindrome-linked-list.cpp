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
    bool isPalindrome(ListNode* head) {
        // Using stack: Reach mid while storing all the values inside a stack till mid point.
        // Now iterate from mid till end and compare with the top of stack
        ListNode* fast= head, *slow=head;
        stack<int> st;
        while(fast && fast->next){
            st.push(slow->val);
            slow=slow->next;
            fast= fast->next->next;
        }
        if(fast) slow=slow->next;    // Slow moves only in case of odd-length. For even length fast will be at null, for odd it will be at last node.
        while(slow){
            if(slow->val!= st.top())  return false;
            st.pop();
            slow=slow->next;
        }
        return true;
    }
};