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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }


        int mid = count / 2;
        ListNode* start = head;
        ListNode* end = head;
        ListNode* prev;
        for (int i = 0; i < mid; i++) {
            prev = end;
            end = end->next;
        }
        prev -> next = nullptr;
    
        end = reverseList(end);

        ListNode dummy(0);
        ListNode* node = &dummy;
        ListNode* first = start;

        for (int i = 0; i < mid; i++) {
            node->next = first;
            first = first->next;
            node = node->next;

            node->next = end;
            end = end->next;
            node = node->next;
        }

        if (first != nullptr) {
            node->next = first;
        }
        if (end != nullptr) {
            node->next = end;
        }

        head = dummy.next;
    }
};
