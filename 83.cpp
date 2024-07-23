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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* prev=head;
        ListNode* ans=prev;
        head=head->next;
        while(head!=nullptr){
            if(prev->val!=head->val){
                prev->next=head;
                prev=prev->next;
            } 
            head=head->next;
        }
        prev->next=nullptr;
        return ans;
    }
};