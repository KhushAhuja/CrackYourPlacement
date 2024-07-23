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
    ListNode* middleNode(ListNode* head) {
        ListNode* midPointer=head;
        int count=0;
        while(midPointer!=nullptr){
            count++;
            midPointer=midPointer->next;
        }
        count+=2;
        count/=2;
        while(count>1){
            head=head->next;
            count--;
        }
        return head;
    }
};