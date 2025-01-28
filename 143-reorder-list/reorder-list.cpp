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
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)    return;
        //part 1: find middle and divide the lists
        ListNode *slow=head, *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *second= slow->next;
        slow->next=nullptr;

        //part 2: merge the lists:
        //1. reverse the second list: 
        ListNode *prev=nullptr, *curr=second, *next=nullptr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        second=prev;
        //2. merge the lists
        ListNode *first=head, *temp1=nullptr, *temp2=nullptr;
        while(first && second){
            temp1=first->next;
            temp2=second->next;

            first->next=second;
            second->next=temp1;

            first=temp1;
            second=temp2;
        }


    }
};