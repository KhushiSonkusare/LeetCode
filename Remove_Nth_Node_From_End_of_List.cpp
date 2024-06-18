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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int i = 0;
        
      
        while (temp != nullptr) {
            i++;
            temp = temp->next;
        }
     
        if (i == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
     
        temp = head;
        for (int j = 1; j < i - n; j++) {
            temp = temp->next;
        }
     
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        
        return head;
    }
};
