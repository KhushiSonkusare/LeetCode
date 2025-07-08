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
    ListNode* removeElements(ListNode* head, int val) {
      
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
    
        if(curr == NULL){
            return head;
        }
     
        while(curr != NULL){
             if(curr->val == val){
               prev->next = curr->next;
               curr = curr->next;
             }
             else{
                curr = curr->next;
                prev = prev->next;
             }
           
        }
        head = dummy->next;
        delete dummy;

       return head;
    }
};