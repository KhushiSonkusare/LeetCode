class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        if (fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* node = slow->next;
        slow->next = node->next;
        delete node;
        
        return head;
    }
};
