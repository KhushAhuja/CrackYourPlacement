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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode* dummy=new ListNode(INT_MAX);
        while(head->next!=nullptr and head->next!=dummy){
            ListNode* node=head->next;
            head->next=dummy;
            head=node;
        }
        if(head->next==dummy) return true;
        else return false;
    }
};