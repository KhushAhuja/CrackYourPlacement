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
    int getDecimalValue(ListNode* head) {
        ListNode* head2=head;
        int count=0;
        while(head->next!=nullptr){
            count++;
            head=head->next;
        }
        int i=0;
        int decVal=0;
        while(head2!=nullptr){
            if(head2->val==1){
                decVal+=pow(2,(count-i));
            }
            head2=head2->next;
            i++;
        }
        return decVal;
    }
};